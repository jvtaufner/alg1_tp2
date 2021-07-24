#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class Graph{

    private:

        int numberOfNodes;
        int numberOfEdges;
        vector<vector<int>> adjList;

    public:

        Graph(int numberOfNodes, int numberOfEdges);
        void addEdge(int node1, int node2);
        
};


#endif