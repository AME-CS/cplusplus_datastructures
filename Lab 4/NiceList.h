//
// Created by Baoli Chen on 10/23/2018.
//

#ifndef NICELIST_H
#define NICELIST_H

#include <list>
#include "ListInterface.h"

template<class ItemType>
class NiceList : public ListInterface<ItemType>
{
private:
    string name;
    list<ItemType> gifts;
public:
    void setName(string aName);

    void addGift(ItemType aGift);

    string getName() const;
    string giftsToString(string split = ",");
};

#include "NiceList.cpp"

#endif //NICELIST_H
