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

/*

类的静态成员函数是属于整个类而非类的对象，所以它没有this指针，这就导致 了它仅能访问类的静态数据和静态成员函数
不能将静态成员函数定义为虚函数。
static并没有增加程序的时空开销，相反她还缩短了子类对父类静态成员的访问 时间，节省了子类的内存空间。      
静态数据成员是静态存储的，所以必须对它进行初始化

初始化在类体外进行，而前面不加static，以免与一般静态变量或对象相混淆；
初始化时不加该成员的访问权限控制符private，public等；        
初始化时使用作用域运算符来标明它所属类；
           所以我们得出静态数据成员初始化的格式：
<数据类型><类名>::<静态数据成员名>=<值>

为了防止父类的影响，可以在子类定义一个与父类相同的静态变量，以屏蔽父类的影响
*/
class Shape {
public:
    Shape() { }
    Shape(int a, int b) : _a(a), _b(b) { 
        std::cout << "new shape" << std::endl;
    }
    static std::vector<int>* getVector2(int size) {
        static std::vector<int> arr;
    
        for (int i = arr.size(); i < size; i++) {
            arr.push_back(i + 100);
        }
    
        for (int i = 0; i < arr.size(); i++) {
         std::cout << arr[i] << std::endl;
        }
        return &arr;
    }
    void printArr();
    static const std::vector<int>* arr;
private:

    int _a;
    int _b;
};

const std::vector<int>* Shape::arr = Shape::getVector2(10);

void Shape::printArr() {
    for (int i = 0; i < arr->size(); ++i) {
        std::cout << arr->at(i) << std::endl;
    }
}


int main() {    
    const std::vector<int>* arr = getVector(10);
    const std::vector<int>* brr = getVector(30);
    
    //Shape::getArr(10);
    Shape a(1, 2);
    Shape b(2, 3);
    // a b 读的一片内存
    std::cout << "a" << std::endl;
    a.printArr();
    std::cout << "b" << std::endl;
    b.printArr();
    return 0;
}
