/*
 * LParenthesisOperatorItem.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef LPARENTHESISOPERATORITEM_H_
#define LPARENTHESISOPERATORITEM_H_

#include "Item.h"

class LParenthesisOperatorItem : public OperatorItem
{
public:
	LParenthesisOperatorItem();

	double Exec(std::stack<Item*>*);
};


#endif /* LPARENTHESISOPERATORITEM_H_ */
