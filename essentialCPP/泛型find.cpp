#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template<typename T> 
const T* find(const T* first, const T* last, T value) {
    if (!first || !last) return nullptr;

    while (first != last) {
        if (*first == value) return first;
        ++first;
    }

    return nullptr;
}

template<
    typename inputIter, typename outputIter, typename cmpType, typename valueType 
>
outputIter getArr(inputIter first, inputIter last, outputIter beginn, const valueType& value, cmpType cmpT) {

    while ((first = std::find_if(first, last, bind(cmpT, *first, value))) != last) {
        std::cout << *first << std:: endl;
        *beginn++ = *first++;
    }

    return beginn;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int brr[5];

    getArr(arr, arr + 5, brr, 3, std::less<int>());
    for (auto x : brr)
    {
        std::cout << "brr:" << x << std::endl;
    }
    
    return 0;
}
