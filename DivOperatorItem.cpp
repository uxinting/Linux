/*
 * DivOperatorItem.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "DivOperatorItem.h"

REGISTER_OPERATOR(/, DivOperatorItem)

DivOperatorItem::DivOperatorItem() {
	symbol = "/";
	precd = 2;
}

double DivOperatorItem::Exec(std::stack<Item*>* s) {
	double num2 = s->top()->Exec(); s->pop();
	double num1 = s->top()->Exec(); s->pop();
	double rs = num1 / num2;
	s->push(new OperandItem(rs));
	return rs;
}


