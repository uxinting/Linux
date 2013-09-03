#include "TrigOperatorItem.h"
#include <math.h>

REGISTER_OPERATOR(sin, SinOperatorItem)

SinOperatorItem::SinOperatorItem() {
	symbol = "sin";
	precd = PRECD_SIN;
}

double SinOperatorItem::Exec(std::stack<Item*>* s) {
	double number = s->top()->Exec();s->pop();
	double rs = sin(number);
	s->push(new OperandItem(rs));
	return rs;
}

#define IMPLEMENT_EXEC(prefix, f) \
double prefix##OperatorItem::Exec(std::stack<Item*>* st){ \
	double number = st->top()->Exec(); st->pop(); \
	double rs = f(number); \
	st->push(new OperandItem(rs)); \
	return rs; \
}

IMPLEMENT_OPERATOR(Cos, cos, PRECD_COS)
IMPLEMENT_EXEC(Cos, cos)

IMPLEMENT_OPERATOR(Tan, tan, PRECD_TAN)
IMPLEMENT_EXEC(Tan, tan)

IMPLEMENT_OPERATOR(Cot, cot, PRECD_COT)
IMPLEMENT_EXEC(Cot, 1 / tan)

IMPLEMENT_OPERATOR(Arcsin, arcsin, PRECD_ARCSIN)
IMPLEMENT_EXEC(Arcsin, asin)

IMPLEMENT_OPERATOR(Arccos, arccos, PRECD_ARCCOS)
IMPLEMENT_EXEC(Arccos, acos)

IMPLEMENT_OPERATOR(Arctan, arctan, PRECD_ARCTAN)
IMPLEMENT_EXEC(Arctan, atan)

IMPLEMENT_OPERATOR(Arccot, arccot, PRECD_ARCCOT)
IMPLEMENT_EXEC(Arccot, PI / 2 - atan)

IMPLEMENT_OPERATOR(Ln, ln, PRECD_LN)
IMPLEMENT_EXEC(Ln, log)

IMPLEMENT_OPERATOR(Lg, lg, PRECD_LG)
IMPLEMENT_EXEC(Lg, log10)