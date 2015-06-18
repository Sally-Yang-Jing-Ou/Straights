#ifndef _TABLE_
#define _TABLE_

#include <iostream>
#include <set>
#include <vector>
#include "Card.h"

class Table {
public:
	Table();
	~Table();
	void printTable();
    void placeCard (Card *card);
    void clearTable();
	std::vector<std::vector<Card*>* >* returnArrayOfSets();

private:
	std::vector<std::vector<Card*>* >* arrayOfSets_;
};

#endif

