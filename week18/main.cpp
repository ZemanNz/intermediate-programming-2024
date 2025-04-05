#include <iostream>
#include <vector>
#include <cassert>
#include <set>
int factorial(int n) {
    int a = 1;
    int vysledek = 1;
    for(int i = 0; i< n ; i++){
        vysledek = a * vysledek;
        a++;
    }
    return vysledek;
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int vysledek;
    if(n == 0){ return a;}
    if(n == 1){ return b;}
    for(int i = 1; i < n; i++){
        vysledek = a + b;
        a = b;  
        b = vysledek;
    }
    return vysledek;
}

// Počet vzestupných kroků
int collatz(int n) {
    int vysledek = 0;
    while(n != 1){
        if(n % 2 == 0){
            n = n / 2;
        }
        else if(n % 2 ==1){
            n = 3* n + 1;
            vysledek++;
        }
    }
    std::cout << " " << std::endl;
    std::cout << "vysledek: " << vysledek << std::endl;
    return vysledek;
}
struct Coords {
    int x;
    int y;
    bool operator==(const Coords& other) const {
        return x == other.x && y == other.y;
    }
};

bool is_valid(Coords coords) {
    if ((coords.x >= 0 && coords.y >= 0) && (coords.x < 8 && coords.y < 8)) {
        return true;
    }
    return false;
}

std::vector<Coords> next(Coords now) {
    std::vector<Coords> result;
    Coords q = {now.x + 1, now.y + 2};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x + 2, now.y + 1};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x + 2, now.y - 1};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x + 1, now.y - 2};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x - 1, now.y - 2};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x - 2, now.y - 1};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x - 2, now.y + 1};
    if(is_valid(q)){
        result.push_back(q);
    }
    q = {now.x - 1, now.y + 2};
    if(is_valid(q)){
        result.push_back(q);
    }
    return result;
}
bool existuje(const std::vector<Coords>& vec, const Coords& value) {
    for (const auto& item : vec) {
        if (item == value) {
            return true;
        }
    }
    return false;
}


bool can_horse(Coords start, Coords end, unsigned steps) {
    std::vector<Coords> visited;
    visited.push_back(start);
    unsigned vysledek = 0;
    if((start == end) && (steps % 2 == 0)){ return true;}
    while(!existuje(visited, end)){
        vysledek++;
        for(const auto& coord : visited){
            std::vector<Coords> next_coords = next(coord);
            for(std::size_t j = 0; j < next_coords.size(); j++){
                visited.push_back(next_coords[j]);
            }
        }
    }
    if(vysledek == steps){
        return true;
    }
    if((vysledek - steps) % 2 == 0){
        return true;
    }
    return false;
}


unsigned horse_steps(Coords start, Coords end) {
    std::vector<Coords> visited;
    visited.push_back(start);
    int vysledek = 0;
    while(!existuje(visited, end)){
        vysledek++;
        for(const auto& coord : visited){
            std::vector<Coords> next_coords = next(coord);
            for(std::size_t j = 0; j < next_coords.size(); j++){
                if(!existuje(visited, next_coords[j])){
                    visited.push_back(next_coords[j]);
                }
            }
        }
    }
    return vysledek;
}

using Neighbours = std::vector<std::size_t>;
using Graph = std::vector<Neighbours>;
bool abc(const Graph& graph, std::size_t current, std::size_t end, std::set<std::size_t>& visited) {
    if (current == end)return true;
    visited.insert(current);
    for (std::size_t i = 0; i < graph[current].size(); i++) {
        if (!visited.contains(graph[current][i])) {
            if (abc(graph, graph[current][i], end, visited)) {
                return true;
            }
        }
    }
    return false;
}

