#ifndef __JOHNSON_H_
#define __JOHNSON_H_
#include <vector>
#include "node.hpp"
using namespace std;

class Johnson
{
private:
    int num;
    vector<vector<pair<int, int>>> m_adj;
    vector<vector<int>> edges;
    vector<int> h;
    vector<Node*> Q;
    
public:
    Johnson(int n, vector<vector<int>>& edges_);
    ~Johnson();
    void printMat(const vector<vector<int>>& mat) const;
    void printAdj() const;
    void johnson(vector<vector<int>>& D);

private:
    void toMarix(vector<vector<int>>& D, vector<Node*>& Q, int root);
    bool bellman_ford(int root);
    void printAdj_(const vector<vector<pair<int, int>>>& m_adj) const;
};


#endif