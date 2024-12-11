#include "nodeset.h"

NodeSet::NodeSet(){}

bool NodeSet::isEmpty() {
    return nodes.empty(); 
}

void NodeSet::add(Node* node) {
    for (Node* n : nodes) {
        if (n->getName() == node->getName()) return;
    }
    nodes.push_back(node);
}

Node* NodeSet::removeMin() {
    if (isEmpty()) return nullptr;
    int smallest = nodes[0]->getValue();
    Node* smallestNode = nodes[0];
    int index = 0;
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->getValue() < smallest) {
            smallest = nodes[i]->getValue();
            smallestNode = nodes[i];
            index = i;
        }
    }

    nodes.erase(nodes.begin()+index);
    return smallestNode;
}
