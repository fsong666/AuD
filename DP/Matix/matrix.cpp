#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(vector<Mat>& A_) 
: n(A_.size()), A(A_), m(n + 1, vector<int>(n + 1, 0)), s(n + 1, vector<int>(n + 1, 0)) {
}

void Matrix::boot_up_cut() {
    for (int l = 2; l <= n; ++l) {  // length of window
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT32_MAX;
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + A[i - 1].row * A[j - 1].col * A[k - 1].col;
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }  
        }
    }
}

void Matrix::print_solution(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        print_solution(i, s[i][j]);
        print_solution(s[i][j] + 1, j);
        printf(")");
    }
}

void Matrix::print_A() {
    printf("input:");
    for (int i = 0; i < n; ++i) {
        printf("A%d=(%d, %d)", i, A[i].row, A[i].col);
    }
    printf("\n");
}