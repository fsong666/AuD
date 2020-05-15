#ifndef _PRIM_H_
#define _PRIM_H_
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
    int id;
    int key = INT32_MAX;//每个节点到MST最小边的权重值
    Node* p;

    Node()=default;
    Node(int n) : id(n), p(nullptr) {};

    bool operator==(const int b) {
        return id == b;
    }

    bool operator<(const Node* b) const {
        return key < b->key;
    }
};


class Prim
{
private:
    vector<vector<pair<int, int>>> m_adj;
    vector<Node*> Q;
    vector<Node*> A;
    int n;
    int start;

public:
    Prim(int n, int start, vector<vector<int>>& edges);
    ~Prim();
    int prim();
    int prim2();

private:
    template<class InputIt, class T>
    InputIt find_p(InputIt first, InputIt last, const T& val);
    static bool mycmp (const Node* a, const Node* b);

};

#endif