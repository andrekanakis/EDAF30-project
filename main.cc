#include "dijkstra.h"
#include "graph.h"
#include "cost_functions.h"
#include <iostream>
#include <fstream>
#include <optional>
#include <limits>

using std::cout;

void printPath(Node* dest) {
    if (!dest) return;

    std::vector<Node*> path;
    Node* current = dest;
    while (current != nullptr) {
        path.push_back(current);
        current = current->getParent();
    }

    for (auto& p: path) {
        if (!p) return;
        cout << p->getName() << ' ';
    }
    cout << dest->getValue() << '\n';
}

void printMenu(){
    cout << "Choose function method\n";
    cout << "1. Shortest distance\n";
    cout << "2. Fewest cities passed\n";
}

std::optional<Node*> getCity(Graph& g, const std::string& prompt) {
    cout << prompt;
    std::string city;
    std::getline(std::cin, city);

    Node* node = g.find(city);
    if (!node) {
        cout << "City: " << city << " could not be found.\n";
    }
    return node;
}

std::optional<std::pair<Node*, Node*>> getCities(Graph& g) {
    auto start = getCity(g, "Enter start city: ");
    if (!start.has_value()) return std::nullopt;

    auto dest = getCity(g, "Enter destination city: ");
    if (!dest.has_value()) return std::nullopt;

    return std::make_pair(start.value(), dest.value());
}

void calcAndPrintPath(Node* start, Node* dest, int choice) {
    if (!start || !dest) return;

    if (choice == 1) {
        dijkstra(start, DistanceCost());
    } else {
        dijkstra(start, CitiesPassedCost());
    }

    int result = dest->getValue();
    if (result == Node::max_value) {
        cout << "No path could be found.\n";
        return;
    }

    cout << (choice == 1 ? "Shortest distance path: " : "Fewest cities passed path: ");
    cout << "from: " << start->getName() << " to: " << dest->getName() << " is " << result
        << (choice == 1 ? " km long\n" : " cities passed\n");
    printPath(dest);
}

bool processUserChoice(Graph& g) {
    printMenu();
    int choice;
    
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, enter 1 or 2.\n";
        return true;
    }
    std::cin.ignore();

    if (choice != 1 && choice != 2) {
        cout << "Wrong input, try again!\n";
        return true;
    }

    g.resetVals();

    auto cities = getCities(g);
    if (!cities.has_value()) return true;

    calcAndPrintPath(cities.value().first, cities.value().second, choice);
    return true;
}

int main() {
    std::ifstream file("../graph.txt");
    if (!file) {
        std::cerr << "Could not open file!";
        return 1;
    }

    Graph g(file);
    while (processUserChoice(g)) {
    
    }

    return 0;
}
