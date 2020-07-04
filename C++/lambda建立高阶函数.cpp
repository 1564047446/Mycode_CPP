#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void PrintVector(vector<int>& numbers) {
    for (auto it = begin(numbers); it != end(numbers); it++) {
        if (it != begin(numbers)) {
            cout << ", ";
        }
        cout << *it;
    }
    cout << endl;
}

bool IsOdd(int a) {
    return a % 2 == 1;
}

bool Not(bool b) {
    return !b;
}

bool And(bool a, bool b) {
    return a && b;
}

bool Or(bool a, bool b) {
    return a || b;
}

decltype(auto) GreaterThan(int x) {
    return [=](int y)
    {
        return y > x;
    };
}

decltype(auto) EqualsTo(int x) {
    return [=](int y)
    {
        return y == x;
    };
}

auto Compose = [](auto f, auto g) {
    return [=](auto x) {
        return f(g(x));
    };
};

auto Combine = [](auto c, auto f, auto g) {
    return [=](auto x) {
        return c(f(x), g(x));
    };
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    {
        vector<int> odds;
        copy_if(begin(numbers), end(numbers), back_inserter(odds),
            IsOdd
            );
        PrintVector(odds);
    }
    {
        vector<int> evens;
        copy_if(begin(numbers), end(numbers), back_inserter(evens),
            Compose(Not, IsOdd)
            );
        PrintVector(evens);
    }
    {
        vector<int> one_two_nine_ten;
        copy_if(begin(numbers), end(numbers), back_inserter(one_two_nine_ten),
            Combine(Or,
                Combine(And,
                    Combine(Or, GreaterThan(1), EqualsTo(1)),
                    Compose(Not, GreaterThan(2))
                    ),
                Combine(And,
                    Combine(Or, GreaterThan(9), EqualsTo(9)),
                    Compose(Not, GreaterThan(10))
                    )
                )
            );
        PrintVector(one_two_nine_ten);
    }
    return 0;
}
