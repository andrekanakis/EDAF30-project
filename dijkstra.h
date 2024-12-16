#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "node.h"
#include "nodeset.h"

template<typename CostFunction>
void dijkstra(Node* start, const CostFunction& costFunc) {
    start->setValue(0);
    start->setParent(nullptr);

    NodeSet nodes;
    nodes.add(start);

    while (!nodes.isEmpty()) {
        Node* current = nodes.removeMin();
        for (const Edge& edge : current->getEdges()) {
            Node* dest = edge.getDest();
            int newDist = current->getValue() + costFunc(current, edge);

            if (newDist < dest->getValue()) {
                dest->setValue(newDist);
                dest->setParent(current);
                nodes.add(dest);
            }
        }
    }
}



#endif
