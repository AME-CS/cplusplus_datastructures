/*-------------------------------------------------------------------------
                    Implement the class LinkedSortedList
                           Created by Baoli Chen.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <random>
#include "SortedListInterface.h"
#include "LinkedSortedList.h"

// Function prototype
void displayList(const shared_ptr<SortedListInterface<int>>& listPtr);

/************************************************************************
*                                 main                                  *
************************************************************************/
int main()
{
    // generate a number from 1-100 use the STL random library
    // For repeated uses, both are bound together
    auto dice = bind(uniform_int_distribution<int>{1, 100},
                     default_random_engine{random_device()()});

    const int LIST_SIZE = 21;
    shared_ptr<SortedListInterface<int>> listPtr = make_shared<LinkedSortedList<int>>();
    int number = 0, position;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (i == 0)
            cout << "The numbers that will be inserted: \n";
        else
            cout << ", ";

        // generates number in the range 1..100
        number = dice();
        cout << number;
        // insert 21 random numbers (1-100) on the sorted list.
        listPtr->insertSorted(number);
    }

    cout << "\n\n";
    // display all inserted numbers.
    displayList(listPtr);

    if (number > 0)
    {
        position = listPtr->getPosition(number);

        listPtr->remove(position);
    }

    // display the sorted list.
    displayList(listPtr);

    return 0;
}

/************************************************************************
*                             displayList                               *
************************************************************************/
void displayList(const shared_ptr<SortedListInterface<int>>& listPtr)
{
    cout << "The linked sorted list contains " << endl;

    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        if (pos > 1)
            cout << ", ";
        cout << listPtr->getEntry(pos);
    }

    cout << "\n\n";
}