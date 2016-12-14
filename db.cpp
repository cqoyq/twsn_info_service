/*
 * db.cpp
 *
 *  Created on: 2016-10-19
 *      Author: root
 */

#include "db.h"
#include "local_logger.h"

void make_db_pool_thr(){
	DB_POOL_TYPE::construct();				// db pool.
	if(DB_POOL_TYPE::instance()->make_mysql_pool(4, "mysql") == -1){
		string_append str;
		str.add("make mysql pool error! err_msg:")->add(DB_FUNC_TYPE::instance()->err().err_message().c_str());
		CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_ERROR, LOG_TAG_DATABASE_TASK, str.to_string());
		exit(0);
	}

	DB_POOL_TYPE::release();				// db pool.
}

db_func::db_func() : db_factory() {
	// TODO Auto-generated constructor stub

}

db_func::~db_func() {
	// TODO Auto-generated destructor stub
}

