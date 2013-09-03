#include "XExpression.h"

double XExpression::Exec(double x) {
	std::stack<Item*> s;

	double rs = 0;
	XOperatorItem::SetX(x);

	for (std::list<Item*>::const_iterator it = items.begin(); it != items.end(); it++) {
		(*it)->Exec(&s);
	}

	return s.top()->Exec();
}