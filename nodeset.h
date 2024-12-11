#ifndef NODESET_H
#define NODESET_H

#include "node.h"

class NodeSet {
public:
    NodeSet();
    bool isEmpty();
    Node* removeMin();
    void add(Node* node);
   
private:
    std::vector<Node*> nodes;
};

#endif
