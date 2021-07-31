#include <vector>
#include <iostream>
#include "./lib/graph.hpp"
#include "./lib/graph_utils.hpp"

using namespace std;

Graph readInput(){

    int x, y, aux1, aux2;

    cin >> x >> y;
    Graph graph(x, y);
    
    for(int i=0; i<y; i++){
        cin >> aux1 >> aux2;
        graph.addEdge(aux1, aux2);
    }

    return graph;

}

int main(){

    Graph graph = readInput();
    //graph.printGraph();
    Graph reversedGraph = GraphUtils::reverseGraph(graph);
    GraphUtils::DFS(graph, 10);
    //reversedGraph.printGraph();
    /*for(int i=0; i<graph.getNumberOfNodes(); i++){
        cout << graph.getVisited(i+1) << " ";
    }
    cout << "\n\n\n";
    
        for(int i=0; i<graph.getNumberOfNodes(); i++){
        cout << graph.getVisited(i+1) << " ";
    }*/
    
}