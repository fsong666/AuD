#include "floyd.hpp"
#include <bits/stdc++.h>
#include <algorithm> 
#define MAX 100

Floyd::Floyd(const int n_, const vector<vector<int>>& edges_)
: num(n_), M(n_ + 1, vector<int>(n_ + 1, MAX)), P(n_ + 1, vector<int>(n_ + 1, MAX)) {
    for (const auto& edge : edges_) {
        const int u = edge[0], v = edge[1], w = edge[2];
        M[u][v] = w;
        P[u][v] = u;
    }
    for (int i = 1; i <= n_; ++i)
        M[i][i] = 0; 
}

Floyd::~Floyd() {
}

void Floyd::printMat(const vector<vector<int>>& mat) const {
    printf("mat:\n");
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            printf("%10d ", mat[i][j]);
        }
        printf("\n");
    }
}

void Floyd::printM() const {
    printf("M:\n");
    printMat(M);
}

void Floyd::printP() const {
    printf("P:\n");
    printMat(P);
}

void Floyd::floyd_warshall(vector<vector<int>>& D, vector<vector<int>>& P_) {
    D = M;
    P_ = P;
    for (int k = 1; k <= num; ++k) {
       vector<vector<int>> D_k(num + 1, vector<int>(num + 1, 0));
       vector<vector<int>> P_k(num + 1, vector<int>(num + 1, 0));
       for (int i = 1; i <= num; ++i) {
           for (int j = 1; j <= num; ++j) {
               if (D[i][j] <= D[i][k] + D[k][j]) {
                   D_k[i][j] = D[i][j];
                   P_k[i][j] = P_[i][j];
               }else {
                   D_k[i][j] = D[i][k] + D[k][j];
                   P_k[i][j] = P_[k][j];
               }
            //    D_k[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
           }
       }
    D = D_k;
    P_ = P_k;
    }
}

void Floyd::floyd_warshall2() {
    for (int k = 1; k <= num; ++k) {
       for (int i = 1; i <= num; ++i) {
           for (int j = 1; j <= num; ++j) {
               if (M[i][j] > M[i][k] + M[k][j]) {
                    M[i][j] = M[i][k] + M[k][j];
                    P[i][j] = P[k][j];
               }
           }
       }
    }
}

void Floyd::printPath(const int i, const int j) const {
    if (i == j) {
        printf("%d->", i);
        return;
    } else if (P[i][j] == MAX) {
        printf("no path");//不是连通图
        return;
    }
    
    printPath(i, P[i][j]);
    printf("%d->", j);
}

void Floyd::printAllPath() const {
    for (int i = 1; i <=num; ++i) {
        for (int j = 1; j <=num; ++j) {
            printPath(i, j);
            printf("\n");
        }
    }
}
