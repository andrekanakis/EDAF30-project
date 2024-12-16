#include "node.h"
#include <vector>
#include <string>

Node::Node(const std::string& name) : name(name), val(Node::max_value) {}

std::string Node::getName() const{
    return name;
}

void Node::setValue(int v){
    val = v;
}

int Node::getValue() const{
    return val;
}

void Node::addEdge(Node* destination, int length){
    edges.push_back(Edge(destination, length));
}

const std::vector<Edge>& Node::getEdges() const{
    return edges;
}

void Node::setParent(Node* node) {
    parent = node;
}

Node* Node::getParent() const {
    return parent;
}
