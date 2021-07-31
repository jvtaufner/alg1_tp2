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

/*void GraphUtils::DFS(Graph graph){
    unordered_set<bool> visited = {false};


}*/