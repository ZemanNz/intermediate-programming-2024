#include <iostream>
#include <vector>

void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

int sum(std::vector<int> data) {
    return 0;
}

float average(std::vector<int> data) {
    return 0.0;
}

float median(std::vector<int> data) {
    return 0.0;
}

std::vector<int> range(int start, int end) {
    return {};
}

std::vector<int> runningSum(std::vector<int> data) {
    return {};
}

std::vector<int> rotateRight(std::vector<int> data, int count) {
    return data;
}

int main() {
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };

    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(vec1) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;
 
    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;
}
