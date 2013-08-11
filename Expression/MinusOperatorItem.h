/*
 * MinusOperatorItem.h
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#ifndef MINUSOPERATORITEM_H_
#define MINUSOPERATORITEM_H_

#include "Item.h"

class MinusOperatorItem : public OperatorItem
{
public:
	int Precedence() const;
	double Exec(std::stack<Item*>* s);

private:
	static int const precd;
};


#endif /* MINUSOPERATORITEM_H_ */
