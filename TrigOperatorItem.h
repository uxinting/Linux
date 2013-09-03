#ifndef SINOPERATORITEM_H_
#define SINOPERATORITEM_H_

#include "Item.h"

class SinOperatorItem : public OperatorItem
{
public:
	SinOperatorItem();
	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(SinOperatorItem)
};

class CosOperatorItem : public OperatorItem
{
public:
	CosOperatorItem();
	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(CosOperatorItem)
};

class TanOperatorItem : public OperatorItem
{
public:
	TanOperatorItem();
	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(TanOperatorItem)
};

class CotOperatorItem : public OperatorItem
{
public:
	CotOperatorItem();
	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(CotOperatorItem)
};

class ArcsinOperatorItem : public OperatorItem
{
public:
	ArcsinOperatorItem();
	double Exec(std::stack<Item*>*);

	DECLAR_OPERATOR(ArcsinOperatorItem);
};

#define PI 3.1415926

OPERATOR_CLASS(Arccos)
OPERATOR_CLASS(Arctan)
OPERATOR_CLASS(Arccot)
OPERATOR_CLASS(Ln)
OPERATOR_CLASS(Lg)
#endif /* SinOperatorItem.h */