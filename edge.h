#ifndef EDGE_H
#define EDGE_H

#include "node.h"

class Edge{
public:
    /** Skapa en ny båge till noden destination, med längden length. */
    Edge(Node* destination, int length);

    /** Hämtar bågens destination. */
    Node* getDestination();

    /** Hämtar bågens längd. */
    int getLength() const;

private:
    Node* dest;
    int len;

};

#endif;