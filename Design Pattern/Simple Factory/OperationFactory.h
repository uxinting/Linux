#include "Operation.h"
#include "OperationDiv.h"
#include "OperationMul.h"
#include "OperationAdd.h"
#include "OperationSub.h"
#include <string>

class OperationFactory
{
	public:
		static Operation* CreateOperate(char operate) {
			Operation* opr = 0;
			switch (operate) {
				case '+':
					opr = new OperationAdd();break;
				case '-':
					opr = new OperationSub();break;
				case '*':
					opr = new OperationMul();break;
				case '/':
					opr = new OperationDiv();break;
			}
			return opr;
		}
};
