#include <iostream>
#include <vector>
#include <queue>
#include "prim.hpp"
using namespace std;

int main (void) {
    vector<vector<int>> edges = { {2, 0, 3}, {1, 0, 4}, {1, 2, 8},
      {2, 3, 1}, {0, 3, 2}, {3, 4, 4}, {0, 4, 12}};
    int root = 1;
    Prim g_prim(5, root, edges); 
          

    cout << "sum= " << g_prim.prim() << endl;
    return 0;
}