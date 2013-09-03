/*
 * AddOperatorItem.h
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#ifndef ADDOPERATORITEM_H_
#define ADDOPERATORITEM_H_

#include "Item.h"

class AddOperatorItem : public OperatorItem
{
public:
	AddOperatorItem();
	double Exec(std::stack<Item*>* s);

DECLAR_OPERATOR(AddOperatorItem)
};


#endif /* ADDOPERATORITEM_H_ */
