/*************************************************************************
	> File Name: frog.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Thu Nov 12 23:28:25 2015
 ************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

int Jump(int *a, int n, int j, int width) {
    int *w = new int[width+1];
    int *earliest = new int[width+1];
    for(int i = 0;i <= width;i++) w[i] = -1;
    for(int i = 0;i <= width;i++) earliest[i] = INT_MAX;
    earliest[0] = 0;
    
    deque<int> myqueue;
    myqueue.push_back(0);
    
    for(int i = 0;i < n;i++) {
        w[a[i]] = i+1;
    }
    
    for(int i = 1;i <= width;i++) {
        if(myqueue.front()+ j < i) myqueue.pop_front();
        if(myqueue.front() + j >= width) return earliest[myqueue.front()];
        if(w[i] != -1) {
            earliest[i] = max(earliest[myqueue.front()], w[i]);
            while(earliest[i] <= earliest[myqueue.back()]) myqueue.pop_back();
            myqueue.push_back(i);
        }
    }
    return earliest[width];
}


int main() {
    
    int a[7] = {8,5,9,7,2,4};
    
    cout << Jump(a, 6, 3, 10);
    
    return 0;
}