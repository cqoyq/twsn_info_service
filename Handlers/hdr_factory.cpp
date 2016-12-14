/*
 * hdr_factory.cpp
 *
 *  Created on: 2016-10-9
 *      Author: root
 */

#include "hdr_factory.h"

//#include "content_hdr.h"
//
//#include "message_0x20_hdr.h"
//#include "message_0x21_hdr.h"
//#include "message_0x22_hdr.h"
//#include "message_0x23_hdr.h"
//#include "message_0x24_hdr.h"
//#include "message_0x25_hdr.h"
//#include "message_0x26_hdr.h"
//#include "message_0x27_hdr.h"
//#include "message_0x28_hdr.h"
//#include "message_0x2A_hdr.h"
//#include "message_0x2B_hdr.h"
//#include "message_0x2C_hdr.h"
//#include "message_0x2D_hdr.h"

using namespace Handlers;

// ----------------------------- hdr_factory -------------------------------  //
hdr_factory::hdr_factory(log_handler* log) {
	// TODO Auto-generated constructor stub
	logger_ = log;

//	hdr_set_.push_back(new message_0x20_hdr(log));
//	hdr_set_.push_back(new message_0x21_hdr(log));
//	hdr_set_.push_back(new message_0x22_hdr(log));
//	hdr_set_.push_back(new message_0x23_hdr(log));
//	hdr_set_.push_back(new message_0x24_hdr(log));
//	hdr_set_.push_back(new message_0x25_hdr(log));
//	hdr_set_.push_back(new message_0x26_hdr(log));
//	hdr_set_.push_back(new message_0x27_hdr(log));
//	hdr_set_.push_back(new message_0x28_hdr(log));
//	hdr_set_.push_back(new message_0x2A_hdr(log));
//	hdr_set_.push_back(new message_0x2B_hdr(log));
//	hdr_set_.push_back(new message_0x2C_hdr(log));
//	hdr_set_.push_back(new message_0x2D_hdr(log));
}

hdr_factory::~hdr_factory() {
	// TODO Auto-generated destructor stub
}

bool hdr_factory::doit(net_layer*& net, node* js){
	bool result = false;
	foreach_(handler& n, hdr_set_){
		if(n.doit(net, js)){
			result = true;
			break;
		}
	}

	return result;
}
