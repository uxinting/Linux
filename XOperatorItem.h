#ifndef XOPERATORITEM_H_
#define XOPERATORITEM_H_

#include "Item.h"

class XOperatorItem : public OperatorItem
{
public:
	XOperatorItem();
	double Exec(std::stack<Item*>* s);
	static void SetX(double);

	DECLAR_OPERATOR(XOperatorItem)
private:
	static double x;
};

#endif /* XOperatorItem.h */