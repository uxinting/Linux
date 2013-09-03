#include "XOperatorItem.h"

REGISTER_OPERATOR(x, XOperatorItem)

double XOperatorItem::x = 0;

XOperatorItem::XOperatorItem() {
	symbol = "x";
	precd = 0;
}

double XOperatorItem::Exec(std::stack<Item*>* s) {
	s->push(new OperandItem(x));
	return 0;
}

void XOperatorItem::SetX(double xx) {
	x = xx;
}