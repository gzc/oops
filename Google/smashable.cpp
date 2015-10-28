/*************************************************************************
	> File Name: smashable.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
 > Link: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=145654&extra=page%3D1%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
 > Description: 给一个词典和一个target word,问这个word是不是smashable. smashable的定义是这个词在字典里并且它不停地任意删除一个字母得到的单词也在词典里.
	> Created Time: Tue Oct 27 21:44:50 2015
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

bool isSmashable(set<string> &dictionary, map<string, bool> &mymap, string word) {
    
    if(mymap.count(word) > 0) return true;
    if(dictionary.count(word) == 0) return false;
    if(word.length() == 1) return true;
    
    for(int i = 0;i < word.length();i++) {
        string temp = word.substr(0, i) + word.substr(i+1);
        bool f = isSmashable(dictionary, mymap, temp);
        if(!f) return false;
    }
    
    mymap[word] = true;
    return true;
}


int main() {
    
    string word = "eye";
    string data[6]= {"e","y","ye","ey","ee","eye"};
    set<string> dictionary (data,data+6);
    map<string, bool> mymap;
    
    bool f = isSmashable(dictionary, mymap, word);
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
