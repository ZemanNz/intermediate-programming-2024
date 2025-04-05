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
        if(n % 2 ==1){
            n = 3* n + 1;
            vysledek++;
        }
    }
    return vysledek;
}
struct Coords {
    int x;
    int y;
};

bool is_valid(Coords coords) {
    return false;
}

std::vector<Coords> next(Coords now) {
    std::vector<Coords> result;
    return result;
}

bool can_horse(Coords start, Coords end, unsigned steps) {
    return false;
}

unsigned horse_steps(Coords start, Coords end) {
    return 0;
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
    /*
    assert(collatz(6) == 8);
    assert(collatz(10) == 6);
    assert(collatz(1) == 0);
    assert(collatz(15) == 17);
    */
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
