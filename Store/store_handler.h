/*
 * store_handler.h
 *
 *  Created on: 2016-10-19
 *      Author: root
 */

#ifndef STORE_HANDLER_H_
#define STORE_HANDLER_H_

#include "pb.h"

namespace Store {

class store_handler {
public:
	virtual ~store_handler(){}

	// If handle success then return true, otherwise return false.
	virtual bool doit(node* js) = 0;
};

}


#endif /* STORE_HANDLER_H_ */
