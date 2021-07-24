#include "../lib/graph.hpp"


Graph::Graph(int numberOfNodes, int numberOfEdges){

    this->numberOfNodes = numberOfNodes;
    this->numberOfEdges = numberOfEdges;
    this->adjList.resize(numberOfNodes, vector<int>(0));
}

void Graph::addEdge(int node1, int node2){
    adjList[node1].push_back(node2);
}