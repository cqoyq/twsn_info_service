/*
 * packagefactory.cpp
 *
 *  Created on: 2016-10-6
 *      Author: root
 */

#include "package_factory.h"

#include "unpack/message_0x6a_0x01.h"
//#include "unpack/message_0x21.h"
//#include "unpack/message_0x22.h"
//#include "unpack/message_0x23.h"
//#include "unpack/message_0x24.h"
//#include "unpack/message_0x25.h"
//#include "unpack/message_0x26.h"
//#include "unpack/message_0x27.h"
//#include "unpack/message_0x28.h"
//#include "unpack/message_0x2A.h"
//#include "unpack/message_0x2B.h"
//#include "unpack/message_0x2C.h"
//#include "unpack/message_0x2D.h"
//#include "unpack/message_unknow.h"
//
//#include "pack/message_0x20.h"
//#include "pack/message_0x22.h"
//#include "pack/message_0x23.h"
//#include "pack/message_0x2C.h"
//#include "pack/message_0x2D.h"

using namespace Package;

package_factory::package_factory(log_handler* log) {
	// TODO Auto-generated constructor stub

	unpack_set_.push_back(new unpack::message_0x6A_0x01(log));
//	unpack_set_.push_back(new unpack::message_0x21(log));
//	unpack_set_.push_back(new unpack::message_0x22(log));
//	unpack_set_.push_back(new unpack::message_0x23(log));
//	unpack_set_.push_back(new unpack::message_0x24(log));
//	unpack_set_.push_back(new unpack::message_0x25(log));
//	unpack_set_.push_back(new unpack::message_0x26(log));
//	unpack_set_.push_back(new unpack::message_0x27(log));
//	unpack_set_.push_back(new unpack::message_0x28(log));
//	unpack_set_.push_back(new unpack::message_0x2A(log));
//	unpack_set_.push_back(new unpack::message_0x2B(log));
//	unpack_set_.push_back(new unpack::message_0x2C(log));
//	unpack_set_.push_back(new unpack::message_0x2D(log));
//	unpack_set_.push_back(new unpack::message_unknow(log));
//
//	pack_set_.push_back(new pack::message_0x20(log));
//	pack_set_.push_back(new pack::message_0x22(log));
//	pack_set_.push_back(new pack::message_0x23(log));
//	pack_set_.push_back(new pack::message_0x2C(log));
//	pack_set_.push_back(new pack::message_0x2D(log));
}

package_factory::~package_factory() {
	// TODO Auto-generated destructor stub
}

bool package_factory::unpack(char*& in, size_t& in_size, net_layer*& in_net,  node*& out_js){
	bool result = false;
	foreach_(unpack_handler& n, unpack_set_){
		if(n.handler(in, in_size, in_net, out_js) == 0){
			result = true;
			break;
		}
	}

	return result;
}

bool package_factory::pack(net_layer*& in_net, node*& in, char*& out_data, size_t& out_data_size){
	bool result = false;
	foreach_(pack_handler& n, pack_set_){
		if(n.handler(in, in_net, out_data, out_data_size) == 0){
			result = true;
			break;
		}
	}

	return result;
}



