/*
 * LParenthesisOperatorItem.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "LParenthesisOperatorItem.h"

LParenthesisOperatorItem::LParenthesisOperatorItem() {
	symbol = "(";
	precd = 0;
}

double LParenthesisOperatorItem::Exec(std::stack<Item*>* s) {
	return 0;
}


