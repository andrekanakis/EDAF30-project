#ifndef COST_FUNCTIONS_H
#define COST_FUNCTIONS_H

#include "node.h"
#include "edge.h"

class DistanceCost {
public:
    int operator()([[maybe_unused]] const Node* node, const Edge& edge) const {
        return edge.getLength();
    }
};

class CitiesPassedCost {
public:
    int operator()([[maybe_unused]] const Node* node, [[maybe_unused]] const Edge& edge) const {
        return 1;
    }
};

#endif
