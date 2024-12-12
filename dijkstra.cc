#include "dijkstra.h"
#include "nodeset.h"

void dijkstra(Node* start) {
    start->setValue(0);
    start->setParent(nullptr);

    NodeSet nodes;
    nodes.add(start);

    while (!nodes.isEmpty()) {
        Node* current = nodes.removeMin();

        for (const Edge& edge : current->getEdges()) {
            Node* dest = edge.getDest();
            int newDistance = current->getValue() + edge.getLength();

            if (newDistance < dest->getValue()) {
                dest->setValue(newDistance);
                dest->setParent(current);
                nodes.add(dest);
            }
        }
    }
}
