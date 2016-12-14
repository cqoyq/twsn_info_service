/*
 * store_factory.cpp
 *
 *  Created on: 2016-10-19
 *      Author: root
 */

#include "store_factory.h"
//#include "message_0x20_store.h"
//#include "message_0x21_store.h"
//#include "message_0x22_store.h"
//#include "message_0x23_store.h"
//#include "message_0x24_store.h"
//#include "message_0x25_store.h"
//#include "message_0x26_store.h"
//#include "message_0x27_store.h"
//#include "message_0x28_store.h"
//#include "message_0x2A_store.h"
//#include "message_0x2B_store.h"
using namespace Store;

store_factory::store_factory(log_handler* log) {
	// TODO Auto-generated constructor stub
//	hdrs_.push_back(new message_0x20_store(log));
//	hdrs_.push_back(new message_0x21_store(log));
//	hdrs_.push_back(new message_0x22_store(log));
//	hdrs_.push_back(new message_0x23_store(log));
//	hdrs_.push_back(new message_0x24_store(log));
//	hdrs_.push_back(new message_0x25_store(log));
//	hdrs_.push_back(new message_0x26_store(log));
//	hdrs_.push_back(new message_0x27_store(log));
//	hdrs_.push_back(new message_0x28_store(log));
//	hdrs_.push_back(new message_0x2A_store(log));
//	hdrs_.push_back(new message_0x2B_store(log));
}

store_factory::~store_factory() {
	// TODO Auto-generated destructor stub
}

bool store_factory::doit(node* js){
	foreach_(store_handler&n, hdrs_){
		if(n.doit(js))
			return true;
	}

	return false;
}

