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
#include <map>
#include <iostream>

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

	virtual bool operator > (Item& item) const;
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
struct RuntimeItem;
class OperatorItem : public Item
{
public:
	void Display() const;

	virtual RuntimeItem* GetRuntimeItem() const;
	int Precedence() const;
public:
	static RuntimeItem optorOperatorItem;
protected:
	int precd;
	std::string symbol;
};

//dynamic creation of operator item

struct RuntimeItem {
	std::string m_szOperatorName;
	OperatorItem* (*m_pfnCreateItem)();

	static RuntimeItem* pFirstItem;
	RuntimeItem* m_pNextItem;
};

struct ITEM_INIT {
	ITEM_INIT(struct RuntimeItem* pNewItem);
};

#define DECLAR_OPERATOR(className) \
	public: \
		static RuntimeItem optor##className; \
		virtual RuntimeItem* GetRuntimeItem() const; \
		static OperatorItem* CreateOperatorItem();

#define REGISTER_OPERATOR(optorName, className) \
	OperatorItem* className::CreateOperatorItem() { \
		return new className; } \
	static std::string _szOperatorName = #optorName; \
	RuntimeItem className::optor##className = { \
		_szOperatorName, className::CreateOperatorItem }; \
	static ITEM_INIT _init_##className(&className::optor##className); \
	RuntimeItem* className::GetRuntimeItem() const { \
		return &className::optor##className; }

#endif /* ITEM_H_ */
