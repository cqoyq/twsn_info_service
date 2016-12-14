/*
 * pb.h
 *
 *  Created on: 2016-9-27
 *      Author: root
 */

#ifndef PB_H_
#define PB_H_

#include <boost/crc.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

#include <bingo/type.h>
#include <bingo/singleton.h>
#include <bingo/string.h>
#include <bingo/config/node.h>
#include <bingo/TCP/pack_and_unpack/pack_handler.h>
#include <bingo/TCP/pack_and_unpack/unpack_handler.h>
#include <bingo/TCP/pack_and_unpack/net_layer.h>
#include <bingo/log/log_handler.h>
#include <bingo/log/log_level.h>
#include <bingo/log/log_factory.h>
#include <bingo/thread/all.h>
using namespace bingo;
using namespace bingo::log;

typedef bingo::config::node 											node;
typedef bingo::TCP::pack_and_unpack::net_layer 				net_layer;
typedef bingo::TCP::pack_and_unpack::unpack_handler 	unpack_handler;
typedef bingo::TCP::pack_and_unpack::pack_handler 		pack_handler;

#define LOG_TAG_MAIN_FUNCTION			"twsn_info_main"
#define LOG_TAG_RABBITMQ_SENDOR 	"twsn_info_rabbitmq_sendor"
#define LOG_TAG_RABBITMQ_RECEIVER 	"twsn_info_rabbitmq_receiver"
#define LOG_TAG_MESSAGE_UNPACK		"twsn_info_message_unpack"
#define LOG_TAG_MESSAGE_PACK			"twsn_info_message_pack"
#define LOG_TAG_MESSAGE_HANDLER		"twsn_info_message_handler"
#define LOG_TAG_REV_TASK					"twsn_info_rev_task"
#define LOG_TAG_RESPONSE_TASK			"twsn_info_response_task"
#define LOG_TAG_DATABASE_TASK			"twsn_info_database_task"

typedef bingo::singleton_v0<log::log_factory> LOCAL_LOG_VISITOR_TYPE;

#define RABBITMQ_ROUTINGEKEY_MAX_SIZE  50
#define RABBITMQ_LOCAL_SERVER_ROUTINGEKEY  			"twsn_info_service"
#define RABBITMQ_KEY_TYPE_ACCEPTOR_SERVICE 			"tcp_acceptor"

#define TCP_MESSAGE_MAX_SIZE 				1024
#define RABBITMQ_MESSAGE_MAX_SIZE 		2048

#endif /* PB_H_ */
