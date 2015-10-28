/*************************************************************************
	> File Name: oneforth.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
 > Link: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=145654&extra=page%3D1%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
 > Description: Given a sorted array,find occuring time more than n/4 times popular number.
	> Created Time: Tue Oct 27 18:22:09 2015
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

vector<int> findOneForth(vector<int>& myvec) {
    int d = myvec.size()/8;
    vector<int>candidate,result;
    for(int i = 0;i+d < myvec.size();i+=d)
        if(candidate.empty() || (myvec[i] == myvec[i+d] && myvec[i] != candidate.back()))
            candidate.push_back(myvec[i]);
    
    for(int i = 0;i < candidate.size();i++) {
        std::vector<int>::iterator low,up;
        low =std::lower_bound (myvec.begin(), myvec.end(), candidate[i]);
        up = std::upper_bound (myvec.begin(), myvec.end(), candidate[i]);
        int n = up - low;
        if(n >= (int)ceil(myvec.size()/4.0)) {
            result.push_back(candidate[i]);
        }
    }
    
    return result;
}

int main() {
    
    vector<int> myvec{2,2,4,4,4,4,5,6,7,8};
    
    vector<int> result = findOneForth(myvec);
    
    for(int e : result) cout << e << endl;
    
    return 0;
}