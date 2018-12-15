//
// Created by Baoli Chen on 10/23/2018.
//

#include "NiceList.h"

template<class ItemType>
void NiceList<ItemType>::setName(string aName)
{
    name = aName;
}

template<class ItemType>
void NiceList<ItemType>::addGift(ItemType aGift)
{
    gifts.push_back(aGift);
}

template<class ItemType>
string NiceList<ItemType>::getName() const
{
    return name;
}

template<class ItemType>
string NiceList<ItemType>::giftsToString(string split)
{
    string result;

    for (typename list<ItemType>::iterator i = gifts.begin(); i != gifts.end(); i++)
    {
        if (!result.empty())
            result += split;
        result += ItemType(*i);
    }

    return result;
}