/*
 * OperatorFactory.cpp
 *
 *  Created on: 2013年8月12日
 *      Author: xinting
 */

#include "OperatorFactory.h"

OperatorFactory::OperatorFactory() {}

OperatorFactory::~OperatorFactory() {
	std::map<std::string, OperatorItem*>::const_iterator map_it = items.begin();

	while (map_it != items.end()) {
		delete map_it->second;
		map_it++;
	}
}

OperatorItem* OperatorFactory::GetOperatorItem(std::string s) {
	OperatorItem* item;
	if (items.count(s) == 0) {
		item = items[s] = CreateOperatorItem(s);
	} else {
		item = items[s];
	}
	return item;
}


OperatorItem* OperatorFactory::CreateOperatorItem(std::string s) {
	RuntimeItem* pFirst = RuntimeItem::pFirstItem;
	while (pFirst) {
		if (pFirst->m_szOperatorName == s) {
			return pFirst->m_pfnCreateItem();
		}
		pFirst = pFirst->m_pNextItem;
	}

	return null;
}


