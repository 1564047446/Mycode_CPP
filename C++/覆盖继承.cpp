#include <iostream>
#include <string>

using namespace std;

/*struct Animal {
	Animal(string name) : __name(name) {}
	virtual void run() = 0;
	virtual ~Animal() {}
	string __name;
};

struct Cat : Animal {
	Cat() : Animal("cat") {}
	void run() override {
		cout << "I can run with 4 legs" << endl;
	}
};

struct People : Animal {
	People() : Animal("people") {};
	void run() override {
		cout << "I can run with 2 legs" << endl;
	}
};*/

class Animal {
public :
	Animal(string name) : __name(name) {}
	virtual void run() = 0;
	virtual ~Animal() {}
	string __name;
};

class People : public Animal {
public :
	People() : Animal("people") {}
	void run() override {
		cout << "People running" << endl;
	}
};

int main() {	
	/*Cat a;
	Animal &b = a;
	Animal *c = &a;
	People b, c;
	Animal *d[3] = {&a, &b, &c};
	for (int i = 0; i < 3; i++) {
		d[i]->run();
	}*/
	People a;
	a.run();
	Animal &b = a;
	b.run();
	Animal *c = &a;
	c->run();
	return 0;
}