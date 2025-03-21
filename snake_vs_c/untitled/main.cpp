#include <iostream>


class A {
    int bla;
};

void something(A& obj) {
    std::cout << "L value ref of A" << std::endl;
}

int main() {
    something(A());
    std::cout << "Hello, World!" << std::endl;
    return 0;
}