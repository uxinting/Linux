/*
 * AddOperatorItem.cpp
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#include "AddOperatorItem.h"

int const AddOperatorItem::precd = 1;

int AddOperatorItem::Precedence() const {
	return precd;
}

double AddOperatorItem::Exec(std::stack<Item*>* s) {
	double num2 = s->top()->Exec(null); s->pop();
	double num1 = s->top()->Exec(null); s->pop();
	double rs = num1 + num2;
	s->push(new OperandItem(rs));
	return rs;
}

