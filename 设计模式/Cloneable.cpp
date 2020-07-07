// 基础的原型模式，克隆对象
// 这种模式会出现深拷贝和浅拷贝的问题，问题解决在Cloneable2.cpp中会解决

#include <iostream>

class Monster {
public:
    virtual ~Monster() {}
    virtual Monster* clone() = 0;
};

class Ghost : public Monster {
public:
    Ghost(int hp, int speed) : Monster(), _hp(hp), _speed(speed) {}
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

class Pet : public Monster {
public:
    Pet(int hp, int speed, int type1) : Monster(), _hp(hp), _speed(speed), _type(type1) {}
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

class Generator {
public:
    Generator(Monster* monster) : _monster(monster) {}
    Monster* GetMonster() {
        return _monster->clone();
    }
private:
    Monster* _monster;
};

int main() {
    Monster* ghost = new Ghost(1, 2);
    //ghost->printMe();
    Generator* generator = new Generator(ghost);

    // clone
    Monster* ghost2 = generator->GetMonster();
    Ghost* c = dynamic_cast<Ghost*>(ghost2);
    Ghost* b = (Ghost*)ghost2;
    b->printMe();
    c->printMe();
    return 0;
}
