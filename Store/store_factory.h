/*
 * store_factory.h
 *
 *  Created on: 2016-10-19
 *      Author: root
 */

#ifndef STORE_FACTORY_H_
#define STORE_FACTORY_H_

#include "pb.h"
#include "store_handler.h"

namespace Store {

class store_factory : public store_handler {
public:
	store_factory(log_handler* log);
	virtual ~store_factory();

	bool doit(node* js) ;

private:
	boost::ptr_vector<store_handler> hdrs_;
};

}

#endif /* STORE_FACTORY_H_ */
