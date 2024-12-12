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

    /** Hämtar nodens namn. */
    std::string getName() const;

    /** Sätter nodens värde till v. */
    void setValue(int v);

    /** Hämtar nodens värde. */
    int getValue() const;

    /** Lägger till en ny båge från denna nod till en given destination.
    Bågen ska ha längden length. */
    void addEdge(Node* destination, int length);

    /** Hämtar de bågar som utgår från denna nod. */
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
