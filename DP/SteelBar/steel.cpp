#include "steel.hpp"
#include <iostream>

SteelBar::SteelBar(int n_) : n(n_), r(n_ + 1, INT32_MIN), s(n_ + 1, 0) {
}
SteelBar::SteelBar() {
}

SteelBar::~SteelBar(){ 
}

void SteelBar::boot_up_cut() {
    r[0] = 0; // 最优子结构的初始化
    for (int j = 1; j <= n; ++j) { // 长度为j的钢条
        int max_value = INT32_MIN;
        for (int i = 1; i <= j; ++i) { //在j钢条里选择第i点切割
            if (max_value < p[i - 1] + r[j - i]) {
                max_value = p[i - 1] + r[j - i];
                s[j] = i; // 在j长度下，存入切割位置
            }
        }
        r[j] = max_value;
    }
}

int SteelBar::up_boot_cut(int n) {
    if (r[n] >= 0)
        return r[n];
    int max_value = 0;
    if (n == 0)
        max_value = 0;
    else {
        int temp = -1;
        for (int i = 1; i <= n; ++i) {
            temp = p[i - 1] + up_boot_cut(n - i);
            if (max_value < temp) {
                max_value = temp;
                s[n] = i;
            }
        }
    }
    r[n] = max_value;
    return r[n];
}

void SteelBar::print_solution() {
    if (n > 10) {
        printf("input number greater than 10");
        return;
    }
    boot_up_cut();
    // up_boot_cut(n);
    printf("%2d r= %2d: ", n, r[n]);
    while (n > 0) {
        printf("%d, ", s[n]);
        n = n - s[n];    
    }
    printf("\n");
}