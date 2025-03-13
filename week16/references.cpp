#include <iostream>

void references() {
    int a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << std::endl;

    int& b = a;
    std::cout << "b: " << b << std::endl;
    std::cout << std::endl;

    a = 10;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << std::endl;

    b = 15;

    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << std::endl;
}

void increment(int& arg) {
    arg++;
}

void increment_c(const int& arg) {
    // arg++;
}

int main() {
    references();

    int a = 6;
    std::cout << "a: " << a << std::endl;
    increment(a);
    std::cout << "a: " << a << std::endl;

    increment_c(a);
}
