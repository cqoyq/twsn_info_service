/*
 * base.h
 *
 *  Created on: 2016-10-12
 *      Author: root
 */

#ifndef HANDLERS_BASE_H_
#define HANDLERS_BASE_H_

#include "pb.h"

namespace Handlers {

// Construct rabbitmq-message and send to destination.
void send_rabbitmq_message(net_layer*& net, log_handler*& log, node*& js);

}

#endif /* HANDLERS_BASE_H_ */
