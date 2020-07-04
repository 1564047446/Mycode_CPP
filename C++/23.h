#ifndef _23_H
#define _23_H
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
 
namespace haizei {
 
template<typename T> struct Hash;
template<> struct Hash<int> {
    int operator()(int a) {
        return a & 0x7fffffff;
    }
};
template<> struct Hash<double> {
    int operator()(double a) {
        return static_cast<int>(a) & 0x7fffffff;
    }
};
template<> struct Hash<string> {
    int operator()(const string &s) {
        int hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = (hash << 5) ^ s[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
};
 
template<typename KEY_T, typename VALUE_T, typename HashFunc_T = Hash<KEY_T> >
class HashTable {
public :
    HashTable(int size = 100) : __size(size) {
        this->__data = new pair<KEY_T, VALUE_T>[this->__size];
        this->__map = new bool[this->__size]{0};
    }
    ~HashTable() {
        delete[] this->__data;
        delete[] this->__map;
    }
    VALUE_T &operator[](const KEY_T &key) {
        int index;
        VALUE_T *temp = this->find(key, &index);
        if (temp == this->end() && index == -1) return this->__end;
        if (this->__map[index] == 0) {
            this->__data[index].first = key;
            this->__map[index] = true;
        }
        return this->__data[index].second;
    }
    VALUE_T *end() {return &(this->__end);}
    VALUE_T *find(const KEY_T &key, int *_index = nullptr) {
        int hash_code = this->__hash_func(key);
        int index = hash_code % this->__size;
        int times = 1;
        while (this->__map[index] && this->__data[index].first != key) {
            index += (times * times);
            index %= this->__size;
            times++;
            if (times == this->__size) {
                if (_index != nullptr) {
                    *_index = -1;
                }
                return this->end();
            }
        }
        if (_index != nullptr) {
            *_index = index;
        }
        if (this->__map[index] == 0) return this->end();
        return &(this->__data[index].second);
    }
    
private :
    int __size;
    pair<KEY_T, VALUE_T> *__data;
    bool *__map;
    HashFunc_T __hash_func;
    VALUE_T __end;
};
} // end of haizei
#endif
