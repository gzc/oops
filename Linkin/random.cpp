/*************************************************************************
	> File Name: random.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Wed Nov 11 21:11:20 2015
 ************************************************************************/
#include<iostream>
using namespace std;

void random(int* a, int n) {
    for(int i = 0;i < n;i++) {
        int r = rand() % n;
        swap(a[i], a[r]);
    }
}

int main() {

    int a[5] = {1,2,3,4,5};
    random(a, 5);
    for(int i = 0;i < 5;i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
