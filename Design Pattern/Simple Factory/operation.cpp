#include "OperationFactory.h"
#include <iostream>

int main(int argc, char* args[]) {
	Operation* od = OperationFactory::CreateOperate('+');
	od->setA(1);
	od->setB(0);
	try {
		std::cout << od->GetResult() << std::endl;
	} catch (std::invalid_argument &err) {
		std::cerr << "Invalid Argument: " << err.what() << std::endl;
	}
	return 0;
}
