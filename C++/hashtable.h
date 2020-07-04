/*************************************************************************
	> File Name: hashtable.h
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月13日 星期五 14时25分40秒
 ************************************************************************/

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

typedef int (*HashFuncRaw)(const void *value);

class HashFunc {
public :
    //virtual int hash(const void *value) = 0;
    virtual int operator()(const void *value) = 0;
    virtual ~HashFunc() {}
};

class HashTable {
public :
    HashTable(HashFunc &hc) : __hc(&hc), __hcr(nullptr) {}
    HashTable(HashFuncRaw hc) : __hcr(hc), __hc(nullptr) {}
    int get_hash(const void *data) {
        if (this->__hc) {
            return (*(this->__hc))(data);
        } else {
            return this->__hcr(data);
        }
    }

private :
    HashFunc *__hc;
    HashFuncRaw __hcr;
};

#endif
