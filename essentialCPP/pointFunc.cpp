#include <iostream>

void print_num(int num) {
    std::cout << "this number:" << num << std::endl;
    return ;
}

int main() {
    int a = 10000;
    void (*ptr_func)(int);
    void (*ptr_funcs[10])(int);
    ptr_funcs[0] = print_num;
    ptr_func = print_num;
    ptr_func(a);
    ptr_funcs[0](a + 10);
    (*(ptr_funcs + 0))(a + 100);
    return 0;
}
