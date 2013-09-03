#ifndef XEXPRESSION_H_
#define XEXPRESSION_H_

#include "Expression.h"

class XExpression : public SuffixExpression
{
public:
	XExpression(std::string s) : SuffixExpression(s){}
	double Exec(double x);
};

#endif /* XExpression.h */