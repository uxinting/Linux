#ifndef _OP_DIV
#define _OP_DIV

#include "Operation.h"
#include <stdio.h>
#include <stdexcept>

class OperationDiv : public Operation
{
	public:
	double GetResult() {
		if (getB() == 0) {
			throw std::invalid_argument("the divided number can't be zero!");
		}
		return getA() / getB();
	}
};

#endif
