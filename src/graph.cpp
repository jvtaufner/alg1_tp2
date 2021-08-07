#include "../lib/graph.hpp"

Graph::Graph(int numberOfNodes, int numberOfEdges){

    this->numberOfNodes = numberOfNodes;
    this->numberOfEdges = numberOfEdges;
    this->adjList.resize(numberOfNodes, vector<int>(0));
    this->visited.resize(numberOfNodes, false);
}

Graph::Graph(int numberOfNodes){

    this->numberOfNodes = numberOfNodes;
    this->adjList.resize(numberOfNodes, vector<int>(0));
    this->visited.resize(numberOfNodes, false);
}


void Graph::addEdge(int node1, int node2){
    
    adjList[node1-1].push_back(node2);
}


vector<int> Graph::getNeighbors(int node){
    return adjList[node-1];
}

bool Graph::getVisited(int node){
    return visited[node-1];
}

void Graph::setVisited(int node){
    visited[node-1] = true;
}

int Graph::getNumberOfNodes(){
    return numberOfNodes;
}

int Graph::getNumberOfEdges(){
    return numberOfEdges;
}

void Graph::setNumberOfEdges(int numberOfEdges){
    this->numberOfEdges = numberOfEdges;
}