/*
 * MultiOperatorItem.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef MULTIOPERATORITEM_H_
#define MULTIOPERATORITEM_H_

#include "Item.h"

class MultiOperatorItem : public OperatorItem
{
public:
	MultiOperatorItem();

	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(MultiOperatorItem)
};


#endif /* MULTIOPERATORITEM_H_ */
