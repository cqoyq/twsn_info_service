/*
 * base.cpp
 *
 *  Created on: 2016-10-12
 *      Author: root
 */

#include "base.h"

#include "Package/package_factory.h"
using namespace Package;

#include "rb.h"

// Construct rabbitmq-message and send to destination.
void Handlers::send_rabbitmq_message(net_layer*& net, log_handler*& log, node*& js){
	// Make pack block.
	char tcp_pk[TCP_MESSAGE_MAX_SIZE];
	memset(tcp_pk, 0x00, TCP_MESSAGE_MAX_SIZE);
	char* p_tcp_pk = tcp_pk;
	size_t tcp_pk_size = 0;


	// Make response tcp-package.
	PACKAGE_FACTORY_TYPE::instance()->pack(net, js, p_tcp_pk, tcp_pk_size);

	// Make response rabbtmq-package.
	char rb_pk[RABBITMQ_MESSAGE_MAX_SIZE];
	memset(rb_pk, 0x00, RABBITMQ_MESSAGE_MAX_SIZE);
	char* p_rb_pk = rb_pk;
	size_t rb_pk_size = 0;
	make_rabbitmq_data_message(net, p_tcp_pk, tcp_pk_size, p_rb_pk, rb_pk_size);

	// Check rabbitmq-package
	if(rb_pk_size == 0){

		// Write Log
		if(log){
			string_append info;
			info.add("handle package fail! err_msg: get source_routingkey error, routingkey:")->add(net->req_addr.c_str());
			log->handle(LOG_LEVEL_ERROR, LOG_TAG_MESSAGE_HANDLER, info.to_string());
		}

		return;
	}else{
		// Write Log
		if(log){
			string_ex t;
			string_append info;
			info.add("handle package success! will send response-message, message:")
					->add(t.stream_to_string(p_rb_pk, rb_pk_size))
					->add(",req_addr:")
					->add(net->req_addr.c_str());
			log->handle(LOG_LEVEL_DEBUG, LOG_TAG_MESSAGE_HANDLER, info.to_string());
		}
	}
	// Send response rabbtmq-package to destination.
	RABBITMQ_FACTORY_TYPE::instance()->transfer_data_by_routingkey(net->req_addr, p_rb_pk, rb_pk_size);
}

