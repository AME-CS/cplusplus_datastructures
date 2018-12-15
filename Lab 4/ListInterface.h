//
// Created by Baoli Chen on 10/23/2018.
//

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include <string>

using namespace std;

template<class ItemType>
class ListInterface
{
public:
    virtual void setName(string aName) = 0;
    virtual void addGift(ItemType aGift) = 0;

    /** Gets the current name of this list.
    @return The string name of the list. */
    virtual string getName() const = 0;
    virtual string giftsToString(string split) = 0;
};

#endif //LISTINTERFACE_H
