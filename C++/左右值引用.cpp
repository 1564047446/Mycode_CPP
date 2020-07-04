#include <iostream>

using namespace std;

void test(int &x) {
	cout << "this is left :" << x << endl;
	return ;
}

void test(int &&x) {
	cout << "this is right :" << x << endl;
}

void func(int &x) {
	cout << "this is left func" << endl;
	test(x);
	return ;
}

void func(int &&x) {
	cout << "this is right func" << endl;
	//test(x);
	test(forward<int &&>(x));
	return ;
}

int main() {
	int a = 1, b = 2;
	test(a);
	test(b);
	func(a + b);
	return 0;
}