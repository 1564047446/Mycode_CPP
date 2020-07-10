#include <iostream>
#include <string>
#include <hash_map>
#include <random>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

// 由于c++ 的hash_map 中没有Key 为string的定义，所以我们要自己写一下重载。
/*
    1、系统中有大量对象。 
    2、这些对象消耗大量内存。 
    3、这些对象的状态大部分可以外部化。 
    4、这些对象可以按照内蕴状态分为很多组，当把外蕴对象从对象中剔除出来时，每一组对象都可以用一个对象来代替。 
    5、系统不依赖于这些对象身份，这些对象是不可分辨的。
*/

// 使用场景：1、系统有大量相似对象。 2、需要缓冲池的场景。
namespace __gnu_cxx
{
    template<> 
    struct hash<const string>
    {
        size_t operator()(const string& s) const
        { return hash<const char*>()( s.c_str() ); } //__stl_hash_string
    };

    template<> 
    struct hash<string>
    {
        size_t operator()(const string& s) const
        { return hash<const char*>()( s.c_str() ); }
    };
}

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void setXYR(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
        return ;
    }
    void setColor(string color) {
        this->color = color;
        return ;
    }
    virtual void draw() {
        cout << color << endl;
    }
private:
    string color;
    int x, y, r;
};

class ShapeFactory {
public:
    ShapeFactory() {
    }
    Circle* getCircle(string color) {
        auto iter = hmap.find(color);
        if (iter != hmap.end()) {
            cout << "same color" << endl;
            return iter->second;
        }
        Circle* circle = new Circle();
        circle->setColor(color);
        hmap.insert(make_pair(color, circle));
        cout << "new color" << endl;
        return circle;
    }
private:
    hash_map<string, Circle*> hmap;
};

int main() {
    string makecolor[3] = {"red", "yellow", "blue"};
    default_random_engine e;
    ShapeFactory* sf = new ShapeFactory();
    Shape* cir = new Circle();
    e.seed(10);
    for (int i = 0; i < 10; i++) {
        cir = sf->getCircle(makecolor[e() % 3]);
        cir->draw();
    }
    return 0;
}