/*-------------------------------------------------------------------------
                 Implement a class of postfix calculators
                           Created by Baoli Chen.
 -------------------------------------------------------------------------*/
#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

// Function prototype
int postfixCalculator(string expression);
int calculator(int first, int second, char op);

/************************************************************************
*                                 main                                  *
************************************************************************/
int main()
{
    bool done = false; // A finish flag
    string expression;
    char choice;
    int result;

    cout << "=========================================================\n"
        << " This program require you to enter postfix expressions. \n"
        << "     eg. If you enter: 234+* \n"
        << "           the result: 14 \n"
        <<"=========================================================\n";

    while (!done)
    {
        cout << "\nPlease enter a postfix expression: ";
        getline(cin, expression);

        try
        {
            result = postfixCalculator(expression);
            cout << "The result of \""<< expression << "\": " << result << endl;
            cout << "\nDo you want to try another postfix expression? (Y/N): ";
            cin >> choice;
            cin.ignore();
            done = tolower(choice) != 'y';
        }
        catch (exception& e)
        {
            cout << "ERROR: " << expression << " is not a correct postfix expressions! \n"
                 << "Sorry, please try again! \n";
        }
    }

    cout << "\n~~~~~~~~~~~~\n"
        << " Thank you! \n"
        << "~~~~~~~~~~~~\n";

    return 0;
}

/****************************************************
*                 postfixCalculator                 *
****************************************************/
int postfixCalculator(string expression)
{
    int result = -1;

    int i = 0, size = int(expression.length());
    string operators = "+-*/";
    int operand1, operand2;
    stack<int> numbStack;

    for (; i < size; i++)
    {
        if (isdigit(expression[i]))
            numbStack.push(expression[i] - '0');
        else if (operators.find(expression[i]) != -1)
        {
            if (numbStack.size() > 1)
            {
                operand1 = numbStack.top();
                numbStack.pop();
                operand2 = numbStack.top();
                numbStack.pop();

                numbStack.push(calculator(operand2, operand1, expression[i]));
            }
            else
            {
                i--;
                break;
            }
        }
    }

    if (numbStack.size() == 1 && i == size)
    {
        result = numbStack.top();
        numbStack.pop();
    }
    else
        runtime_error("bad_exception");

    return result;
}

/****************************************************
*                     calculator                    *
****************************************************/
int calculator(int first, int second, char op)
{
    switch (op)
    {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        case '/': return first / second;
        default: return 0;
    }
}
