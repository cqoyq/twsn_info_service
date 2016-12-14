/*
 * base.cpp
 *
 *  Created on: 2016-10-6
 *      Author: root
 */

#include "base.h"

// -------------------------------------------------- Unpack  -------------------------------------------- //

bool Package::is_stream_type_data(char* header){
	return (header[0] == 0x01)?true : false;
}

string Package::u8_to_string(char* u8_p){
	int n = 0;
	memcpy(&n, u8_p, 1);
	return lexical_cast<string>(n);
}

string Package::u16_to_string(char* u16_p){
	u16_t n = 0;
	memcpy(&n, u16_p, 2);
	return lexical_cast<string>(n);
}

string Package::u24_to_string(char* u24_p){
	u32_t n = 0;
	memcpy(&n, u24_p, 3);
	return lexical_cast<string>(n);
}

string Package::u32_to_string(char* u32_p){
	u32_t n = 0;
	memcpy(&n, u32_p, 4);
	return lexical_cast<string>(n);
}

string Package::u40_to_string(char* u40_p){
	u64_t n = 0;
	memcpy(&n, u40_p, 5);
	return lexical_cast<string>(n);
}

string Package::u56_to_string(char* u56_p){
	u64_t n = 0;
	memcpy(&n, u56_p, 7);
	return lexical_cast<string>(n);
}

char* Package::base_stream_to_node(char* stream, node*& n){
	node* header = new node("header", Package::u8_to_string(stream).c_str());
	node* base_code = new node("base_code", Package::u32_to_string(stream + 2).c_str());
	node* command = new node("command", Package::u8_to_string(stream + 2 + 4).c_str());
	node* frame_code = new node("frame_code", Package::u8_to_string(stream + 2 + 4 + 1).c_str());
	node* endpoint_code = new node("endpoint_code", Package::u32_to_string(stream + 2 + 4 + 1 + 1).c_str());

	n->child.push_back(header);
	n->child.push_back(base_code);
	n->child.push_back(command);
	n->child.push_back(frame_code);
	n->child.push_back(endpoint_code);

	return stream + 2 + 4 + 1 + 1 + 4;
}

// -------------------------------------------------- Pack  -------------------------------------------- //

void Package::make_rabbitmq_data_message(
		net_layer*& net,
		char*& data,
		size_t& data_size,
		char*& out,  size_t& out_size){

	//                  type    source_routingkey    								sockid     data
	size_t size = 1       + RABBITMQ_ROUTINGEKEY_MAX_SIZE 	+ 8        + data_size;
	char out_t[size];
	memset(&out_t[0], 0x00, size);

	out_t[0] = 0x01;

	int len = net->req_addr.length();
	if(len > RABBITMQ_ROUTINGEKEY_MAX_SIZE)
		return;

	memcpy(out_t + 1, net->req_addr.c_str(), len);
	memcpy(out_t + 1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE, &(net->session), 8);
	memcpy(out_t + 1 + RABBITMQ_ROUTINGEKEY_MAX_SIZE + 8, data, data_size);

	memcpy(out, out_t, size);
	out_size = size;
}

void Package::make_tcp_message(
		message_type 		type,
		bool						is_passive,
		const char* 		app,
		u8_t						app_size,
		char*& out,  size_t& out_size){

	//                 header   length    app-lenght     crc
	size_t size = 1       + 1     		+ app_size     + 1;
	char out_t[size];
	memset(&out_t[0], 0x00, size);

	// header
	out_t[0] = (is_passive) ? 0x33 : 0x66;

	// length
	out_t[1] = app_size;

	// application
	memcpy(out_t + 2, app,  app_size);

	// calculate crc.
	u8_t chr = out_t[1] ^ out_t[2];
	for (size_t i = 3; i < size - 1; i++) {
		chr = chr ^ out_t[i];
	}
	out_t[size - 1] = chr;

	memcpy(out, out_t, size);
	out_size = size;
}


void Package::string_to_u8(string& s, char* u8_p){
	int n = lexical_cast<int>(s);
	memcpy(u8_p, &n, 1);
}

void Package::string_to_u16(string& s, char* u16_p){
	int n = lexical_cast<int>(s);
	memcpy(u16_p, &n, 2);
}

void Package::string_to_u24(string& s, char* u24_p){
	int n = lexical_cast<int>(s);
	memcpy(u24_p, &n, 3);
}

void Package::string_to_u56(string& s, char* u56_p){
	long n = lexical_cast<long>(s);
	memcpy(u56_p, &n, 7);
}

void Package::string_to_u40(string& s, char* u40_p){
	long n = lexical_cast<long>(s);
	memcpy(u40_p, &n, 5);
}

void Package::string_to_u1024(string& s, char* u128_p){
	size_t len = s.length();
	if(len <= 128)
		memcpy(u128_p, s.c_str(), len);
}

