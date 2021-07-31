#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "./graph.hpp"
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

class GraphUtils{

    public:

    static Graph reverseGraph(Graph graph);
    static void DFS(Graph &graph, int node);
    static void DFS(Graph &graph, int node, stack<int> &dfsFinishOrder);
    //static Graph kosaraju(Graph graph);
    //static int edgesToMakeSCC(Graph graph);

};

#endif