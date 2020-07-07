// 生成器函数

#include <iostream>

class Monster {
public:
    virtual ~Monster() {}
    virtual Monster* clone() = 0;
};

class Ghost : public Monster {
public:
    Ghost(int hp, int speed) : Monster(), _hp(hp), _speed(speed) {}
    Ghost() {}
    virtual Monster* clone() override {
        return new Ghost(_hp, _speed);
    }

    void printMe() {
        std::cout << "ghost" << std::endl;
        std::cout << "hp:"<< _hp << std::endl;
    }
private:
    int _hp;
    int _speed;
};

Monster* CreateGhost() {
    return new Ghost();
}

class Pet : public Monster {
public:
    Pet(int hp, int speed, int type1) : Monster(), _hp(hp), _speed(speed), _type(type1) {}
    Pet() {}

    virtual Monster* clone() override {
        return new Pet(_hp, _speed, _type);
    }

    void printMe() {
        std::cout << "pet" << std::endl;
    }
private:
    int _hp;
    int _speed;
    int _type;
};

Monster* CreatePet() {
    return new Pet();
}

// 定义函数会更简洁
typedef Monster* (*CreateFunc)();

class Generator {
public:
    Generator(CreateFunc func) : _func(func) {}
    Monster* GetItem() {
        return _func();
    }
private:
    CreateFunc _func;
};

// 模板方式获取
class Generator2 {
public:
    Generator2() {}
    virtual Monster* getMonster() = 0;
};

template<typename T>
class Creator : public Generator2 {
public:
    Creator() {}
    virtual Monster* getMonster() override {
        return new T();
    }
};

int main() {
    Generator* generator = new Generator(CreateGhost);
    Monster* ghost = generator->GetItem();
    Ghost* ghost2 = dynamic_cast<Ghost*>(ghost);
    ghost2->printMe();
    
    Generator2* gen = new Creator<Pet>();
    Creator<Pet>* creator = dynamic_cast<Creator<Pet>*>(gen);
    Monster* pet = creator->getMonster();
    Pet* pet2 = dynamic_cast<Pet*>(pet);
    pet2->printMe();
    return 0;
}