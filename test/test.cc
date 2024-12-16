#include "../dijkstra.h"
#include "../graph.h"
#include "../cost_functions.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

void test_shortest_distance(Graph& g) {
    std::cout << "Testing shortest distance between Lund and Veberod\n";
    Node* start = g.find("Lund");
    Node* end = g.find("Veberod");

    g.resetVals();
    dijkstra(start, DistanceCost());
    assert(end->getValue() == 23); // Lund -> Dalby -> Veberod = 12 + 11 = 23
    std::cout << "Shortest path correct! Expected: 23, Got: " << end->getValue() << '\n';
}

void test_few_cities(Graph& g) {
    std::cout << "Testing fewest cities between Lund and Veberod\n";
    Node* start = g.find("Lund");
    Node* end = g.find("Veberod");
    g.resetVals();
    dijkstra(start, CitiesPassedCost());
    assert(end->getValue() == 2);// Passes through Dalby
    std::cout << "Cities passed correct! Expected: 2, Got: " << end->getValue() << '\n';
}

int main() {
    std::ifstream file("../graph.txt");
    if (!file) {
        std::cerr << "Could not open file.txt!\n";
        return 1;
    }

    Graph g(file);
    g.resetVals();
    test_shortest_distance(g);
    test_few_cities(g);

    std::cout << "All test passed!";

    return 0;
}
