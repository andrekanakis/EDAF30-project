#include "nodeset.h"

std::vector<Node*> nodes;

NodeSet::NodeSet(){}

bool isEmpty() {
    return nodes.empty(); 
}

void add(Node* node) {
    nodes.push_back(node);
}

Node* removeMin() {
    if (isEmpty()) return nullptr;
    int size = nodes[0]->getValue();
    Node* smallestNode = nodes[0];
    int index = 0;
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->getValue() < size) {
            size = nodes[i]->getValue();
            smallestNode = nodes[i];
            index = i;
        }
    }

    nodes.erase(nodes.begin()+index);
    return smallestNode;
}
