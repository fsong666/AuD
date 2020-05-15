#include "johnson.hpp"
#include <iostream>
#include <vector>
#include "dijkstra.hpp"

Johnson::Johnson(int n, vector<vector<int>>& edges_)
: num(n + 1), m_adj(edges_.size()), edges(edges_), h(n + 1, 0){
    for (const auto edge : edges) {
        m_adj[edge[0]].emplace_back(edge[1], edge[2]);
    }

    for (int i = 0; i < num; ++i) {
        Q.emplace_back(new Node(i));
        if (i > 0) {
            m_adj[0].emplace_back(i, 0);
        }
    }
    cout << "Q.size() = " << Q.size() << endl;
}

Johnson::~Johnson() {
}

void Johnson::printAdj_(const vector<vector<pair<int, int>>>& m_adj) const {
    printf("m_adj:\n");
    for (int i = 0; i < num; ++i) {
        for (const auto& edge : m_adj[i]) {
            printf("%10d~%2d ", edge.first, edge.second);
        }
        printf("\n");
    }
}

void Johnson::printAdj() const {
    printAdj_(m_adj);
}

void Johnson::printMat(const vector<vector<int>>& mat) const {
    int num = mat.size();
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            printf("%10d ", mat[i][j]);
        }
        printf("\n");
    }
}

bool Johnson::bellman_ford(int root) {
    /*
    1. 判断有无负权重环
    2. 获得h(v) = 即从0节点到其他节点的最短距离值　
    */
    Q[root]->d = 0;
    Q[root]->p = Q[root];
    printf("bellman_ford:\n");
    for (int i = 0; i < num - 1; ++i) {// |V| - 1次
        for (int j = 0; j < num; ++j) {
            for (const auto& edge : m_adj[j]) {
                const int u = j, v = edge.first, w = edge.second;
                if (Q[v]->d > Q[u]->d + w) {
                    Q[v]->d = Q[u]->d + w;
                    Q[v]->p = Q[u];
                }
            }
        }
    }
    for (int j = 0; j < num; ++j) {
        h[j] = Q[j]->d;
        for (const auto& edge : m_adj[j]) {
            const int u = j, v = edge.first, w = edge.second;
            if (Q[v]->d > Q[u]->d + w) {
                printf("cycle with negative weight!\n");
                return false;
            }
        }
    }
    return true;
}

void Johnson::johnson(vector<vector<int>>& D) {
    if (!bellman_ford(0)) {
        return;
    }
    printf("m_adj without negative:\n");
    for (int i = 0; i < num; ++i) {
        for (auto& edge : m_adj[i]) {
            const int u = i, v = edge.first, w = edge.second;
            edge.second = w + h[u] - h[v];//转化成非负权重
            printf("%10d~%2d ", v, edge.second);
        }
        printf("\n");
    }
    for (int i = 1; i < num; ++i) {
        Q[i]->d = 0;
        Q[i]->p = Q[i];
        vector<Node*> out;
        Dijkstra dij(m_adj, num,  i);
        dij.dijkstra(out);
        toMarix(D, out, i);
    }
}

void Johnson::toMarix(vector<vector<int>>& D, vector<Node*>& Q, int root) {
     int hu = h[root];
     for (const Node* v : Q) {
        if (v->id == 0)    continue;
        int d = v->d + h[v->id] - hu;//还原原始的最短权重值
        D[root - 1][v->id - 1] = d;//D矩阵从0开始索引
    }
}
 
