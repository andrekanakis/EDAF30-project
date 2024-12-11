#include "edge.h"

Node* dest;
int len;


/** Skapa en ny båge till noden destination, med längden length. */
Edge::Edge(Node* destination, int length){
    dest = destination;
    len = length;
}

/** Hämtar bågens destination. */
Node* Edge::getDestination(){
    return dest;
}

/** Hämtar bågens längd. */
int Edge::getLength() const{
    return len;
}