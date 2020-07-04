#include <iostream>

using namespace std;

typedef void (*func)();
typedef void (*func2)(void *, int);

struct A {
	virtual void say1() {
		cout << "say1()" << endl;
	}
	virtual void say2() {
		cout << "say2()" << endl;
	}
	virtual void say3() {
		cout << "say3()" << endl;
	}
	virtual void say4() {
		cout << "say4()" << endl;
	}
	virtual void say5(int x) {
		cout << "say5() " << x << endl;
	}
};

int main() {
	A *a = new A;
	for (int i = 0; i < 4; i++) {
		(*((((func **)a)[0]) + i))();
		(((func **)a)[0])[i]();	
	}
	((func2 **)a)[0][4](a, 123);	
	return 0;
}