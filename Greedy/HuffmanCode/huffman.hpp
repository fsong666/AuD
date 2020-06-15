#ifndef __HUFFMAN_H
#define __HUFFMAN_H
#include <queue> 
#include <string> 
#include <vector> 
using namespace std;

struct Node {
    string name;
    int val; //每个字符出现的频率
    Node* left;
    Node* right;

    Node() : name(""), val(0), left(nullptr), right(nullptr){};
    Node(string str, int n) : name(str), val(n),left(nullptr), right(nullptr){};
};

class MyComparison {
public:
    MyComparison() = default;
    bool operator()(const Node* a, const Node* b) {
        return a->val > b->val;
    }
};

class Huffman {
private:
    //容器元素是指针，使用heap上的内存，为了避免拷贝对象和原对象析构时多次delete指针，所以阻止拷贝
    priority_queue<Node*, vector<Node*>, MyComparison> Q;
    Node* root;
public:
    Huffman() = default;
    Huffman(priority_queue<Node*, vector<Node*>, MyComparison> Q_);
    Huffman(const Huffman& other) = delete;
    Huffman& operator=(const Huffman& other) = delete;
    ~Huffman();

    void printQ();
    void greedy();
    void printCode();

private:
    void deleteP(Node* node);
    void printCode_(Node* node, string code);
};



#endif