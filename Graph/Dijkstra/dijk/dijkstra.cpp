#include "dijkstra.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>

Dijkstra::Dijkstra(int n, int start,  vector<vector<int> >& edges)
:m_adj(edges.size()), n(n), start(start) {   
    for (const auto edge : edges) {
        m_adj[edge[0]].emplace_back(edge[1], edge[2]);
        //m_adj[edge[1]].emplace_back(edge[0], edge[2]);
    }
    for (int i = 0; i < n; ++i) {
        Node* u = new Node(i);
        if (start == i) {
            u->d = 0;
            u->p = u;
        }
        Q.emplace_back(u);
    }
    cout << "Q.size() = " << Q.size() << endl;
}


Dijkstra::Dijkstra(vector<vector<pair<int, int>>>& m_adj_,int num , int s) 
: m_adj(m_adj_), A(), n(num), start(s) {
     for (int i = 0; i < n; ++i) {
        Node* u = new Node(i);
        if (start == i) {
            u->d = 0;
            u->p = u;
        }
        Q.emplace_back(u);
    }
}


Dijkstra::~Dijkstra(){
    for (Node* n : Q) {
        delete n;
    }
    for (Node* a : A) {
        delete a;
    }
}

int Dijkstra::dijkstra() {
    printf("dijkstra:\n");
    while (!Q.empty()) {
        auto it = std::min_element(Q.begin(), Q.end(), mycmp);
        Node* u = *it;
        A.emplace_back(u);//不是有序加入,无法用A[i]定位node
        Q.erase(it);
        // cout << "u.d: " << u->d << " u.id: " << u->id << endl;
        for (auto& pair: m_adj[u->id]) {
            auto its = find_p(Q.begin(), Q.end(), pair.first);
            if (its != Q.end()) {
                Node* v = *its;
                int w = pair.second;
                if (u->d + w < v->d) { 
                    v->p = u;       
                    v->d = u->d + w; //Dijkstra 不会累加
                    // cout << "---v.d: " << v->d << " v.id: " << v->id << endl;
                }
            }
        }
    }
    int sum = 0;
    printNodeList(A, start, sum);
    return sum;
}

void Dijkstra::dijkstra(vector<Node*>& nodeList) {
    printf("dijkstra:\n");
    while (!Q.empty()) {
        auto it = std::min_element(Q.begin(), Q.end(), mycmp);
        Node* u = *it;
        nodeList.emplace_back(u);//不是有序加入,无法用nodeList[i]定位node
        Q.erase(it);
        for (auto& pair: m_adj[u->id]) {
            auto its = find_p(Q.begin(), Q.end(), pair.first);
            if (its != Q.end()) {
                Node* v = *its;
                int w = pair.second;
                if (u->d + w < v->d) { 
                    v->p = u;       
                    v->d = u->d + w; //Dijkstra 不会累加
                }
            }
        }
    }
    int sum = 0;
    printNodeList(nodeList, start, sum);
}


bool Dijkstra::mycmp(const Node* a, const Node* b) {
    return a->d < b->d;
}

template<class InputIt, class T>
InputIt Dijkstra::find_p(InputIt first, InputIt last, const T& val) {
	while(first != last) {
		if (**first == val) return first;
		++first;
	}
	return last;
}

void Dijkstra::printNodeList(vector<Node*>& nodeList, const int root, int&sum) { 
    printf("--------printNodeList root=%d:\n", root);
    for (const auto& u : nodeList) {
        if (u == nullptr) {
            printf(" u is null!");
            continue;
        } 
        printf("%d.d=%2d ", u->id, u->d);
        sum += u->d;
        if (!u->p)  continue;
        printPath(nodeList, root, u->id);
        printf("\n");
    }
    printf("sum=%d\n", sum);
}

void Dijkstra::printPath(vector<Node*>& nodeList, int i, int j) {
    if (i == j) {
        printf("%d->", i);
        return;
    } else {
        auto it = find_p(nodeList.begin(), nodeList.end(), j);
        if (it == nodeList.end()) {
            printf("no path");//不是连通图
            return;
        }else {
            printPath(nodeList, i, (*it)->p->id);
            printf("%d->", j);
        }
    }
}