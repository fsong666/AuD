#include "huffman.hpp"
#include <iostream>
using namespace std;

Huffman::Huffman(priority_queue<Node*, vector<Node*>, MyComparison> Q_) : Q(Q_), root(nullptr) {

}

Huffman::~Huffman() {
   deleteP(root);
}

void Huffman::deleteP(Node* node) {
    if (!node) return;
    deleteP(node->left);
    deleteP(node->right);
    delete node;
}

void Huffman::printQ() {
    auto q = Q;
    while(!q.empty()) {
        Node* p = q.top();
        q.pop();
        // printf("(%s, %d) ", p->name, p->val); string对象不能通过printf输出
        cout << "(" << p->name << "," << p->val << ") ";
    }
    cout<< endl;
}

/**
 * 自底向上的迭代贪心算法，先从出现频率最小的字符开始编译，直到最大频率编译.
*/
void Huffman::greedy() {
    int len = Q.size();
    for (int i = 0; i < len - 1; ++i) {
        Node* n = new Node();
        if (i == len - 2)
            root = n;
        auto p1 = Q.top(); //选择 最小频率
        Q.pop();
        n->left = p1;
        auto p2 = Q.top();
        Q.pop();
        n->right = p2;
        n->val = p1->val + p2->val;
        Q.push(n);
    }
}

void Huffman::printCode() {
    printf("root.freq= %d\n", root->val);
    string s = "";
    printCode_(root, s);

}
void Huffman::printCode_(Node* node, string code) {
    if (!node->left && !node->right) {
        cout << "(" << node->name << "," << node->val << ") = " << code << endl;
        return;
    }
    if (node->left != nullptr)
        printCode_(node->left, code + "0");
    if (node->right != nullptr)
        printCode_(node->right, code + "1");
}