#ifndef __NODE_H_
#define __NODE_H_
#define MAX 100

struct Node {
    int id;
    int d = MAX;
    Node* p;


    Node()=default;
    Node(int n) : id(n), p(nullptr) {};

    bool operator==(const int b) {
        return id == b;
    }

    bool operator<(const Node* b) const {
        return d < b->d;
    }
};

#endif