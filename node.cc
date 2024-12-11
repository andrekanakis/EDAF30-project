#include "node.h"
#include <vector>
#include <string>

std::string name;
int val;
std::vector<Edge> edges;

Node::Node(const std::string& name){

}

/** Hämtar nodens namn. */
std::string Node::getName() const{

}

/** Sätter nodens värde till v. */
void Node::setValue(int v){

}

/** Hämtar nodens värde. */
int Node::getValue() const{

}

/** Lägger till en ny båge från denna nod till en given destination.
Bågen ska ha längden length. */
void Node::addEdge(Node* destination, int length){

}

/** Hämtar de bågar som utgår från denna nod. */
const std::vector<Edge>& Node::getEdges() const{

}