void printGraph(const Graph& graph) {
    for (std::size_t i = 0; i < graph.size(); ++i) {
        std::cout << "Node " << i << ": ";
        for (std::size_t j = 0; j < graph[i].size(); ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool reachable(const Graph& graph, std::size_t start, std::size_t end) {
    Graph my_graph = graph;
    for(std::size_t i = 0; i < graph.size(); i++){
        for(std::size_t j = 0; j < graph[i].size(); j++){
            my_graph[graph[i][j]].push_back(i);
        }
    }
    //std::cout << "Graph contents:" << std::endl;
    //printGraph(my_graph);
    if(graph.size() == 0){
        return false;
    }
    std::set<std::size_t> visited;
    return abc(my_graph, start, end, visited);
}


bool reachable_oriented(const Graph& graph, std::size_t start, std::size_t end) {
    if(graph.size() == 0){
        return false;
    }
    std::set<std::size_t> visited;
    return abc(graph, start, end, visited);
}

int main() {
// Test factorial
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(5) == 120);
    assert(factorial(10) == 3628800);

    // Test fibonacci
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(5) == 5);
    assert(fibonacci(10) == 55);

    // Test collatz
    
    assert(collatz(6) == 2);
    assert(collatz(10) == 1);
    assert(collatz(1) == 0);
    assert(collatz(15) == 5);

    assert(can_horse({0, 0}, {0, 0}, 0) == true);
    assert(can_horse({3, 3}, {3, 3}, 0) == true);

    // Test: Jeden tah – legální tah koně
    assert(can_horse({0, 0}, {1, 2}, 1) == true);
    assert(can_horse({0, 0}, {2, 1}, 1) == true);

    // Test: Jeden tah – ale cílová pozice není dosažitelná jedním tahem
    assert(can_horse({0, 0}, {2, 2}, 1) == false);

    // Test: Návrat do stejné pozice přes dva tahy (např. 0,0 → (1,2) → 0,0)
    assert(can_horse({0, 0}, {0, 0}, 2) == true);

    // Test: Cesta, která vyžaduje přesně 4 tahy
    // Například z (0,0) do (4,4) je minimální počet tahů 4
    assert(can_horse({0, 0}, {4, 4}, 3) == false);
    assert(can_horse({0, 0}, {4, 4}, 4) == true);

    // Test: Tah z okraje šachovnice
    // Z (7,7) do (6,5) je legální tah
    assert(can_horse({7, 7}, {6, 5}, 1) == true);

    // Test: Zkuste detour – když počet tahů je větší, než je minimální cesta
    // Například z (0,0) do (1,2) je minimálně 1 tah, takže přesně 2 tahy by neměly stačit
    assert(can_horse({0, 0}, {1, 2}, 2) == false);

    // Test: Další tah z okraje – z (7,7) do (5,6) (legální tah) 
    assert(can_horse({7, 7}, {5, 6}, 1) == true);

    // Test: Z (7,7) do (4,7) za 2 tahy
    // Například cesta: (7,7) → (5,6) → (4,7)
    assert(can_horse({7, 7}, {5, 6}, 5) == true);

    assert(horse_steps({0, 0}, {0, 0}) == 0);
    assert(horse_steps({3, 3}, {3, 3}) == 0);

    // Cíl je dosažen jedním tahem
    assert(horse_steps({0, 0}, {1, 2}) == 1);
    assert(horse_steps({0, 0}, {2, 1}) == 1);

    // Dva tahy
    assert(horse_steps({0, 0}, {3, 3}) == 2);
    assert(horse_steps({0, 0}, {4, 2}) == 2);

    // Tři tahy
    assert(horse_steps({0, 0}, {4, 4}) == 4);
    assert(horse_steps({0, 0}, {7, 0}) == 5);

    // Delší cesta
    assert(horse_steps({0, 0}, {7, 7}) == 6);
    assert(horse_steps({7, 0}, {0, 7}) == 6);
    
    // Test reachable for graph (not oriented)
    Graph graph = {{1}, {2}, {}, {2}};
    assert(reachable(graph, 3, 0) == true); // Path: 0 -> 1 -> 2 <- 3
    assert(reachable(graph, 0, 1) == true); // Path: 0 -> 1

    // Test reachable_oriented for graph (oriented)
    assert(reachable_oriented(graph, 0, 3) == false); // Path: 0 -> 1 -> 2 -> 3
    assert(reachable_oriented(graph, 1, 2) == true); // Path: 1 -> 2

Graph graph_non_oriented = {
        {1, 2},    // Node 0 is connected to 1 and 2
        {0, 3},    // Node 1 is connected to 0 and 3
        {0, 3},    // Node 2 is connected to 0 and 3
        {1, 2},    // Node 3 is connected to 1 and 2
        {}         // Node 4 is isolated
    };

    // Test cases for non-oriented graph
    assert(reachable(graph_non_oriented, 0, 3) == true);  // Path: 0 -> 1 -> 3
    assert(reachable(graph_non_oriented, 2, 1) == true);  // Path: 2 -> 0 -> 1
    assert(reachable(graph_non_oriented, 0, 4) == false); // Node 4 is isolated
    assert(reachable(graph_non_oriented, 3, 0) == true);  // Path: 3 -> 1 -> 0

    // Test oriented graph (reachable_oriented)
    Graph graph_oriented = {
        {1, 2},    // Node 0 points to 1 and 2
        {3},       // Node 1 points to 3
        {3},       // Node 2 points to 3
        {4},       // Node 3 points to 4
        {}         // Node 4 is isolated
    };

    // Test cases for oriented graph        cdtdtdfg -------------- neco

    assert(reachable_oriented(graph_oriented, 0, 3) == true);  // Path: 0 -> 1 -> 3
    assert(reachable_oriented(graph_oriented, 2, 4) == true);  // Path: 2 -> 3 -> 4
    assert(reachable_oriented(graph_oriented, 1, 0) == false); // No path from 1 to 0
    assert(reachable_oriented(graph_oriented, 3, 0) == false); // No path from 3 to 0
    assert(reachable_oriented(graph_oriented, 4, 4) == true);  // No movement needed, it's the same node

    // Edge case: Empty graph (no nodes)
    Graph empty_graph = {};
    assert(reachable(empty_graph, 0, 0) == false);  // No nodes, so no reachability
    assert(reachable_oriented(empty_graph, 0, 0) == false);  // Same for oriented graph

    // Test disconnected graph (non-oriented)
    Graph disconnected_graph = {
        {1},       // Node 0 points to 1
        {0},       // Node 1 points to 0
        {},        // Node 2 is isolated
        {4},       // Node 3 points to 4
        {3}        // Node 4 points to 3
    };

    assert(reachable(disconnected_graph, 0, 1) == true);  // Direct path between 0 and 1
    assert(reachable(disconnected_graph, 0, 2) == false); // Node 2 is isolated
    assert(reachable(disconnected_graph, 3, 4) == true);  // Path: 3 -> 4
    assert(reachable(disconnected_graph, 0, 4) == false); // No path from 0 to 4

    // Test cyclic graph (non-oriented)
    Graph cyclic_graph = {
        {1},      // Node 0 points to 1
        {2},      // Node 1 points to 2
        {0},      // Node 2 points to 0 (cycle)
    };

    assert(reachable(cyclic_graph, 0, 2) == true);  // Path: 0 -> 1 -> 2
    assert(reachable(cyclic_graph, 1, 0) == true);  // Path: 1 -> 2 -> 0
    assert(reachable(cyclic_graph, 0, 0) == true);  // Cycle, so reachability exists

    std::cout << "All tests passed!" << std::endl;
}
