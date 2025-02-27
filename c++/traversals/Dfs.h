#ifndef DFS_H
#define DFS_H

#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*


*/

class DFS {

    public:
    // Assuming given an adjList
    // print the traversals
    void iterativeDFS(unordered_map<int,vector<int>>& adjList, int start){
        unordered_set<int> visited;
        stack<int> st;
        st.push(start);

        while(!st.empty()){

            int node = st.top();
            st.pop();

            if(visited.count(node) == 0){
                visited.insert(node);
                cout << node << ' ';

                for(int i = adjList[node].size()-1; i >= 0; --i){
                    if(visited.count(adjList[node][i]) == 0){
                        st.push(adjList[node][i]);
                    }
                }
            }
        }

        cout << endl;


    }

    void recursiveDFSHelper(unordered_map<int,vector<int>>& adjList, unordered_set<int>& visited, int start){
        visited.insert(start);
        cout << start << ' ';

        for(auto& neighbor : adjList[start]){
            if (visited.count(neighbor) == 1){
                continue;
            }
            recursiveDFSHelper(adjList,visited,neighbor);
            
        }

    }


    void recursiveDFS (unordered_map<int,vector<int>> adjList, int start){
        unordered_set<int> visited;
        recursiveDFSHelper(adjList,visited,start);
        cout << endl;
        return;

    }
};


#endif