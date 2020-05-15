#include "floyd.hpp"
#include <iostream>
#include <vector>

int main () {
    int num = 5;
    vector<vector<int>> edges = {{1, 2, 3}, {1, 5, -4}, {1, 3, 8},
                                 {2, 4, 1}, {2, 5, 7},
                                 {3, 2 ,4}, 
                                 {4, 1, 2}, {4, 3, -5},
                                 {5, 4, 6}, };
    Floyd  floyd(num, edges);
    floyd.printM();
    floyd.printP();
    floyd.floyd_warshall2();
    floyd.printM();
    floyd.printP();
    floyd.printAllPath();
    
    return 0;
}