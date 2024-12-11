#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>
#include <string>


class Graph {
public:
    Graph() = default;

    void addNode(const std::string& name);
    Node* find(const std::string& name);
    void resetVals();


    using iterator = std::vector<Node*>::iterator;
    iterator begin();
    iterator end();


private:
    std::vector<std::unique_ptr<Node>> nodes;
};


#endif
