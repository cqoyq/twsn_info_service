/*
 * dbthr.cpp
 *
 *  Created on: 2016-10-2
 *      Author: root
 */

#include "db_thr.h"
#include "rb.h"

void top(twsn_db_data_message*& msg, twsn_db_task_data& task_data){
	net_layer* p_net = 0;

	node js;
	node* p_js = &js;

	char* p_data = msg->data.header();
	// Unpack message.
	if(task_data.pack_and_unpack.unpack(p_data, msg->data.length(), p_net, p_js)){
		// Store data.
		task_data.factory.doit(p_js);
	}
}

void make_db_task(){

	// Make db task.
	RB_DB_TASK::construct(
				top,					// thread_task queue top callback
				4						// 4 thread.
				);
}

void free_db_task(){

	RB_DB_TASK::release();
}

