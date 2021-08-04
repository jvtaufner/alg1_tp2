#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "./graph.hpp"
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <utility>


using namespace std;

class GraphUtils{

    public:

    static Graph reverseGraph(Graph graph);
    static void DFS(Graph &graph, int node);
    static void DFS(Graph &graph, int node, stack<int> &dfsFinishOrder);
    static void DFS(Graph &graph, int node, int counter, vector<int> &newID);
    static Graph createSimplerGraph(Graph graph, vector<int> newID, int newSize);
    static Graph kosaraju(Graph graph);
    static int edgesToMakeSCC(Graph graph);

};

#endif