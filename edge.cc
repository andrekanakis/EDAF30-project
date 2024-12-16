#include "edge.h"

const Node* dest;
int len;

Edge::Edge(Node* destination, int length){
    dest = destination;
    len = length;
}

Node* Edge::getDest() const {
    return dest;
}

int Edge::getLength() const{
    return len;
}
