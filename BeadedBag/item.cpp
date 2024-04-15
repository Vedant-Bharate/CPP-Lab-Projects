#include <string>
#include "item.h"

Item::Item(const std::string &item_name): m_name(item_name) {}

std::string Item::getName() {

	return this->m_name;

}

bool Item::isEqual(Item other_item) {

	if (this->m_name == other_item.m_name) {
		return true;
	}

	return false;

}