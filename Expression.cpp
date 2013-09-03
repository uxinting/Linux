/*
 * Expression.cpp
 *
 *  Created on: 2013
 *      Author: xinting
 */

#include "Expression.h"
#include <iostream>
#include <regex>

Expression::Expression(std::string s) {
	expr = s;
	expr += '#';
	factory = new OperatorFactory();
}

Expression::~Expression() {
	delete factory;
}

void Expression::Display() const {
	for (std::string::size_type ix = 0; ix != expr.size()-1; ix++) {
		std::cout << expr[ix];
	}
	std::cout << std::endl;

	for (std::list<Item*>::const_iterator it = items.begin(); it != items.end(); it++) {
		(*it)->Display();
	}
}

SuffixExpression::SuffixExpression(std::string s) :
Expression(s) {
	Inffix2Suffix(items, expr);
}

void SuffixExpression::Inffix2Suffix(std::list<Item*>& items, std::string expr) {
	std::string numberics("1234567890.");
	//std::string notOperator("1234567890.(#x");
	std::regex pattern(PATTERN);
	std::smatch m;
	std::stack<Item*> operatorItems;

	operatorItems.push(factory->GetOperatorItem("#"));
	std::string::size_type it = 0;
	while ( it != expr.size() ) {
		char ch = expr[it];
		if (ch == '#') break; //sentinel

		if (ch == '(') {
			operatorItems.push(new LParenthesisOperatorItem());

			it++;
			continue;
		}

		if (ch == ')') {
			while (operatorItems.top()->Precedence() != PRECD_LEFTP) {//not (
				items.push_back(operatorItems.top());
				operatorItems.pop();
			}
			operatorItems.pop();

			it++;
			continue;
		}

		if (ch == 'x') {
			items.push_back(factory->GetOperatorItem("x"));

			it++;
			continue;
		}

		if (ch > '0' && ch < '9') { //operand
			std::string::size_type pos = expr.find_first_not_of(numberics, it);
			std::string num = expr.substr(it, pos-it);

			items.push_back(new OperandItem(num));

			it = pos;
			continue;
		} else { //operator
			//std::string::size_type pos = expr.find_first_of(notOperator, it+1);
			//std::string optor = expr.substr(it, pos-it);
			std::string optor = expr.substr(it);
			std::regex_search(optor, m, pattern);
			OperatorItem* oitem = factory->GetOperatorItem(m.str());

			if (*oitem > *operatorItems.top()) {
				operatorItems.push(oitem);
			} else {
				while (*operatorItems.top() > *oitem) {
					items.push_back(operatorItems.top());
					operatorItems.pop();
				}
				operatorItems.push(oitem);
			}

			it += m.length();
			//it = pos;
			continue;
		}

		it++;
	}

	while (!operatorItems.empty()) {
		items.push_back(operatorItems.top());
		operatorItems.pop();
	}
}

double SuffixExpression::Exec() {
	std::stack<Item*> s;

	double rs = 0;
	for (std::list<Item*>::const_iterator it = items.begin(); it != items.end(); it++) {
		(*it)->Exec(&s);
	}

	return s.top()->Exec();
}
