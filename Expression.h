/*
 * Expression.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "OperatorFactory.h"
#include <list>
#include <string>

#define PATTERN ("(x)|(cos)|(tan)|(cot)|(arctan)|(arccot)|(arcsin)|(arccos)|(sin)|[+|-|*|/]")

class Expression
{
public:
	Expression(std::string);
	virtual ~Expression();

	void Display() const;
	virtual double Exec() = 0;
protected:
	std::string expr;
	std::list<Item*> items;
	OperatorFactory* factory;
};


//suffix expression
class SuffixExpression : public Expression
{
public:
	SuffixExpression(std::string);

	double Exec();
protected:
	void Inffix2Suffix(std::list<Item*>&, std::string);
};

#endif /* EXPRESSION_H_ */
