/*
 * DivOperatorItem.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef DIVOPERATORITEM_H_
#define DIVOPERATORITEM_H_

#include "Item.h"

class DivOperatorItem : public OperatorItem
{
public:
	DivOperatorItem();

	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(DivOperatorItem)
};


#endif /* DIVOPERATORITEM_H_ */
