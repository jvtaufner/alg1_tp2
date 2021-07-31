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
        vector<bool> visited;
        
    public:

        Graph(int numberOfNodes, int numberOfEdges);
        void addEdge(int node1, int node2);
        vector<int> getNeighbors(int node);
        bool getVisited(int node);
        void setVisited(int node);
        int getNumberOfNodes();
        int getNumberOfEdges();
        void printGraph();
     
};


#endif