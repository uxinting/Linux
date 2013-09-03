/*
 * LParenthesisOperatorItem.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "LParenthesisOperatorItem.h"

LParenthesisOperatorItem::LParenthesisOperatorItem() {
	symbol = "(";
	precd = PRECD_LEFTP;
}

double LParenthesisOperatorItem::Exec(std::stack<Item*>* s) {
	return 0;
}


