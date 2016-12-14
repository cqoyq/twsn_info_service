/*
 * handler.h
 *
 *  Created on: 2016-10-9
 *      Author: root
 */

#ifndef HANDLER_H_
#define HANDLER_H_

#include "pb.h"

namespace Handlers {

class handler{
public:
	virtual ~handler(){}

	// If handle success then return true, otherwise return false.
	virtual bool doit(net_layer*& net, node* js) = 0;

protected:
	log_handler* logger_;
};

}


#endif /* HANDLER_H_ */
