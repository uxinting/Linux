/*
 * MinusOperatorItem.cpp
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#include "MinusOperatorItem.h"

int const MinusOperatorItem::precd = 1;

int MinusOperatorItem::Precedence() const {
	return precd;
}

double MinusOperatorItem::Exec(std::stack<Item*>* s) {
	double num2 = s->top()->Exec(null); s->pop();
	double num1 = s->top()->Exec(null); s->pop();
	double rs = num1 - num2;
	s->push(new OperandItem(rs));

	return rs;
}

