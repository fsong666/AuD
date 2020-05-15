#include "prim.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>

Prim::Prim(int n, int start,  vector<vector<int> >& edges)
:m_adj(edges.size()), n(n), start(start) {   
    for (const auto edge : edges) {
        m_adj[edge[0]].emplace_back(edge[1], edge[2]);
        m_adj[edge[1]].emplace_back(edge[0], edge[2]);
    }
    for (int i = 0; i < n; ++i) {
        Node* u = new Node(i);
        if (start == i) {
            u->key = 0;
            u->p = u;
        }
        Q.emplace_back(u);
    }
    cout << "Q.size() = " << Q.size() << endl;
}


Prim::~Prim(){
}

int Prim::prim() {
    while (!Q.empty()) {
        auto it = std::min_element(Q.begin(), Q.end(), mycmp);
        Node* u = *it;
        A.emplace_back(u);
        Q.erase(it);
        cout << "u.key: " << u->key << " u.id: " << u->id << endl;
        for (auto& pair: m_adj[u->id]) {
            auto its = find_p(Q.begin(), Q.end(), pair.first);
            if (its != Q.end()) {
                Node* v = *its;
                int uv_w = pair.second;
                //if (u->key + uv_w < v->key) { 
                if (uv_w < v->key) { 
                    v->p = u;       
                    v->key = uv_w; //更新到MST最小边权重,不会累加
                    //v->key = u->key + uv_w; //Dijkstra 不会累加
                }
            }
        }
    }
    int sum = 0;
    for (const Node* u : A) {
       // cout << "A u.key: " << u->key << ". " << u->p->id << "->"<< u->id<< endl;
        printf("A %d.key: %d  path:%d->%d\n", u->id, u->key, u->p->id, u->id);
        sum += u->key;
    }
    return sum;
}

bool Prim::mycmp(const Node* a, const Node* b) {
    return a->key < b->key;
}

template<class InputIt, class T>
InputIt Prim::find_p(InputIt first, InputIt last, const T& val) {
	while(first != last) {
		if (**first == val) return first;
		++first;
	}
	return last;
}
