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
RuntimeItem* RuntimeItem::pFirstItem = null;

ITEM_INIT::ITEM_INIT(RuntimeItem* pNewItem) {
		pNewItem->m_pNextItem = RuntimeItem::pFirstItem;
		RuntimeItem::pFirstItem = pNewItem;
}

struct RuntimeItem OperatorItem::optorOperatorItem = {
		"OperatorItem", 0x0
};

static ITEM_INIT _init_OperatorItem(&OperatorItem::optorOperatorItem);
RuntimeItem* OperatorItem::GetRuntimeItem() const {
	return &OperatorItem::optorOperatorItem;
}

void OperatorItem::Display() const {
	cout << "The precedence: " << Precedence() << " The operator symbol: " << symbol << endl;
}

int OperatorItem::Precedence() const {
	return precd;
}

