#ifndef EDGE_H
#define EDGE_H

#include <algorithm>
#include <set>

class Edge {
   public:
    Edge();
    explicit Edge(int vertex1, int vertex2)
        : v1(std::min(vertex1, vertex2)), v2(std::max(vertex1, vertex2)) {}

    bool operator<(const Edge &other) const {
        return (v1 < other.v1) || (v1 == other.v1 && v2 < other.v2);
    }

    int v1, v2;
};

#endif  // EDGE_H
