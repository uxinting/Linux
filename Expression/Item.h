/*
 * Item.h
 *
 *  Created on: 2013年8月11日
 *      Author: xinting
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <stack>
#include <string>

#define null 0x00000000

class Item
{
public:
	Item();
	virtual ~Item();

	//this function get this Item's precedence
	virtual int Precedence() const = 0;

	//get this item's value
	virtual double Exec(std::stack<Item*>* s=null) = 0;

	//display self
	virtual void Display() const = 0;

	bool operator > (Item& item) const;
};

//Item for the numbers, not operator
class OperandItem : public Item
{
public:
	OperandItem(const std::string);
	OperandItem(double);
	OperandItem(int);
	~OperandItem();

	int Precedence() const;
	double Exec(std::stack<Item*>* s);
	void Display() const;

private:
	static int const precd;
	double value;
};


//Operator item
class OperatorItem : public Item
{
public:
	void Display() const;

protected:
	std::string symbol;
};


#endif /* ITEM_H_ */
