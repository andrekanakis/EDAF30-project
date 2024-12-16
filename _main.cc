#include "dijkstra.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include "cost_functions.h"

using std::cout;

void printPath(Node* dest) {
    std::vector<Node*> path;

    Node* current = dest;
    while (current != nullptr) {
        path.push_back(current);
        current = current->getParent();
    }

    for (auto& p : path) {
        std::cout << p->getName() << ' ';
    }

    std::cout << dest->getValue() << '\n';
}


int main() {
    std::ifstream file("../graph.txt");
    if (!file) {
        cout << "Could not open graph.txt\n";
        return 1;
    }

    Graph g(file);

    while (true) {
        cout << "Choose functionm method\n";
        cout << "1. Shortest distance\n";
        cout << "2. Fewest cities passed\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

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
        if (choice == 1) {
            dijkstra(startNode, DistanceCost());
            cout << "Shortest distance path: ";
        } else if (choice == 2) {
            dijkstra(startNode, CitiesPassedCost());
            cout << "Fewest cities passed path: ";
        } else {
            cout << "Wrong input, try again\n";
            continue;
        }

        int result = destNode->getValue();
        if (result == Node::max_value) {
            cout << "No path exists! Better luck next time!\n";
        } else {
            cout << "from: " << start << " to: " << dest << " is " << result; 
            if (choice == 1) cout << " km long\n";
            if (choice == 2) cout << " cities passed\n";
            printPath(destNode);
        }
    }
    return 0;
}
