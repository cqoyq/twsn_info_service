/*
 * db_thr.h
 *
 *  Created on: 2016-10-2
 *      Author: root
 */

#ifndef DB_THR_H_
#define DB_THR_H_

#include "pb.h"
#include "local_logger.h"

#include "Package/package_factory.h"
using namespace Package;
#include "Store/store_factory.h"
using namespace Store;

// --------------------------- message ------------------------- //

#pragma pack(1)
struct twsn_db_package{
	char message[RABBITMQ_MESSAGE_MAX_SIZE];
};
#pragma pack()

class twsn_db_pack_or_unpack : public package_factory {
public:
	twsn_db_pack_or_unpack(): package_factory(LOCAL_LOG_VISITOR_TYPE::instance()){};
	virtual ~twsn_db_pack_or_unpack(){};
};

class twsn_db_factory : public store_factory {
public:
	twsn_db_factory() : store_factory(LOCAL_LOG_VISITOR_TYPE::instance()){};
	virtual ~twsn_db_factory(){};
};

struct twsn_db_task_data {
	twsn_db_pack_or_unpack pack_and_unpack;
	twsn_db_factory	factory;
};

typedef bingo::thread::task_message_data<twsn_db_package> 	twsn_db_data_message;
typedef bingo::thread::task_exit_data				   							twsn_db_exit_message;

// --------------------------- many_to_many ------------------------- //

typedef bingo::thread::many_to_many<twsn_db_data_message,
														  twsn_db_exit_message,
														  twsn_db_task_data
	> twsn_db_task;
typedef bingo::singleton_v2<twsn_db_task, twsn_db_task::thr_top_callback, int> RB_DB_TASK;

void make_db_task();
void free_db_task();


#endif /* DB_THR_H_ */
