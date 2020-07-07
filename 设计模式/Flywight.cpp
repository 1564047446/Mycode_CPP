// 享元模式
// 运用共享技术幼小的持之大量的细粒度的对象
// 主要用于减少创建对象的数量，以尖山内存占用和提高性能

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <atomic>
#include <map>

using namespace std;

class Shape {
private:
    int key;
public:
    Shape(const int& keys) : key(keys) {}
};

// 目前游戏服务器这种模式运用比较多
class FlyWightFactory {
public:
    Shape* getShape(int key);
    map<int, Shape*> shapemap;
};

Shape* FlyWightFactory::getShape(int key) {
    auto it = shapemap.find(key);
    if (it != shapemap.end()) {
        return it->second;
    } else {
        Shape* shape = new Shape(key);
        shapemap.insert(make_pair(key, shape));
        return shape;
    }
}

int main() {
    return 0;
}