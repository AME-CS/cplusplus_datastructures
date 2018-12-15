/*-------------------------------------------------------------------------
                         Implement a nice gift list
                           Created by Baoli Chen.
 -------------------------------------------------------------------------*/
#include <iostream>
#include "NiceList.h"

/************************************************************************
*                                 main                                  *
************************************************************************/
int main()
{
    list<NiceList<string>> lists;
    string listName, giftName;

    cout << "name for nice list: ";
    getline(cin, listName);

    while (!listName.empty())
    {
        NiceList<string> niceList;
        niceList.setName(listName);

        cout << "add gifts for " << listName << endl;

        do {
            cout << "gift: ";
            getline(cin, giftName);
            niceList.addGift(giftName);
        } while (!giftName.empty());

        lists.push_back(niceList);

        cout << "name for nice list: ";
        getline(cin, listName);
    }

    cout << "The list contains" << endl;
    for (auto aList: lists)
        cout << aList.getName() << "  " << aList.giftsToString(" ") << endl;

    return 0;
}