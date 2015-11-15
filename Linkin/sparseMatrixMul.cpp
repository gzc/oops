/*************************************************************************
	> File Name: sparseMatrixMul.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sat Nov 14 23:00:06 2015
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#include<unordered_map>
#include<climits>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row1 = A.size();
        int col1 = A[0].size();
        int row2 = B.size();
        int col2 = B[0].size();
        
        vector<vector<int>> res(row1, vector<int>(col2, 0));
        
        for(int i = 0;i < row1;i++) {
            for(int j = 0;j < col2;j++) {
                for(int k = 0;k < col1;k++) {
                    res[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row1 = A.size();
        int col1 = A[0].size();
        int row2 = B.size();
        int col2 = B[0].size();
        
        vector<vector<int>> res(row1, vector<int>(col2, 0));
        vector<unordered_map<int,int>> CacheB(col2);
        
        for(int i = 0;i < row2;i++)
            for(int j = 0;j < col2;j++)
                if(B[i][j] != 0)
                    CacheB[j][i] = B[i][j];
        
        for(int i = 0;i < row1;i++) {
            for(int j = 0;j < col2;j++) {
                unordered_map<int, int> right = CacheB[j];
                if(right.size() == 0) continue;
                for(int k = 0;k < col1;k++) {
                    if(A[i][k] != 0 && right.count(k) > 0) {
                        res[i][j] += A[i][k] * right[k];
                    }
                }
            }
        }
        
        return res;
    }
};



int main() {
    Solution2 s;
    vector<int>v1 = {0,1};
    vector<int>v2 = {0,0};
    vector<int>v3 = {0,1};
    vector<int>v4 = {1,0};
    vector<int>v5 = {1,0};
    vector<vector<int>>A{v1,v2,v3};
    vector<vector<int>>B{v4,v5};
    
    s.multiply(A, B);
    
    return 0;
}