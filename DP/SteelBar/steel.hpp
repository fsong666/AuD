#ifndef __STEEL_H
#define __STEEL_H
#include <vector>
using namespace std;

class SteelBar
{
private:
    const int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n;
    vector<int> r; // 每个长度能取得的最大收益数组
    vector<int> s;
    
public:
    SteelBar(int n_);
    SteelBar();
    ~SteelBar();
    void print_solution();
private:
    void boot_up_cut();
    int up_boot_cut(int n);

};


#endif