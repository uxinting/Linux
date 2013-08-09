#ifndef _OP_ADD
#define _OP_ADD

#include "Operation.h"

class OperationAdd : public Operation
{
	public:
		double GetResult() {
			double result = 0;
			result = getA() + getB();
			return result;
		}
};

#endif
