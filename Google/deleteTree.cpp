/*************************************************************************
	> File Name: deleteTree.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
 > Link: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=146431&extra=page%3D1%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
 > Description: 给一个删除树节点的函数，和root，怎么遍历删除整棵树
	> Created Time: Mon Nov  2 19:05:57 2015
 ************************************************************************/
#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _v):val(_v){}
};

void deleteTree(TreeNode* root) {
    stack<TreeNode*> mystack;
    mystack.push(root);
    TreeNode* cur = root;
    if(!root) return;
    
    while(!mystack.empty()) {
        while(cur && cur->left) {
            mystack.push(cur->left);
            cur = cur->left;
        }
        
        cur = mystack.top();
        mystack.pop();
        TreeNode* deletenode = cur;
        cur = cur->right;
        delete deletenode;
        if(cur) mystack.push(cur);
    }
}

int main() {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(1);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(1);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    
    deleteTree(n1);
    return 0;
}
