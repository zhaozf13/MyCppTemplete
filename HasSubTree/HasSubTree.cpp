// HasSubTree.cpp : 
// 判断A树是否包含B树的全部拓扑结构，即不一定完全相同，只要包含即可，认为NULL不是A树的子结构

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    bool check(TreeNode* h, TreeNode* t2) {
        if (t2 == NULL) {//相当于t2遍历完了，没出现不等于的情况，即符合上了
            return true;
        }
        if (h == NULL || h->val != t2->val) {
            return false;
        }
        return check(h->left, t2->left) && check(h->right, t2->right);//先序遍历对比
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL) {
            return false;
        }
        if (pRoot2 == NULL) {
            return false;
        }
        //先序遍历去检查，检查完pRoot1，递归检查子树是否包含
        return check(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};



