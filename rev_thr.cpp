/*
 * revthr.cpp
 *
 *  Created on: 2016-9-28
 *      Author: root
 */

#include "rev_thr.h"
#include "rb.h"
#include "db_thr.h"

#include "Package/package_factory.h"
#include "Handlers/hdr_factory.h"

// Parse stream
void parse_to_net(char* header, net_layer*& net){
	char req_addr[1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE];
	memset(req_addr, 0x00, 1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE);
	memcpy(req_addr, header + 1, RABBITMQ_ROUTINGEKEY_MAX_SIZE);

	u64_t session = 0;
	memcpy(&session, header + 1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE, 8);

	net->req_addr = req_addr;
	net->session = session;
}

void top(twsn_rev_data_message*& msg, twsn_rev_task_data& task_data){

	string_ex t;
	LOCAL_LOG_VISITOR_TYPE::instance()->handle(
			LOG_LEVEL_DEBUG,
			LOG_TAG_REV_TASK,
			string_append().add("top data:")->add(t.stream_to_string(msg->data.header(), msg->data.length()))->to_string()
			);

	// Unpack message.
	net_layer net;
	net_layer* p_net = &net;

	node js;
	node* out_js = &js;

	char* p_msg = msg->data.header();

	// Unpack net-layer.
	parse_to_net(p_msg, p_net);

	// Unpack tcp-layer.
	char* in_app = p_msg + 1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE + 8;
	size_t in_app_size = msg->data.length() - 1 - RABBITMQ_ROUTINGEKEY_MAX_SIZE - 8;
	if(task_data.pack_and_unpack.unpack(in_app, in_app_size, p_net, out_js)){

		// Handle app-layer.
		if(!task_data.handler.doit(p_net, out_js))
			return;

		// Transfer data to db-thread.
		error_what e_what;
		twsn_db_data_message* data = new twsn_db_data_message();

		// Copy stream to twsn_db_data_message.
		if(data->data.copy(in_app, in_app_size, e_what) == -1){
			bingo::string_ex t;
			LOCAL_LOG_VISITOR_TYPE::instance()->handle(
					LOG_LEVEL_ERROR,
					LOG_TAG_REV_TASK,
					string_append().add("copy stream to RB_DB_TASK fail, err_code:")
					->add(e_what.err_no())
					->add(", err_msg:")
					->add(string(e_what.err_message()))
					->add(",data:")
					->add(t.stream_to_string(in_app, in_app_size))->to_string());

			delete data;
			return;
		}

		if(RB_DB_TASK::instance()->put(data, e_what) == -1){			// Input T into queue

			bingo::string_ex t;
			LOCAL_LOG_VISITOR_TYPE::instance()->handle(
								LOG_LEVEL_ERROR,
								LOG_TAG_REV_TASK,
								string_append().add("put message to RB_DB_TASK fail, err_code:")
								->add(e_what.err_no())
								->add(", err_msg:")
								->add(string(e_what.err_message()))
								->add(",data:")
								->add(t.stream_to_string(in_app, in_app_size))->to_string());
			delete data;
		}
	}
}

void make_rev_task(){

	// Make rev task.
	RB_RECEIVER_TASK::construct(
				top					// thread_task queue top callback
				);
}

void free_rev_task(){

	RB_RECEIVER_TASK::release();
}

