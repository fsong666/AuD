#ifndef _PRIM_H_
#define _PRIM_H_
#include <iostream>
#include <vector>
#include "node.hpp"

using namespace std;


class Dijkstra
{
private:
    vector<vector<pair<int, int>>> m_adj;
    vector<Node*> Q;
    vector<Node*> A;
    int n;
    int start;

public:
    Dijkstra( vector<vector<pair<int, int>>>& m_adj_, int num, int s);
    Dijkstra(int n, int start, vector<vector<int>>& edges);
    ~Dijkstra();
    int dijkstra();
    void dijkstra(vector<Node*>& A);
    void printNodeList(vector<Node*>& nodeList, const int root,  int& sum);
    
private:
    template<class InputIt, class T>
    InputIt find_p(InputIt first, InputIt last, const T& val);
    static bool mycmp (const Node* a, const Node* b);
    void printPath( vector<Node*>& nodeList, int i, int j);

};

#endif