#ifndef _OP_SUB
#define _OP_SUB

#include "Operation.h"

class OperationSub : public Operation
{
	public:
	double GetResult() {
		return getA() - getB();
	}
};

#endif
