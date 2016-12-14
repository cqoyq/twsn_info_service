/*
 * db.h
 *
 *  Created on: 2016-10-19
 *      Author: root
 */

#ifndef DB_H_
#define DB_H_

#include "pb.h"

#include <bingo/database/db_factory.h>
using namespace bingo::database;

class db_func : public db_factory  {
public:
	db_func();
	virtual ~db_func();
};

typedef bingo::singleton_v0<db_factory> DB_POOL_TYPE;
typedef bingo::singleton_v0<db_func>     DB_FUNC_TYPE;

void make_db_pool_thr();



#endif /* DB_H_ */
