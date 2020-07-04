#include <iostream>
#include <functional>

using namespace std;

function<int(int)> Addr(int x) {
	return [=](int y) { return x + y; };
}

function<int(int)> Compose(function<int(int)> f, function<int(int)> g) {
	return [=](int y) { return f(g(y)); };
}

int main() {
	auto addr = Compose(Addr(1), Addr(2));
	cout << addr(3) << endl;
    function<int(int)> fib = [&fib](int i)->int
    {
        if (i < 2) {
            return 1;
        } else {
            return fib(i - 1) + fib(i - 2);
        }
    }/*请在这里补充lambda表达式*/;
    for (int i = 0; i < 10; i++)
    {
        cout << fib(i) << endl;
    }
	return 0;
}