/*
 * hdr_factory.h
 *
 *  Created on: 2016-10-9
 *      Author: root
 */

#ifndef HDR_FACTORY_H_
#define HDR_FACTORY_H_

#include "pb.h"
#include "handler.h"

namespace Handlers {

class hdr_factory : public handler {
public:
	hdr_factory(log_handler* log);
	virtual ~hdr_factory();

	bool doit(net_layer*& net, node* js);

private:
	boost::ptr_vector<handler> hdr_set_;
};

}


#endif /* HDR_FACTORY_H_ */
