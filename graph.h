#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <memory>
#include <vector>
#include <string>
#include <istream>

class Graph {
public:
    Graph();
    Graph(std::istream& in);

    void addNode(const std::string& name);
    Node* find(const std::string& name);
    void resetVals();


    using iterator = std::vector<std::unique_ptr<Node>>::iterator;
    iterator begin();
    iterator end();


private:
    std::vector<std::unique_ptr<Node>> nodes;
};


#endif
