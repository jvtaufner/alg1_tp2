#include "../lib/graph_utils.hpp"

Graph GraphUtils::reverseGraph(Graph graph){

    Graph reversedGraph(graph.getNumberOfNodes(), graph.getNumberOfEdges());
    
    for(int i=0; i<graph.getNumberOfNodes(); i++){
        for(int v : graph.getNeighbors(i+1)){
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

void GraphUtils::DFS(Graph &graph, int node, int counter, vector<int> &newID){

    graph.setVisited(node);
    newID[node-1] = counter;

    for(int v : graph.getNeighbors(node)){
        if(!graph.getVisited(v)){
            DFS(graph, v, counter, newID);
        }
    }
}

Graph GraphUtils::createSimplerGraph(Graph graph, vector<int> newID, int newSize){

    Graph simplerGraph(newSize);
    int numberOfEdges = 0;
    bool uniqueEdges[newSize][newSize] = {false};

    for(int i=0; i<graph.getNumberOfNodes(); i++){
        for(int v : graph.getNeighbors(i+1)){
            if(newID[v-1] != newID[i] && !uniqueEdges[newID[i]-1][newID[v-1]-1]){
                simplerGraph.addEdge(newID[i], newID[v-1]);
                uniqueEdges[newID[i]-1][newID[v-1]-1] = true;
                numberOfEdges++;
            }
        }
    }
    simplerGraph.setNumberOfEdges(numberOfEdges);
    return simplerGraph;
}


Graph GraphUtils::kosaraju(Graph graph){
    Graph reversedGraph = reverseGraph(graph);
    stack<int> processedNodes;
    vector<int> newID(graph.getNumberOfNodes());

    for(int i=0; i<graph.getNumberOfNodes(); i++){
        if(graph.getVisited(i+1) == false){
            DFS(graph, i+1, processedNodes);
        }
    }
  
    int counter = 0;

    while(!processedNodes.empty()){
        
        if(reversedGraph.getVisited(processedNodes.top()) == false){
            counter++;
            DFS(reversedGraph, processedNodes.top(), counter, newID);
        }
        processedNodes.pop();
    }
    for(int i=0; i<graph.getNumberOfNodes(); i++){
        cout << "nó " << i+1 << " tem novo indice " << newID[i] << "\n";
    }

    return createSimplerGraph(graph, newID, counter);   
}

int GraphUtils::edgesToMakeSCC(Graph graph){
    Graph simplerGraph = kosaraju(graph);
    Graph reversedSimplerGraph = reverseGraph(simplerGraph);
    int sinkNodes = 0;
    int sourceNodes = 0;
    int isolatedNodes = 0;
    for(int i=0; i<simplerGraph.getNumberOfNodes(); i++){
        if(simplerGraph.getNeighbors(i+1).size() == 0){
            sinkNodes++;
        }
    }

    for(int i=0; i<reversedSimplerGraph.getNumberOfNodes(); i++){
        if(reversedSimplerGraph.getNeighbors(i+1).size() == 0){
            
            sourceNodes++;
        }
    }

    return max(sinkNodes, sourceNodes);  
}


        
    


