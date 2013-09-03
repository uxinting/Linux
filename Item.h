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
#define PRECD_LEFTP -999
#define PRECD_ADD 1
#define PRECD_MINUS 1
#define PRECD_MULTI 2
#define PRECD_DIV	2
#define PRECD_SIN 3
#define PRECD_COS 3
#define PRECD_TAN 3
#define PRECD_COT 3
#define PRECD_LN 3
#define PRECD_LG 3
#define PRECD_ARCSIN 3
#define PRECD_ARCCOS 3
#define PRECD_ARCTAN 3
#define PRECD_ARCCOT 3

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

#define OPERATOR_CLASS(prefix) \
class prefix##OperatorItem : public OperatorItem \
{ \
public:\
	prefix##OperatorItem();\
	double Exec(std::stack<Item*>*);\
	DECLAR_OPERATOR(prefix##OperatorItem) \
};

#define REGISTER_OPERATOR(optorName, className) \
	OperatorItem* className::CreateOperatorItem() { \
		return new className; } \
	/*static std::string _szOperatorName = #optorName;*/ \
	RuntimeItem className::optor##className = { \
		#optorName, className::CreateOperatorItem }; \
	static ITEM_INIT _init_##className(&className::optor##className); \
	RuntimeItem* className::GetRuntimeItem() const { \
		return &className::optor##className; }

#define IMPLEMENT_OPERATOR(prefix, s, PRECD) \
REGISTER_OPERATOR(s, prefix##OperatorItem) \
prefix##OperatorItem::prefix##OperatorItem() {\
	symbol = #s; \
	precd = PRECD; \
}
#endif /* ITEM_H_ */
