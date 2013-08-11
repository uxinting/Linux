/*
 * main.cpp
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#include "Item.h"
#include "AddOperatorItem.h"
#include "MinusOperatorItem.h"
#include <iostream>

int main() {
	OperandItem item(2);
	OperandItem item2("2.0");
	OperandItem item3(3);
	AddOperatorItem addItem;
	MinusOperatorItem minusItem;

	std::stack<Item*> items;
	Item* is[] = {&item, &item2, &addItem, &item3, &minusItem};

	double rs(0);
	for (int i = 0; i < 5; i++) {
		rs = is[i]->Exec(&items);
	}
	std::cout << rs;
	return 0;
}


