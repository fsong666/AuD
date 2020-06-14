#include "activity.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> start = {-1, 1, 3, 0, 5, 3, 5,  6,  8,  8,  2, 12};
    vector<int> finish = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    Actity greedy(start, finish);
    greedy.greedyIteration();
    // greedy.greedyRecursion(0);
    greedy.printSolution();
    return 0;
}