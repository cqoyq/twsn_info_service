/*
 * rev_thr.h
 *
 *  Created on: 2016-9-28
 *      Author: root
 */

#ifndef REV_THR_H_
#define REV_THR_H_

#include "pb.h"
#include "local_logger.h"

#include "Package/package_factory.h"
using namespace Package;
#include "Handlers/hdr_factory.h"
using namespace Handlers;

// --------------------------- message ------------------------- //

#pragma pack(1)
struct twsn_rev_package{
	char message[RABBITMQ_MESSAGE_MAX_SIZE];
};
#pragma pack()

class twsn_rev_pack_or_unpack : public package_factory {
public:
	twsn_rev_pack_or_unpack(): package_factory(LOCAL_LOG_VISITOR_TYPE::instance()){};
	virtual ~twsn_rev_pack_or_unpack(){};
};

class twsn_rev_handler : public hdr_factory {
public:
	twsn_rev_handler(): hdr_factory(LOCAL_LOG_VISITOR_TYPE::instance()){};
	virtual ~twsn_rev_handler(){};
};

struct twsn_rev_task_data {
	twsn_rev_pack_or_unpack	pack_and_unpack;
	twsn_rev_handler handler;
};

typedef bingo::thread::task_message_data<twsn_rev_package> 	twsn_rev_data_message;
typedef bingo::thread::task_exit_data				   							twsn_rev_exit_message;

// --------------------------- many_to_one ------------------------- //

typedef bingo::thread::many_to_one<twsn_rev_data_message,
														  twsn_rev_exit_message,
														  twsn_rev_task_data
	> twsn_rev_task;
typedef bingo::singleton_v1<twsn_rev_task, twsn_rev_task::thr_top_callback> RB_RECEIVER_TASK;

void make_rev_task();
void free_rev_task();

#endif /* REV_THR_H_ */
