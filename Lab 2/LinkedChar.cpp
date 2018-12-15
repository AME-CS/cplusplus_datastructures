//
// Created by Baoli Chen on 9/20/2018.
//

#include "LinkedChar.h"
#include "Node.h"

template<class ItemType>
LinkedChar<ItemType>::LinkedChar() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedChar<ItemType>::LinkedChar(string items)
{
    itemCount = int(items.size());

    headPtr = nullptr;

    for (int i = itemCount - 1; i >= 0; i--)
    {
        if (headPtr == nullptr)
        {
            // Copy first node
            headPtr = new Node<ItemType>();
            headPtr->setItem(items[i]);
        } else {
            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(items[i]);
            newNodePtr->setNext(headPtr);  // New node points to chain

            headPtr = newNodePtr;          // New node is now first node
        }
    }
}

template<class ItemType>
LinkedChar<ItemType>::~LinkedChar()
{
    clear();
}  // end destructor

template<class ItemType>
int LinkedChar<ItemType>::length() const
{
    return itemCount;
}  // end length

template<class ItemType>
int LinkedChar<ItemType>::index(const ItemType& anItem) const
{
    int index = 0;
    Node<ItemType>* curPtr = headPtr;

    while (curPtr != nullptr)
    {
        if (anItem == curPtr->getItem())
        {
            return index;

        } // end if
        index++;
        curPtr = curPtr->getNext();
    }
    return -1;
}  // end index

template<class ItemType>
void LinkedChar<ItemType>::append(const LinkedChar &lc)
{
    itemCount += lc.length();
    Node<ItemType>* newChainPtr = headPtr;
    while (newChainPtr != nullptr && newChainPtr->getNext() != nullptr)
    {
        newChainPtr = newChainPtr->getNext();
    }

    Node<ItemType>* origChainPtr = lc.headPtr;
    while (origChainPtr != nullptr)
    {
        // Get next item from original chain
        ItemType nextItem = origChainPtr->getItem();

        // Create a new node containing the next item
        Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

        // Link new node to end of new chain
        newChainPtr->setNext(newNodePtr);

        // Advance pointer to new last node
        newChainPtr = newChainPtr->getNext();

        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
}  // end append

template<class ItemType>
bool LinkedChar<ItemType>::submatch(const LinkedChar &lc) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* origChainPtr = lc.headPtr;

    ItemType anItem;

    while (origChainPtr != nullptr && curPtr != nullptr)
    {
        anItem = origChainPtr->getItem();

        while (curPtr != nullptr)
        {
            if (anItem == curPtr->getItem())
            {
                found = true;
                curPtr = curPtr->getNext();
                break;
            }
            else if (found)
            {
                found = false;
                break;
            }

            curPtr = curPtr->getNext();
        }
        if (!found)
            origChainPtr = lc.headPtr;
        else
            origChainPtr = origChainPtr->getNext();
    }

    return found && (origChainPtr == nullptr);

//    string currentString = this->toString();
//    string originalString = lc.toString();
//
//    return currentString.find(originalString) != -1;
}  // end submatch

template<class ItemType>
void LinkedChar<ItemType>::clear()
{
    Node<ItemType>* curPtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        curPtr->setNext(nullptr);
        delete curPtr;

        curPtr = headPtr;
    }

    itemCount = 0;
}  // end clear

template<class ItemType>
string LinkedChar<ItemType>::toString() const
{
    std::string aString;
    Node<ItemType>* curPtr = headPtr;

    while ((curPtr != nullptr))
    {
        aString += (curPtr->getItem());
        curPtr = curPtr->getNext();
    }

    return aString;
}  // end toString