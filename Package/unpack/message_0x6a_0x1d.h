/*
 * message_0x6A_0x1D.h
 *
 *  Created on: 2016-10-18
 *      Author: root
 */

#ifndef PACKAGE_UNPACK_MESSAGE_0x6A_0x1D_H_
#define PACKAGE_UNPACK_MESSAGE_0x6A_0x1D_H_

#include "pb.h"
#include "../base.h"

namespace Package { namespace unpack {

class message_0x6A_0x1D : public unpack_handler, public unpack_message_base {
public:
	message_0x6A_0x1D(log_handler*& log);
	virtual ~message_0x6A_0x1D();

	int handler(char*& in_data, size_t& in_data_size, TCP::pack_and_unpack::net_layer*& in_net,  node*& data);

protected:
	int check_stream(char*& in_data, size_t& in_data_size, bool& is_to_next, string& err);
};

}}

#endif /* PACKAGE_UNPACK_MESSAGE_0x6A_0x1D_H_ */
