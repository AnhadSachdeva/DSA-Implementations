#include <iostream>

#include "UnionFind.h"

using namespace std;



int main(){
    vector<int> nodes = {1,2,3,4,5,6};
    UnionFind* disjointSet = new UnionFind(nodes);
    
    disjointSet->unionfy(1,2);
    disjointSet->unionfy(3,4);
    disjointSet->unionfy(5,6);

    /*
    Now this should output
    1 <- 2, 3 <- 4, 5 <- 6
    */
   cout << disjointSet->find(2) << endl;
   cout << disjointSet->find(4) << endl;
   cout << disjointSet->find(6) << endl;

    disjointSet->unionfy(4,5);
    //  3
    // 4,5
    //  ,6
    cout << disjointSet->find(6) << endl;

    disjointSet->unionfy(6,2);
     //  3
    // 4,5 1
    //  ,6, 2
    cout << disjointSet->find(2) << endl;
  
    return 0;
}