/*
 * BeginOperatorItem.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef BEGINOPERATORITEM_H_
#define BEGINOPERATORITEM_H_

#include "Item.h"

class BeginOperatorItem : public OperatorItem
{
public:
	BeginOperatorItem();

	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(BeginOperatorItem)
};


#endif /* BEGINOPERATORITEM_H_ */
