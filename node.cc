#include "node.h"
#include <vector>
#include <string>

Node::Node(const std::string& name) : name(name), val(Node::max_value) {}

/** Hämtar nodens namn. */
std::string Node::getName() const{
    return name;
}

/** Sätter nodens värde till v. */
void Node::setValue(int v){
    val = v;
}

/** Hämtar nodens värde. */
int Node::getValue() const{
    return val;
}

/** Lägger till en ny båge från denna nod till en given destination.
Bågen ska ha längden length. */
void Node::addEdge(Node* destination, int length){
    edges.push_back(Edge(destination, length));
}

/** Hämtar de bågar som utgår från denna nod. */
const std::vector<Edge>& Node::getEdges() const{
    return edges;
}

void Node::setParent(Node* node) {
    parent = node;
}

Node* Node::getParent() const {
    return parent;
}
