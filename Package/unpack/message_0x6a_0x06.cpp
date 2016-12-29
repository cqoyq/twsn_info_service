/*
 * message_0x6A_0x06.cpp
 *
 *  Created on: 2016-10-18
 *      Author: root
 */

#include "message_0x6a_0x06.h"

using namespace Package;
using namespace Package::unpack;

void unpack_0x6A_0x06_message(char*& in_data, size_t& in_data_size, node*& data){
	char* app_header = in_data;

	// Get base stream.
	char* next = base_stream_to_node(app_header, data);


	node* device_type = new node("device_type");
	node* first_module_code = new node("first_module_code");
	node* jump = new node("jump");
	node* strength = new node("strength");

	data->child.push_back(device_type);
	data->child.push_back(first_module_code);
	data->child.push_back(jump);
	data->child.push_back(strength);

	char size[1] = {0x0f};
	if(memcmp(app_header + 1, size, 1 ) == 0){
		// first module code.
		first_module_code->value = Package::u32_to_string(next);

		// jump
		jump->value = Package::u8_to_string(next + 4);

		// device type
		device_type->value = "1";
	}else {
		// strength
		strength->value = Package::u8_to_string(next);

		// device type
		device_type->value = "2";
	}

}

message_0x6A_0x06::message_0x6A_0x06(log_handler*& log) {
	// TODO Auto-generated constructor stub
	logger_= log;
}

message_0x6A_0x06::~message_0x6A_0x06() {
	// TODO Auto-generated destructor stub
}

int message_0x6A_0x06::handler(char*& in_data, size_t& in_data_size, net_layer*& in_net,  node*& data){
	bool is_to_next =false;
	string err;
	if(check_stream(in_data, in_data_size, is_to_next, err) == 0){

		// Unpack message.
		// -------- node structure  --------
		// {
		//		... base structure ...
		//		"device_type":""			       	// 入网设备类型, 0x01=基站, 0x02=无线终端
		//		"first_module_code":""       	// 第一转发MD模块编号
		//		"jump":""  		     				// 跳数
		//		"strength":""       					// 接收场强
		// }
		unpack_0x6A_0x06_message(in_data, in_data_size, data);

		// Write Log
		if(logger_){
			string_append info;
			info.add("unpack 0x6A_0x06 success!");
			logger_->handle(LOG_LEVEL_DEBUG, LOG_TAG_MESSAGE_UNPACK, info.to_string());
		}

		return 0;

	}else{

		if(!is_to_next){

			// Write Log
			if(logger_){
				string_append info;
				info.add("unpack 0x6A_0x06 package fail! err_msg:")->add(err.c_str());
				logger_->handle(LOG_LEVEL_ERROR, LOG_TAG_MESSAGE_UNPACK, info.to_string());
			}

			return 0;
		}else
			return -1;
	}
}

int message_0x6A_0x06::check_stream(char*& in_data, size_t& in_data_size, bool& is_to_next, string& err){
	char comp[2] = {0x6a, 0x06};
	if(memcmp(in_data, comp, 1) != 0 || memcmp(in_data + 6, comp + 1, 1) != 0){
		is_to_next = true;
		return -1;
	}
	return 0;
}
