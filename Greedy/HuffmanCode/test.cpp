#include "huffman.hpp"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main () {
    priority_queue<Node*, vector<Node*>, MyComparison> Q;
    Q.push(new Node("a", 45));
    Q.push(new Node("b", 13));
    Q.push(new Node("c", 12));
    Q.push(new Node("d", 16));
    Q.push(new Node("e", 9));
    Q.push(new Node("f", 5));

    Huffman huffmanCode(Q);
    huffmanCode.printQ();
    huffmanCode.greedy();
    huffmanCode.printCode();
    return 0;
}