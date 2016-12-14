/*
 * main.cpp
 *
 *  Created on: 2016-12-8
 *      Author: root
 */

#include "pb.h"

#include "rb.h"
#include "rev_thr.h"
#include "db_thr.h"
#include "db.h"

void init(){
	RABBITMQ_FACTORY_TYPE::construct();		// Rabbitmq client and server.

	// Construct local logger.
	CONSOLE_LOGGER_TYPE::construct();
	if(!CONSOLE_LOGGER_TYPE::instance()->make_local_logger()){
		cout << "make local logger fail! error:" << CONSOLE_LOGGER_TYPE::instance()->err().err_message() << endl;
		CONSOLE_LOGGER_TYPE::release();
		exit(0);
	}

	CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_INFO, LOG_TAG_MAIN_FUNCTION,
							string_append().add("make local logger success!")->to_string()
							);

	// Logger to rabbitmq-server.
	LOCAL_LOG_VISITOR_TYPE::construct();
	if(!LOCAL_LOG_VISITOR_TYPE::instance()->make_rabbitmq_logger(RABBITMQ_FACTORY_TYPE::instance())){

		string_append ap;
		ap.add("make rabbitmq logger fail! err_msg:")->add(LOCAL_LOG_VISITOR_TYPE::instance()->err().err_message().c_str());
		CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_ERROR, LOG_TAG_MAIN_FUNCTION, ap.to_string());
		exit(0);
	}

	CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_INFO, LOG_TAG_MAIN_FUNCTION,
							string_append().add("make rabbitmq logger success!")->to_string()
							);

	DB_FUNC_TYPE::construct();   			// db function.
	if(DB_FUNC_TYPE::instance()->make_mysql_visitor("mysql") == -1){

		string_append ap;
		ap.add("make mysql visitor error! err_msg:")->add(DB_FUNC_TYPE::instance()->err().err_message().c_str());
		CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_ERROR, LOG_TAG_MAIN_FUNCTION, ap.to_string());
		exit(0);
	}

	CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_INFO, LOG_TAG_MAIN_FUNCTION,
							string_append().add("make db function success!")->to_string()
							);


	make_rev_task();
	make_db_task();

	CONSOLE_LOGGER_TYPE::instance()->handle(LOG_LEVEL_INFO, LOG_TAG_MAIN_FUNCTION,
									string_append().add("make receive and response task success!")->to_string()
									);
}

void destory(){

	RABBITMQ_FACTORY_TYPE::release();
	CONSOLE_LOGGER_TYPE::release();
	LOCAL_LOG_VISITOR_TYPE::release();

	DB_FUNC_TYPE::release();   			// db function.

	free_rev_task();
	free_db_task();
}

int main (int argc, char *argv[]) {

	// Init-func
	init();

	boost::thread t0(make_db_pool_thr);
	boost::thread t1(make_rb_sendor);
	boost::thread t2(make_rb_receiver);

	t0.join();
	t1.join();
	t2.join();

	// Free memory.
	destory();

	return 0;
}


