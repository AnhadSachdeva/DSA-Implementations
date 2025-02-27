#include <iostream>

#include "Dfs.h"
#include "Bfs.h"

using namespace std;


int main(){
    unordered_map<int,vector<int>> adjList = {
        {0, {1, 3}},
        {1, {0, 2, 4}},
        {2, {1}},
        {3, {0, 4}},
        {4, {1, 3}}
    };

    BFS* bfs = new BFS();
    bfs->iterativeBFS(adjList,2);
    bfs->recursiveBFS(adjList,2);

    DFS* dfs = new DFS();
    dfs->iterativeDFS(adjList,2);
    dfs->recursiveDFS(adjList,2);

    return 0;
}