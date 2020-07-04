/*************************************************************************
	> File Name: 继承.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 14时34分46秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Animal {
    Animal(string name) {
        cout << "father" << endl;
    }
    string name() {
        return this->__name;
    }
    void set_name(string name) {
        this->__name = name;
    }
private :
    string __name;

};

struct Bat : public Animal {
public :
    Bat() : Animal("bat"){
        cout << "son" << endl;
    }

};

template<typename T>
class Array {
public :
    Array(int n) : n(n) {
        this->data = new T[n];
    }
    T &operator[](int index) {
        if (index < 0 || index >= this->n) return this->temp;
        return this->data[index];
    }
    void output() {
        for (int i = 0; i < this->n; i++) {
            cout << this->data[i] << endl;
        }
    }
    Array<T> &operator=(Array<T> &a) {
        delete[] this->data;
        this->n = a.n;
        this->data = new T[this->n];
        for (int i = 0; i < n; i++) {
            this->data[i] = a.data[i];
        }
        return *this;
    }
    ~Array() {
        this->n = 0;
        delete[] this->data;
    }
private : 
    int n;
    T *data, temp;
};

ostream &operator<<(ostream &out, Bat &a) {
    out << "bat : " << a.name();
    return out;
}

int main() {
    /*Bat a;
    string pp;
    cout << sizeof(pp) << endl;
    cout << sizeof(Animal) << endl;
    cout << sizeof(Bat) << endl;*/
    /*Array<int> arr(10);
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    arr.output();*/
    Array<Bat> arr(10);
    arr.output(); //多出的两行是temp的构造过程
    Array<Bat> brr(10);
    brr = arr;
    brr[7].set_name("qqq");
    arr.output();
    brr.output();
    return 0;
}
