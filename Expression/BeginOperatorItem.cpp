/*
 * BeginOperatorItem.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "BeginOperatorItem.h"

REGISTER_OPERATOR(#, BeginOperatorItem)

BeginOperatorItem::BeginOperatorItem() {
	symbol = "#";
	precd = -1;
}

double BeginOperatorItem::Exec(std::stack<Item*>* s) {
	return s->top()->Exec();
}





