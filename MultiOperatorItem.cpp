/*
 * MultiOperatorItem.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "MultiOperatorItem.h"

REGISTER_OPERATOR(*, MultiOperatorItem)

MultiOperatorItem::MultiOperatorItem() {
	symbol = "*";
	precd = 2;
}

double MultiOperatorItem::Exec(std::stack<Item*>* s) {
	double num2 = s->top()->Exec(); s->pop();
	double num1 = s->top()->Exec(); s->pop();
	double rs = num1 * num2;
	s->push(new OperandItem(rs));
	return rs;
}


