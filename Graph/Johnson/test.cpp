#include "johnson.hpp"
#include <iostream>
#include <vector>
#include "dijkstra.hpp"

int main () {
    int num = 5;
    vector<vector<int>> edges = {{1, 2, 3}, {1, 5, -4}, {1, 3, 8},
                                 {2, 4, 1}, {2, 5, 7},
                                 {3, 2 ,4}, 
                                 {4, 1, 2}, {4, 3, -5},
                                 {5, 4, 6}, };
    Johnson john(num, edges);
    john.printAdj();
    vector<vector<int>> D(num, vector<int>(num, 0));
    john.johnson(D);
    printf("change to origin mat:\n");
    john.printMat(D);
    return 0;
}