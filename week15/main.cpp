#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <set>
#include <string>

void previously() {
    std::vector<int> pole = { 0, 2, 4, 6, 8, 10, 10, 2, 9 };

    std::tuple<int, float, bool> ntice = { 5, 6.2, false };

    std::set<int> mnozina = { 0, 1, 2, 3, 5 };
    std::map<std::string, int> slovnik = { { "jablka", 10 }, { "hrušky", 11 } };
}




void demo() {
    struct Book {
        std::string title;
        std::string author;
        int isbn;
        int publish_year;
    };

    Book lotr { "Lord of the Rings", "J.R.R. Tolkien", 10, 2000 };

    Book mistborn = {
        .title = "Mistborn",
        .author = "Brandon Sanderson",
        .isbn = 5,
        .publish_year = 2010,
    };

    lotr.year = 2000;

    std::cout << mistborn.title << std::endl;

    Book favorite;

    std::cout << favorite.title << std::endl;

    favorite = lotr;

    std::cout << favorite.title << std::endl;

    favorite = mistborn;
    
    std::cout << favorite.title << std::endl;
}

int main() {
}
