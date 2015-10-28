/*************************************************************************
	> File Name: pickGame.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Oct 27 16:56:05 2015
 > Description: Given an array of int, two people can only pick at the beginning or end, if you go first how to get maximum sum.
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

map<pair<int, int>, int> mymap;

int rungame(vector<int>& myvec,int i, int j)
{
    if(mymap.count(make_pair(i,j)) > 0) return mymap[make_pair(i,j)];
    if(j-1 == i) return max(myvec[i], myvec[j]);
    
    int v1 = rungame(myvec,i+1,j-1)+myvec[i];
    int v2 = rungame(myvec,i+2,j)+myvec[i];
    
    int v3 = rungame(myvec,i+1,j-1)+myvec[j];
    int v4 = rungame(myvec,i,j-2)+myvec[j];
    
    int q1 = min(v1,v2);
    int q2 = min(v3,v4);
    
    int v = max(q1,q2);
    
    mymap[make_pair(i,j)] = v;
    
    return v;
}


int main() {
    
    vector<int> myvec{2,5,1,1,10,1};
    
    cout << rungame(myvec, 0, myvec.size()-1);
    
    return 0;
}
