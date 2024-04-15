#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.

/*
 * insert()
 *
 * This function inserts/adds an item to the bead bag, only if not already inserted or present
 *
 * input: Item to insert
 * output: returns nothing
 */
void BeadedBag::insert(Item to_insert) {
	if (!this->contains(to_insert)) {
		this->bag.push_back(to_insert);
	}
}

/*
 * size()
 *
 * This function calculated the number of items in the bead bag
 *
 * input: nothing
 * output: number of items in bead bag or size of bead bag
 */
int BeadedBag::size() {
	return bag.size();
}

// Complete the implementation of the BeadedBag::contains member function.
/*
 * contains()
 *
 * This function checks if an item(maybe_contained_item) is already in the bag
 *
 * input: Item to check for
 * output: Returns TRUE if item is already in the bag, otherwise returns FALSE
 */
bool BeadedBag::contains(Item maybe_contained_item) {

	for (auto item : bag) {
		if (item.isEqual(maybe_contained_item)) {
			return true;
		}
	}
	return false;

}