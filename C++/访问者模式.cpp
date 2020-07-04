#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct Cat;
struct Dog;
struct People;

struct Animal {
	struct Ivisitor {
		virtual void visitor(Cat *) = 0;
		virtual void visitor(Dog *) = 0;
		virtual void visitor(People *) = 0;
	};
	Animal(string name) : name(name) {}
	virtual void say() = 0;
	virtual void Accept(Ivisitor *vis) = 0;
	virtual ~Animal(){}
	string name;
	int age;
};

struct Cat : Animal {
	Cat() : Animal("cat") {
		this->age = rand() % 100;
	}
	void say() {
		cout << "miao miao miao" << endl;
	}
	void Accept(Ivisitor *vis) {
		vis->visitor(this);
	}
};

struct Dog : Animal {
	Dog() : Animal("dog") {
		this->age = rand() % 100;
	}
	void say() {
		cout << "wang wang wang" << endl;
	}
	void Accept(Ivisitor *vis) {
		vis->visitor(this);
	}
};

struct People : Animal {
	People() : Animal("People") {
		this->age = rand() % 100;
	}
	void say() {
		cout << "ren" << endl;
	}
	void Accept(Ivisitor *vis) {
		vis->visitor(this);
	}
};

struct OutputVisitor : Animal::Ivisitor {
	void visitor(Cat *a) {
		cout << "this is a cat " << a->age << endl;
	}
	void visitor(Dog *b) {
		cout << "this is a dog " << b->age << endl;
	}
	void visitor(People *c) {
		cout << "this is a People " << c->age << endl;
	}
};

struct ageVisitor : Animal::Ivisitor {
	void visitor(Cat *a) {
		this->age = a->age - 2;
	}
	void visitor(Dog *b) {
		this->age = b->age * 2;
	}
	void visitor(People *c) {
		this->age = c->age - 10;
	}
	int age;
};

Animal *genCat() {
	return new Cat;
}

Animal *genDog() {
	return new Dog;
}

Animal *genPeople() {
	return new People;
}

int main() {
	srand(time(0));
	Animal *arr[10];
	Animal *(*func_arr[3])() = {
		genCat, genDog, genPeople
	};
	for (int i = 0; i < 10; i++) {
		int x = rand() % 3;
		arr[i] = func_arr[x]();
	}
	/*for (int i = 0; i < 10; i++) {
		Cat *a = dynamic_cast<Cat *>(arr[i]);
		Dog *b = dynamic_cast<Dog *>(arr[i]);
		People *c = dynamic_cast<People *>(arr[i]);
		arr[i]->say();
		if (a) {

		} else if (b) {

		} else {

		}
	}*/
	for (int i = 0; i < 10; i++) {
		OutputVisitor ov;
		ageVisitor ok;
		arr[i]->Accept(&ov);
		arr[i]->Accept(&ok);
		cout << ok.age << endl;
	}
	/*for (int i = 0; i < 10; i++) {
		cout << "This is a " << arr[i]->name << endl;
	}*/
	return 0;
}