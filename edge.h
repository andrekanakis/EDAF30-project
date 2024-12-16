#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge{
public:
    Edge(Node* destination, int length);

    Node* getDest() const;

    int getLength() const;

private:
    Node* dest;
    int len;
};

#endif
