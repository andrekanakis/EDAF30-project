#ifndef NODE_H
#define NODE_H

#include "edge.h"
#include <vector>
#include <string>
#include <limits>

class Node{
public:

    static const int max_value = std::numeric_limits<int>::max();

    Node(const std::string& name);

    std::string getName() const;

    void setValue(int v);

    int getValue() const;

    void addEdge(Node* destination, int length);

    const std::vector<Edge>& getEdges() const;

    void setParent(Node* node);

    Node* getParent() const;

private:
    std::string name;
    int val;
    std::vector<Edge> edges;
    Node* parent {nullptr};
};

#endif
