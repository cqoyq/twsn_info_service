/*
 * message_0x6A_0x1D.cpp
 *
 *  Created on: 2016-10-18
 *      Author: root
 */

#include "message_0x6a_0x1d.h"

using namespace Package;
using namespace Package::unpack;

enum status_type {
	status_type_position  															= 0x00,		// 定位
	status_type_remote_controller  												= 0x01,		// 遥控器
	status_type_sensor	  															= 0x02,		// 传感器
	status_type_controller	  														= 0x03,		// 控制器
	status_type_digital_temperature_sensor 								= 0x10,		// 数字温度传感器
	status_type_digital_humidity_sensor 										= 0x11,		// 数字湿度传感器
	status_type_digital_temperature_and_humidity_sensor 			= 0x12,		// 数字温湿度传感器
	status_type_illumination_sensor 											= 0x14,		// 照度传感器
	status_type_door_sensor 														= 0x30,		// 门磁
	status_type_window_sensor 													= 0x31,		// 窗磁
	status_type_alert_switcher 													= 0x32,		// 告警开关
	status_type_infrared_passive_sensor 										= 0x33,		// 被动红外
	status_type_infrared_correlation_sensor 									= 0x34,		// 对射红外
};

bool unpack_status_infrared_correlation_sensor (char* p, node*& status){
	char cmp[1] = {status_type_infrared_correlation_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_infrared_correlation_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_infrared_passive_sensor (char* p, node*& status){
	char cmp[1] = {status_type_infrared_passive_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_infrared_passive_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_alert_switcher (char* p, node*& status){
	char cmp[1] = {status_type_alert_switcher};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_alert_switcher;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_window_sensor (char* p, node*& status){
	char cmp[1] = {status_type_window_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_window_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_door_sensor (char* p, node*& status){
	char cmp[1] = {status_type_door_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_door_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_illumination_sensor (char* p, node*& status){
	char cmp[1] = {status_type_illumination_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_illumination_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u16_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_digital_TH_sensor (char* p, node*& status){
	char cmp[1] = {status_type_digital_temperature_and_humidity_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_digital_temperature_and_humidity_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u32_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_digital_humidity_sensor(char* p, node*& status){
	char cmp[1] = {status_type_digital_humidity_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_digital_humidity_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u8_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_digital_temperature_sensor(char* p, node*& status){
	char cmp[1] = {status_type_digital_temperature_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_digital_temperature_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u16_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_controller(char* p, node*& status){
	char cmp[1] = {status_type_controller};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_controller;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value");

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_sensor(char* p, node*& status){
	char cmp[1] = {status_type_sensor};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_sensor;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value");

		status->child.push_back(status_type);
		status->child.push_back(status_value);

		return true;
	}else
		return false;
}

bool unpack_status_remote_controller(char* p, node*& status){
	char cmp[1] = {status_type_remote_controller};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_remote_controller;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value", Package::u16_to_string(p + 1).c_str());

		status->child.push_back(status_type);
		status->child.push_back(status_value);
		return true;
	}else
		return false;
}

bool unpack_status_position(char* p, node*& status){
	char cmp[1] = {status_type_position};
	if(memcmp(p, cmp, 1 ) == 0){
		int n_status_type = status_type_position;
		node* status_type = new node("status_type", lexical_cast<string>(n_status_type).c_str());
		node* status_value = new node("status_value");

		status->child.push_back(status_type);
		status->child.push_back(status_value);
		return true;
	}else
		return false;
}




void unpack_0x6A_0x1D_message(char*& in_data, size_t& in_data_size, node*& data){
	char* app_header = in_data;

	// Get base stream.
	char* next = base_stream_to_node(app_header, data);

	node* strength = new node("strength");
	node* status = new node("status");
	node* cost_time = new node("cost_time");

	data->child.push_back(strength);
	data->child.push_back(status);
	data->child.push_back(cost_time);

	char size[1] = {0x11};
	if(memcmp(app_header + 1, size, 1 ) == 0){
		// strength
		strength->value = Package::u8_to_string(next);

		// status
//		status->value = Package::u40_to_string(next + 1);
		if(!unpack_status_position(next + 1, status)
				&& !unpack_status_alert_switcher(next + 1, status)
				&& !unpack_status_controller(next + 1, status)
				&& !unpack_status_digital_TH_sensor(next + 1, status)
				&& !unpack_status_digital_humidity_sensor(next + 1, status)
				&& !unpack_status_digital_temperature_sensor(next + 1, status)
				&& !unpack_status_door_sensor(next + 1, status)
				&& !unpack_status_illumination_sensor(next + 1, status)
				&& !unpack_status_infrared_correlation_sensor(next + 1, status)
				&& !unpack_status_infrared_passive_sensor(next + 1, status)
				&& !unpack_status_remote_controller(next + 1, status)
				&& !unpack_status_sensor(next + 1, status)
				&& !unpack_status_window_sensor(next + 1, status)){

		}

		// cost_time
		cost_time->value = Package::u8_to_string(next + 1 + 5);
	}

}

message_0x6A_0x1D::message_0x6A_0x1D(log_handler*& log) {
	// TODO Auto-generated constructor stub
	logger_= log;
}

message_0x6A_0x1D::~message_0x6A_0x1D() {
	// TODO Auto-generated destructor stub
}

int message_0x6A_0x1D::handler(char*& in_data, size_t& in_data_size, net_layer*& in_net,  node*& data){
	bool is_to_next =false;
	string err;
	if(check_stream(in_data, in_data_size, is_to_next, err) == 0){

		// Unpack message.
		// -------- node structure  --------
		// {
		//		... base structure ...
		//		"strength":""       					// 接收场强
		//		{
		//			"status_type":""				// 状态类型
		//			"status_value":""				// 状态参数
		//		}
		//		"cost_time":""     	  				// 转发基站收到无线单发终端上报状态的时间
		// }
		unpack_0x6A_0x1D_message(in_data, in_data_size, data);

		// Write Log
		if(logger_){
			string_append info;
			info.add("unpack 0x6A_0x1D success!");
			logger_->handle(LOG_LEVEL_DEBUG, LOG_TAG_MESSAGE_UNPACK, info.to_string());
		}

		return 0;

	}else{

		if(!is_to_next){

			// Write Log
			if(logger_){
				string_append info;
				info.add("unpack 0x6A_0x1D package fail! err_msg:")->add(err.c_str());
				logger_->handle(LOG_LEVEL_ERROR, LOG_TAG_MESSAGE_UNPACK, info.to_string());
			}

			return 0;
		}else
			return -1;
	}
}

int message_0x6A_0x1D::check_stream(char*& in_data, size_t& in_data_size, bool& is_to_next, string& err){
	char comp[2] = {0x6a, 0x1d};
	if(memcmp(in_data, comp, 1) != 0 || memcmp(in_data + 6, comp + 1, 1) != 0){
		is_to_next = true;
		return -1;
	}
	return 0;
}
