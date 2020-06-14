#include "matrix.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<Mat> A_;
    A_.emplace_back(Mat(30, 35));
    A_.emplace_back(Mat(35, 15));
    A_.emplace_back(Mat(15, 5));
    A_.emplace_back(Mat(5, 10));
    A_.emplace_back(Mat(10, 20));
    A_.emplace_back(Mat(20, 25));
    Matrix m(A_);
    m.print_A();
    m.boot_up_cut();
    m.print_solution(1, 6);
    printf("\n");
    return 0;
}