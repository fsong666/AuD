#include "activity.hpp"
#include <iostream>
using namespace std;
Actity::Actity(vector<int>& start_, vector<int>& finish_) 
: start(start_), finish(finish_), n(start_.size() - 1)
{

}

void Actity::greedyIteration() {
    A.emplace_back(1);
    int k = 2;
    for (int m = 2; m <= n; ++m) {
        if (start[m] >= finish[k]) { //从活动(k, n]中找到，结束时间最早的活动m
            A.emplace_back(m);
            k = m; // 更新 查找活动范围
        }
    }
}

void Actity::greedyRecursion(int k) {
    int m = k + 1;
    while (m <= n && start[m] < finish[k])
        ++m;
    if (m <= n) {
        A.emplace_back(m);
        greedyRecursion(m);
    } 
}

void Actity::printSolution() {
    for (const int n : A) {
        printf("%d, ", n);
    }
    printf("\n");
}