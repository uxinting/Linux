/*
 * Item.cpp
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#include "Item.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Item::Item() {}

Item::~Item() {}

bool Item::operator>(Item& item) const{
	return this->Precedence() > item.Precedence();
}


int const OperandItem::precd = 0;

//OperandItem
OperandItem::OperandItem(double val) {
	value = val;
}

OperandItem::OperandItem(int val) {
	value = (double) val;
}

OperandItem::OperandItem(const std::string s) {
	value = atof(s.data());
}

OperandItem::~OperandItem() {}

void OperandItem::Display() const {
	cout << "The precedence: " << Precedence() << " The value: " << value << endl;
}

double OperandItem::Exec(std::stack<Item*>* s) {
	if (s == null) {
		return value;
	} else {
		s->push(this);
		return 0;
	}
}

int OperandItem::Precedence() const {
	return precd;
}

//Operator Item
void OperatorItem::Display() const {
	cout << "The precedence: " << Precedence() << " The operator symbol: " << symbol << endl;
}

