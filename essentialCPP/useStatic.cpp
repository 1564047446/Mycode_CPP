#include <iostream>
#include <vector>

// 局部static 的用法
const std::vector<int>* getVector(int size) {
    static std::vector<int> arr;
    
    for (int i = arr.size(); i < size; i++) {
        arr.push_back(i + 100);
    }
    
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
    return &arr;
}

// 类中static的用法
class Shape
{

priavte:

};
int main() {
    
    
    const std::vector<int>* arr = getVector(10);
    const std::vector<int>* brr = getVector(30);
    return 0;
}
