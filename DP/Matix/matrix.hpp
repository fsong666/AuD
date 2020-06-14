#ifndef __STEEL_H
#define __STEEL_H
#include <vector>
using namespace std;

struct Mat {
    int row;
    int col;
    Mat() : row(0), col(0) {}
    Mat(int r, int c) : row(r), col(c) {}
    Mat(const Mat& x) : row(x.row), col(x.col) {}
    Mat& operator=(const Mat& x) {
    	row = x.row;
    	col = x.col;
    	return *this;
    }

};


class Matrix
{
private:
    int n;
    vector<Mat> A; // 每个长度能取得的最大收益数组
    vector<vector<int>> m;
    vector<vector<int>> s;
    
public:
    Matrix() = default;
    ~Matrix() = default;
    Matrix(vector<Mat>& A_);
    void print_solution(int i, int j);
    void print_A(); 
    void boot_up_cut();

};


#endif