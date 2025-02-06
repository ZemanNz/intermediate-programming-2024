#include <iostream>
#include <string>
#include <vector>

int sum(int a, int b) {
    return a+b;
}

std::string sum(std::string a, std::string b) {
    std::string c = a+ b;
    return c;
}

int sum(std::vector<int> xs) {
    int vysledek= 0;
    for(size_t i= 0; i < xs.size(); i++){
        vysledek+=xs[i];
    }
    return vysledek;
}

std::string sum(std::vector<std::string> xs) {
    std::string vysledek;
    for(size_t i= 0; i < xs.size(); i++){
        vysledek += xs[i];
    }
    return vysledek;
}

int mul(int a, int b) {
    return a*b;
}

std::string mul(int a, std::string b) {
    std::string vysledek;
    for(int i= 0; i < a; i++){
        vysledek+= b;
    }
    return vysledek;
}

int main() {
    std::cout << "sum(3, 4): " << sum(3, 4) << "\n"; // 7
    std::cout << R"(sum("Hello, ", "World!"): )" << sum("Hello, ", "World!") << "\n"; // Hello World
    std::cout << "sum({1, 2, 3, 4, 5}): " << sum(std::vector<int>{1, 2, 3, 4, 5}) << "\n"; // 15
    std::cout << R"(sum({"abc", "def", "ghi"}): )" << sum(std::vector<std::string>{"abc", "def", "ghi"}) << "\n"; // abcdefghi

    std::cout << "mul(3, 5): " << mul(3, 5) << "\n"; // 15
    std::cout << R"(mul(3, "Hi"): )" << mul(3, "Hi") << "\n"; // HiHiHi

    return 0;
}

