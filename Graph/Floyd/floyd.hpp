#ifndef __FLOYD_HPP__
#define __FLOYD_HPP__
#include <vector>
using namespace std;

class Floyd
{
private:
    int num;
    vector<vector<int>> M;
    vector<vector<int>> P;

public:
    Floyd(const int n_, const vector<vector<int>>& edges);
    ~Floyd();
    void printM() const;
    void printP() const;
    void printAllPath() const;
    void floyd_warshall(vector<vector<int>>& D, vector<vector<int>>& P_);
    void floyd_warshall2();

private:
    void printMat(const vector<vector<int>>& mat) const;
    void printPath(const int i, const int j) const;

};

#endif