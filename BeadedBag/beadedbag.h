#ifndef __BEADEDBAG_BEADEDBAG_HPP
#define __BEADEDBAG_BEADEDBAG_HPP

#include "item.h"
#include <vector>

class BeadedBag {
public:

	/*
	 * insert()
	 *
	 * This function inserts an item into the bead bad, only if it is not already inserted
	 *
	 * input: Item to insert	
	 * output: returns nothing
	 */
	void insert(Item  to_insert);

	/*
	 * size()
	 *
	 * Provides the number of items in bead bag
	 *
	 * input: Nothing
	 * output: returns the number of items in bead bag
	 */
	int size();

	// Here's the declaration for contains, to get you started:
	bool contains(Item maybe_contained_item);

// Vector storing items in bead bag
private:
	std::vector<Item> bag;
};

#endif