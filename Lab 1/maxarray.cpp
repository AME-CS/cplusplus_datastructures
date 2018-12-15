/*-------------------------------------------------------------------------
                      Implement the algorithm maxArray
                           Created by Baoli Chen.
 -------------------------------------------------------------------------*/
#include <iostream>

// Function prototype
template <class ElementType>
void display(const ElementType array[], int numElements);

template <class ElementType>
ElementType maxArray(const ElementType array[], int begin, int end);

/************************************************************************
*                                 main                                  *
************************************************************************/
int main()
{
    std::cout << "=================================================\n"
              << "This program solves an array to find a max value.\n"
              <<"=================================================\n";

    std::cout << "The first array:\n";
    double firstArray[] = {1.33, 2.44, 3.55, 0.44};
    display(firstArray, 4);
    std::cout << "  The max value is " << maxArray(firstArray, 0, 3) << "\n\n";

    std::cout << "The second array:\n";
    int secondArray[] = {9, 1000, 5, 9999, 2};
    display(secondArray, 5);
    std::cout << "  The max value is " << maxArray(secondArray, 0, 4) << "\n\n";

    std::cout << "The third array:\n";
    char thirdArray[] = {'a', 'Z', '#', '8', '!', '{'};
    display(thirdArray, 6);
    std::cout << "  The max value is " << maxArray(thirdArray, 0, 5) << "\n\n";

    std::cout << "The fourth array:\n";
    std::string fourthArray[] = {"abc", "123", "ddd"};
    display(fourthArray, 3);
    std::cout << "  The max value is " << maxArray(fourthArray, 0, 2) << "\n";
	
    return 0;
}

/************************************************************************
*                               display                                 *
************************************************************************/
template <class ElementType>
void display(const ElementType array[], int numElements)
{
    for (int i = 0; i < numElements; i++)
        std::cout << "\t" << array[i] << "\t";

    if (numElements > 0)
        std::cout << std::endl;
}

/************************************************************************
*                               maxArray                                *
************************************************************************/
template <class ElementType>
ElementType maxArray(const ElementType array[], int begin, int end)
{
    if (end == begin)
        return array[begin];
		
    int mid = begin + (end - begin) / 2;
    ElementType maxLeft = maxArray(array, begin, mid);
    ElementType maxRight = maxArray(array, mid + 1, end);
	
    return maxLeft > maxRight ? maxLeft : maxRight;
}