#include <iostream>
#include <vector>
#include <list>

template <typename Type>
std::vector<Type> replacingOddEven(std::vector<Type>&vector, std::list<Type>&list)
{
    std::vector <int> result;
    std::vector<int> storingEven; // a vector to store all the collected even values from list

    std::vector<int>::iterator it; // an iterator for a vector
    std::list<int>::iterator itl; // an iterator for a vector

    for (itl = list.begin(); itl != list.end(); ++itl) { // storing all even values
        if (*itl % 2 == 0) storingEven.push_back(*itl);
    }

    for (it = vector.begin(); it != vector.end(); ++it) {
        if (*it % 2 == 0) result.push_back(*it);
        else {
            result.push_back(storingEven.back());
            storingEven.pop_back();
        }
    }

    return result;
}


void task5()
{
    // sizes of the list and vector
    int sizeList = 0;
    int sizeVector = 0;

    std::cout<<"Enter the size of your list: "<<std::endl;
    std::cin>>sizeList;

    std::cout<<"Enter the size of your vector: "<<std::endl;
    std::cin>>sizeVector;


    // initializing a list and a vector with the given sizes and filling them with the customary elements
    std::list <int> list_of_digits;
    std::vector <int> vector_of_digits;

    int elem = 0;

    for (int i = 0; i < sizeList; ++i) //   filling in the list
    {
        std::cin>>elem;
        list_of_digits.push_back(elem);
    }

    for (int i = 0; i < sizeVector; ++i) //   filling in the vector
    {
        std::cin>>elem;
        vector_of_digits.push_back(elem);
    }

    // creating a new vector (result)
    std::vector <int> resultingVector = replacingOddEven(vector_of_digits, list_of_digits);

    // printing out the input and the resulted vector
    std::vector<int>::iterator it;
    std::list<int>::iterator itl;

    std::cout<<"The given vector is: "<<std::endl;
    for (it = vector_of_digits.begin(); it != vector_of_digits.end(); it++) {
        std::cout<<*it<<" ";
    }

    std::cout<<"\n";

    std::cout<<"The given list is: "<<std::endl;
    for (itl = list_of_digits.begin(); itl != list_of_digits.end(); itl++) {
        std::cout<<*itl<<" ";
    }

    std::cout<<"\n";
    std::cout<<"The resulted vector is: "<<std::endl;
    for (it = resultingVector.begin(); it != resultingVector.end(); it++) {
        std::cout<<*it<<" ";
    }
}