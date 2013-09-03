#include "stdafx.h"
#include <iostream>
#include "Expression.h"
#include "XExpression.h"
#include <regex>

using namespace std;

int _tmain(int argc, char *args[])
{
/*	SuffixExpression expression("3*sin(3.1415926/6)*2");
	cout << expression.Exec() << endl;*/

	XExpression xexpr("arctan(x)");
	cout << xexpr.Exec(1) << endl;
/*	for (int i = -2000; i < 2000; i++)
		cout << i << ' ' << xexpr.Exec(i) << endl;
	regex pattern("(x)|(sin)|[+|-|*|/]");
	string expr("x2+2*3");
	smatch mr;
	while(regex_search(expr, mr, pattern)) {
		cout << mr.str() << endl;
		expr = mr.suffix().str();
	}*/
	system("pause");
	return 0;
}