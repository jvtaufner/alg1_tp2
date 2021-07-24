#include "../lib/graph.hpp"


Graph::Graph(int numberOfNodes, int numberOfEdges){

    this->numberOfNodes = numberOfNodes;
    this->numberOfEdges = numberOfEdges;
    this->adjList.resize(numberOfNodes, vector<int>(0));
}

void Graph::addEdge(int node1, int node2){
    //número dos nós começa em 1
    adjList[node1-1].push_back(node2);
}

void Graph::printGraph(){
    for(int i=0; i<numberOfNodes; i++){
        cout << "Lista de " << i+1 << endl;
        for(auto v : adjList[i]){
            cout << v << endl;
        }
    }
}