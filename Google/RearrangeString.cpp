/*************************************************************************
	> File Name: RearrangeString.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
    > Link: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=141400&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26sortid%3D311
	> Created Time: Sun Nov  8 00:07:38 2015
 ************************************************************************/
#include<iostream>
using namespace std;

int a[256] = {0};

string Build(string s, int k) {
    
    for(auto e : s)
        a[e]++;
    
    string res(s.length(), '-');
    int cur(0);
    
    for(int i = 0;i < 256;i++) {
        int maxi(-1);
        int maxv(INT_MIN);
        
        for(int j = 0;j < 256;j++) {
            if(a[j] == 0) continue;
            if(a[j] > maxv) {
                maxi = j;
                maxv = a[j];
            }
        }
        
        if(maxi < 0) break;
        
        while(res[cur] != '-') cur++;
        for(int t = 0;t < maxv;t++) {
            if(cur + t * k >= s.length()) {cout << "could not build the string << endl"; return "";}
            res[cur + t * k] = maxi;
        }
        
        a[maxi] = 0;
    }
    
    return res;
}

int main() {
    cout << Build("aabbccc", 3) << endl;
    cout << Build("aabbccc", 4);
}
