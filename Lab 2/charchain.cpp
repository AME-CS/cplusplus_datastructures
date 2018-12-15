/*-------------------------------------------------------------------------
  Implement an ADT character string by using a linked chain of characters
                           Created by Baoli Chen.
 -------------------------------------------------------------------------*/
#include <iomanip>
#include "LinkedChar.h"

// Function prototype
bool isCreated(const LinkedChar<char>* charPtr);
LinkedChar<char> toLinkedChar(const string &items);

/************************************************************************
*                                 main                                  *
************************************************************************/
int main()
{
    bool done = false; // A finish flag
    int choice; // Menu choice
	
    cout << " This program solves an ADT character string.  \n";

    LinkedChar<char>* charPtr = nullptr;
    string firstString;
    char aChar;
	
    while (!done)
    {
		// Display the menu and get the user's choice
        cout << "=========================================================\n"
		    << "Operations\n\n";
        cout << setw(5) << "1. New the first string\n";
        cout << setw(5) << "2. Get the length from the first string\n";
        cout << setw(5) << "3. Find index of character in the first string\n";
        cout << setw(5) << "4. Append another string to the first string\n";
        cout << setw(5) << "5. Test if another string is submatch of the first string\n";
        cout << setw(5) << "6. Quit\n"
		    <<"=========================================================\n\n";
        cout << "Enter your Choice (1-6): ";
        cin >> choice;
        cin.ignore();

		// Validate and process the menu choice
        if (choice == 1)
        {
            cout << "Please enter a string: ";
            getline(cin, firstString);

            charPtr = new LinkedChar<char>(firstString);
            cout << "The first string has been created. \n\n";
        }
        else if (choice == 6)
        {
            // Set the program is finished
            done = true;
        }
        else if (choice > 1 && choice < 6)
        {
            if (isCreated(charPtr))
                // Execute the correct set of actions
                switch (choice)
                {
                    case 2:
                        cout << "The length of the first string \"" <<  charPtr->toString() << "\" is " << charPtr->length() << ".\n\n";
                        break;
                    case 3:
                        cout << "Please enter a character to find: ";
                        cin >> aChar;
                        cout << "The index of \"" << aChar << "\" is " << charPtr->index(aChar) << "\n\n";
                        break;
                    case 4:
                        cout << "Please enter another string to append: ";
                        getline(cin, firstString);
                        charPtr->append(toLinkedChar(firstString));
                        cout << "The string changes to \"" << charPtr->toString() << "\".\n\n";

                        break;
                    case 5:
                        cout << "Please enter another string to test: ";
                        getline(cin, firstString);
                        cout << "The string \"" << firstString << "\" is ";
                        if (!charPtr->submatch(toLinkedChar(firstString)))
                            cout << "not ";
                        cout << "submatch of the first string \"" << charPtr->toString() << "\".\n\n";
                        break;
                }
	    }
        else
        {
            cout << "The valid choices are 1 through 6.\n\n";
        }
    }
	
    return 0;
}

bool isCreated(const LinkedChar<char>* charPtr)
{
    if (charPtr == nullptr)
    {
        std::cout << "Please choose 1 to create the first string before start!\n\n";
        return false;
    }
    else
    {
        return true;
    }
}

LinkedChar<char> toLinkedChar(const string &items)
{
    return LinkedChar<char>(items);
}