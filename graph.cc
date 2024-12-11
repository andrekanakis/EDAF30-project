#include "graph.h"
#include <memory>
#include <string>
#include <sstream>


Graph::Graph() = default;

void Graph::addNode(const std::string& name) {
    if (find(name) == nullptr) {
        nodes.push_back(std::make_unique<Node>(name));
    }
}

Node* Graph::find(const std::string& name) {
    for (const auto& node : nodes) {
        if (node->getName() == name) {
            return node.get();
        }
    }
    return nullptr;
}

void Graph::resetVals() {
    for (const auto& node : nodes) {
        node->setValue(Node::max_value);
    }
}

Graph::iterator Graph::begin() {
    return nodes.begin();
}

Graph::iterator Graph::end() {
    return nodes.end();
}

Graph::Graph(std::istream& in) {
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string from;
        std::string to;
        int distance;
        char colon;

        if (iss >> from >> colon >> distance >> to) {
            addNode(from);
            addNode(to);

            Node* fromNode = find(from);
            Node* toNode = find(to);
            if (fromNode && toNode) {
                fromNode->addEdge(toNode, distance);
            }
        }
    }
}
