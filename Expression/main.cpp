/*
 * main.cpp
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#include "Expression.h"
#include <iostream>

int main() {
	SuffixExpression expr("(1+3)*4");
	std::cout << expr.Exec() << std::endl;
	return 0;
}


