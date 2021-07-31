#include "../lib/graph_utils.hpp"

Graph GraphUtils::reverseGraph(Graph graph){

    Graph reversedGraph(graph.getNumberOfNodes(), graph.getNumberOfEdges());
    
    for(int i=0; i<graph.getNumberOfNodes(); i++){
        for(int v : graph.getNeighbors(i)){
            reversedGraph.addEdge(v, i+1);
        }
    }
    return reversedGraph;
}

void GraphUtils::DFS(Graph &graph, int node){
    
    graph.setVisited(node);

    for(int v : graph.getNeighbors(node)){
        if(!graph.getVisited(v)){
            DFS(graph, v);
        }
    }
}

void GraphUtils::DFS(Graph &graph, int node, stack<int> &dfsFinishOrder){

    graph.setVisited(node);

    for(int v: graph.getNeighbors(node)){
        if(!graph.getVisited(v)){
            DFS(graph, v, dfsFinishOrder);
        }
    }
    dfsFinishOrder.push(node);
}

