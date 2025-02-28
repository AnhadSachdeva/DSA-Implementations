#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TopologicalSort{
    public:
    // Given a directed acyclic graph (DAG) as an adjacency list, return a valid topological order of nodes using depth-first search (DFS).
    vector<int> topologicalSortDFS(unordered_map<int, vector<int>>& graph) {
        
    }


    // Given a DAG and the in-degree of each node, return a topological order using Kahn’s algorithm (BFS-based approach).
    vector<int> topologicalSortKahn(unordered_map<int, vector<int>>& graph, vector<int>& inDegree) {

    }

    // Determine if a directed graph contains a cycle starting from a given node, using DFS with a recursion stack to track nodes in the current path.
    bool hasCycleDFS(unordered_map<int, vector<int>>& graph, int node, unordered_set<int>& visited, unordered_set<int>& recStack) {

    }
};

#endif
