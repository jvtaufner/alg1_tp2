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
    stack<int> teste;
    GraphUtils::DFS(graph, 1, teste);
    
    //reversedGraph.printGraph();
    /*for(int i=0; i<graph.getNumberOfNodes(); i++){
        cout << graph.getVisited(i+1) << " ";
    }
    cout << "\n\n\n";
    
    
        for(int i=0; i<graph.getNumberOfNodes(); i++){
        cout << graph.getVisited(i+1) << " ";
    }
    cout << "\n\n\n";
    while (!teste.empty()) {
        cout << ' ' << teste.top();
        teste.pop();
    }*/
    
}