#include <iostream>
#include <vector>
#include <queue>
#include "dijk/dijkstra.hpp"
//#include "dijkstra.hpp"
using namespace std;

int main (void) {
    int num = 5;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 3, 5},
                                 {1, 3, 2},  {1, 2, 1}, 
                                 {2, 4, 4}, 
                                 {3, 1, 3},  {3, 4, 2},
                                 {4, 0, 7},  {4, 2, 6},
                                 };
    int start = 0;
    Dijkstra g_dijkstra(num, start, edges); 
    g_dijkstra.dijkstra();
  
    return 0;
}