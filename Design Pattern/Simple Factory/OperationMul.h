#ifndef _OP_MUL
#define _OP_MUL

#include "Operation.h"

class OperationMul : public Operation
{
	public:
	double GetResult() {
		return getA() * getB();
	}
};

#endif
