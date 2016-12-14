/*
 * message_0x6A_0x01.cpp
 *
 *  Created on: 2016-10-18
 *      Author: root
 */

#include "message_0x6a_0x01.h"

using namespace Package;
using namespace Package::unpack;

void unpack_0x6A_0x01_message(char*& in_data, size_t& in_data_size, node*& data){
	char* app_header = in_data;

	// Get base stream.
	char* next = base_stream_to_node(app_header, data);

	// Get offline base module code.
	node* module_code = new node("module_code");
	char size[1] = {0x0e};
	if(memcmp(app_header + 1, size, 1 ) == 0){
		module_code->value = Package::u32_to_string(next);
	}

	data->child.push_back(module_code);
}

message_0x6A_0x01::message_0x6A_0x01(log_handler*& log) {
	// TODO Auto-generated constructor stub
	logger_= log;
}

message_0x6A_0x01::~message_0x6A_0x01() {
	// TODO Auto-generated destructor stub
}

int message_0x6A_0x01::handler(char*& in_data, size_t& in_data_size, net_layer*& in_net,  node*& data){
	bool is_to_next =false;
	string err;
	if(check_stream(in_data, in_data_size, is_to_next, err) == 0){

		// Unpack message.
		unpack_0x6A_0x01_message(in_data, in_data_size, data);

		// Write Log
		if(logger_){
			string_append info;
			info.add("unpack 0x6A_0x01 success!");
			logger_->handle(LOG_LEVEL_DEBUG, LOG_TAG_MESSAGE_UNPACK, info.to_string());
		}

		return 0;

	}else{

		if(!is_to_next){

			// Write Log
			if(logger_){
				string_append info;
				info.add("unpack 0x6A_0x01 package fail! err_msg:")->add(err.c_str());
				logger_->handle(LOG_LEVEL_ERROR, LOG_TAG_MESSAGE_UNPACK, info.to_string());
			}

			return 0;
		}else
			return -1;
	}
}

int message_0x6A_0x01::check_stream(char*& in_data, size_t& in_data_size, bool& is_to_next, string& err){
	char comp[2] = {0x6a, 0x01};
	if(memcmp(in_data, comp, 1) != 0 || memcmp(in_data + 6, comp + 1, 1) != 0){
		is_to_next = true;
		return -1;
	}
	return 0;
}
