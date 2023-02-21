#include <iostream>
#include <list>
#include <vector>

template<typename T>
std::list<T> alternate_pairs(const std::vector<T>& vec, const std::list<T>& lst) {
    std::list<T> result;
    auto vec_iter = vec.rbegin();
    for (auto lst_iter = lst.begin(); lst_iter != lst.end(); ++lst_iter) {
        result.push_back(*lst_iter);
        if (vec_iter != vec.rend()) {
            result.push_back(*vec_iter);
            ++vec_iter;
        }
    }
    while (vec_iter != vec.rend()) { // add remaining elements in vector
        result.push_back(*vec_iter);
        ++vec_iter;
    }
    return result;
}

void task6() {
    std::vector<int> vec = {1, 2, 3};
    std::list<int> lst = {4, 5, 6, 7, 8};
    std::cout << "Original data: " << std::endl;
    std::cout << "Vector: ";
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "List (forward order): ";
    for (auto i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "List (reverse order): ";
    for (auto i = lst.rbegin(); i != lst.rend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::list<int> result = alternate_pairs(vec, lst);
    std::cout << "Result: ";
    for (auto i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}