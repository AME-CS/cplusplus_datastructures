//
// Created by Baoli Chen on 9/20/2018.
//
#ifndef LINKEDCHAR_H
#define LINKEDCHAR_H

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

template<class ItemType>
class LinkedChar
{
private:
    Node<ItemType>* headPtr;
    int itemCount;
public:
    LinkedChar();
    LinkedChar(string items);
    virtual ~LinkedChar();

    int length() const;
    int index(const ItemType& anItem) const; // -1 if no match
    void append(const LinkedChar& lc);
    bool submatch(const LinkedChar& lc) const;
    void clear();

    string toString() const;
};

#include "LinkedChar.cpp"
#endif //LINKEDCHAR_H
