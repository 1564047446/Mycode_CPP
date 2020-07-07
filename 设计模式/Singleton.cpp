#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <atomic>

using namespace std;

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton& singleton);
public:
    void say() {
        cout << "hello" << endl;
    }
public:
    static Singleton* instance;
    static atomic<Singleton*> instance2;
    static Singleton* getSingle();
    static mutex m_mutex;
    virtual ~Singleton() {}
};

Singleton* Singleton::instance = nullptr;

//非线程安全
Singleton* Singleton::getSingle() {
    if (nullptr == instance) {
        return new Singleton;
    }
    return instance;
}

// 加锁 锁的代价过高
Singleton* Singleton::getSingle() {
    mutex mt;
    lock_guard<mutex> lck(mt);
    mt.lock();
    if (nullptr == instance) {
        return new Singleton;
    }
    return instance;
}

// 双向加锁， 内存读写reorder不安全
Singleton* Singleton::getSingle() {
    //mt.lock();
    if (nullptr == instance) {
        mutex mt;
        lock_guard<mutex> lck(mt);
        if (nullptr == instance) {
            return new Singleton;
        }
        return new Singleton;
    }
    return new Singleton;
}

// c++ 跨平台实现volatile
atomic<Singleton*> Singleton::instance2;
mutex Singleton::m_mutex;
Singleton* Singleton::getSingle() {
    Singleton* tmp = instance2.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire); // 获取内存fence
    if (nullptr == tmp) {
        lock_guard<mutex> lck(m_mutex);
        tmp = instance2.load(memory_order_relaxed);
        if (nullptr == tmp) {
            tmp = new Singleton;
            atomic_thread_fence(memory_order_release); // 释放内存fence
            instance2.store(tmp, memory_order_relaxed);
        }
    }
    return tmp;
}

int main() {
    Singleton* single;
    single->getSingle();
    single->say();
    delete single;
    return 0;
}