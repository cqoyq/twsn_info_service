/*
 * package_factory.h
 *
 *  Created on: 2016-10-6
 *      Author: root
 */

#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

#include "pb.h"
#include "base.h"

namespace Package {

class package_factory {
public:
	package_factory(log_handler* log);
	virtual ~package_factory();

	bool pack(net_layer*& in_net, node*& in, char*& out_data, size_t& out_data_size);
	bool unpack(char*& in, size_t& in_size, net_layer*& in_net,  node*& out_js);

private:
	boost::ptr_vector<pack_handler> pack_set_;
	boost::ptr_vector<unpack_handler> unpack_set_;
};

//typedef bingo::singleton_v1<package_factory, log_handler*> PACKAGE_FACTORY_TYPE;

}

#endif /* PACKAGE_FACTORY_H_ */
