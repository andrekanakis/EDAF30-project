#include "dijkstra.h"
#include "graph.h"
#include <iostream>
#include <fstream>

using std::cout;

int main() {
    std::ifstream file("../graph.txt");
    if (!file) {
        cout << "Could not open graph.txt\n";
        return 1;
    }

    Graph g(file);

    while (true) {
        cout << "Calc the shortest dist between 2 cities\n";
        cout << "Enter start city: ";
        std::string start;
        std::getline(std::cin, start);

        Node* startNode = g.find(start);
        if (!startNode) {
            cout << "City " << start << " not found in graph!\n";
            continue;
        }

        cout << "Enter destination city: ";
        std::string dest;
        std::getline(std::cin, dest);

        Node* destNode = g.find(dest);
        if (!destNode) {
            cout << "City " << dest << " not found in graph!\n";
            continue;
        }

        g.resetVals();
        dijkstra(startNode);

        int distance = destNode->getValue();
        if (distance == Node::max_value) {
            cout << "No path exists! Better luck next time!\n";
        } else {
            cout << "Path from: " << start << " to: " << dest << " is " << distance << " km long!\n";
        }
    }
    return 0;
}
