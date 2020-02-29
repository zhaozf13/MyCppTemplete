// ReConstructBinaryTree.cpp : 
// 根据二叉树的先序遍历和中序遍历重建二叉树
// 先序遍历和中序遍历的结果以数组形式给出，假设不含重复元素

#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int in_size = vin.size();
        if (in_size == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int gen = 0;
        for (int i = 0; i < in_size; i++) {
            if (vin[i] == pre[0]) {
                gen = i;
                break;
            }
        }
        vector<int> left_pre, left_in, right_pre, right_in;
        for (int i = 0; i < gen; i++) {
            left_pre.push_back(pre[i + 1]);
            left_in.push_back(vin[i]);
        }
        for (int j = gen + 1; j < in_size; j++) {
            right_pre.push_back(pre[j]);
            right_in.push_back(vin[j]);
        }
        root->left = reConstructBinaryTree(left_pre, left_in);
        root->right = reConstructBinaryTree(right_pre, right_in);
        return root;
    }
};


