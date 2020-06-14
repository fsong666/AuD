#ifndef __ACTITY_H_
#define __ACTITY_H_
#include <vector>
using namespace std;
 
class Actity  {
private:
    vector<int> start;
    vector<int> finish;
    vector<int> A;
    int n;

public: 
    Actity() = default;
    ~Actity() = default;
    Actity(vector<int>& start_, vector<int>& finish_);
    void greedyIteration();
    void greedyRecursion(int k);
    void printSolution();
};

#endif