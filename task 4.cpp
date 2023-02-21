#include <iostream>
#include <list>
#include <vector>

template<typename T>
std::vector<T> print_even(std::list<T>&lst)
{
    std::vector<int> even_vec;
    for (int num : lst) {
        if (num % 2 == 0) {
            even_vec.push_back(num);
        }
    }
    std::cout << "Even elements: ";
    for (int num : even_vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return even_vec;
}

void task4() {

    int lenOfList = 0;
    std::cout << "Enter the size of your list: ";
    std::cin >> lenOfList;
    std::list<int> lst;
    int input = 0;
    std::cout << "Enter element: ";
    for (int i = 0; i < lenOfList; i++) {
        std::cin >> input;
        if (input != 0) {
            lst.push_back(input);
        }
    }
    print_even(lst);
}
