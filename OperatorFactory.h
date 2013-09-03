/*
 * OperatorFactory.h
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#ifndef OPERATORFACTORY_H_
#define OPERATORFACTORY_H_

#include "items.h"
#include <map>

class OperatorFactory
{
public:
	OperatorFactory();
	OperatorItem* GetOperatorItem(std::string);
	~OperatorFactory();

private:
	OperatorItem* CreateOperatorItem(std::string);
	std::map<std::string, OperatorItem*> items;
};


#endif /* OPERATORFACTORY_H_ */
