/*
 * base.h
 *
 *  Created on: 2016-10-6
 *      Author: root
 */

#ifndef PACKAGE_BASE_H_
#define PACKAGE_BASE_H_

#include "pb.h"

namespace Package {


// -------------------------------------------------- Unpack  -------------------------------------------- //

// Unpack message base class.
class unpack_message_base {;
public:
	virtual ~unpack_message_base(){};
protected:
	virtual int check_stream(char*& in_data, size_t& in_data_size, bool& is_to_next, string& err)=0;

	log_handler* logger_;

};

// Check steam type.
bool is_stream_type_data(char* header);

// u8 -> string
string u8_to_string(char* u8_p);

// u16 -> string
string u16_to_string(char* u16_p);

// u24 -> string
string u24_to_string(char* u24_p);

// u32 -> string
string u32_to_string(char* u32_p);

// u40 -> string
string u40_to_string(char* u40_p);

// u56 -> string
string u56_to_string(char* u56_p);

// Unpack base stream - > node
// return next memory block header-pointer.
char* base_stream_to_node(char* stream, node*& n);

// -------------------------------------------------- Pack  -------------------------------------------- //

// Pack message base class.
class pack_message_base {;
public:
	virtual ~pack_message_base(){};
protected:
	virtual int check_node(node*& node, string& err)=0;

	log_handler* logger_;
};

// Construct rabbitmq package function.
void make_rabbitmq_data_message(
		net_layer*& net,
		char*& data,
		size_t& data_size,
		char*& out,  size_t& out_size
		);

// Tcp message type enum.
enum message_type {

};

// Construct tcp stream package function.
void make_tcp_message(
		message_type 		type,							// package type
		bool						is_passive,				// package is passive, then header is 0x66 ,otherwise 0x33.
		const char* 		app,							// application-layer data header.
		u8_t						app_size,					// size of application-layer data.
		char*& out,  size_t& out_size				// output after pack.
		);

// string -> u8_t
void string_to_u8(string& s, char* u8_p);

// string -> u16_t
void string_to_u16(string& s, char* u16_p);

// string -> u24_t
void string_to_u24(string& s, char* u24_p);

// string -> u56_t
void string_to_u56(string& s, char* u56_p);

// string -> u40_t
void string_to_u40(string& s, char* u40_p);

// string -> u1024_t
void string_to_u1024(string& s, char* u128_p);

}

#endif /* PACKAGE_BASE_H_ */
