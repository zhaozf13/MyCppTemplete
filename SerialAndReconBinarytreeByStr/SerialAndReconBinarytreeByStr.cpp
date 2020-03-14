// SerialAndReconBinarytreeByStr.cpp : 
// 二叉树的序列化成字符串，与利用字符串重建二叉树
// 用两种方法实现：1.先序遍历 2.层序遍历

#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

//先序遍历的方法将二叉树序列化，规定节点值末尾为“！”，空节点为“#”
string serialByPre(TreeNode* root) {
    if (root == NULL) {
        return "#!";
    }
    string res_str = to_string(root->val);
    res_str.append("!");
    res_str += serialByPre(root->left);
    res_str += serialByPre(root->right);
    return res_str;
}

int index = -1;
TreeNode* reconPreOrder(vector<int> reconStr) {
    index++;
    int temp = reconStr[index];
    if (temp == INT_MIN) {
        return NULL;
    }
    TreeNode* root = new TreeNode(temp);
    root->left = reconPreOrder(reconStr);
    root->right = reconPreOrder(reconStr);
    return root;
}

TreeNode* reconByPreString(string preStr) {
    vector<int> reconStr;
    string tempStr;
    int i = 0;
    while (i < preStr.size()) {
        if (preStr[i] == '!') {
            if (tempStr != "") {
                int iTemp = atoi(tempStr.c_str());
                reconStr.push_back(iTemp);
                /*stringstream ss;
                int iTemp;
                ss << tempStr;
                ss >> iTemp;
                reconStr.push_back(iTemp);*/
                tempStr.clear();
            }
            i++;
        }
        else if (preStr[i] == '#') {
            reconStr.push_back(INT_MIN);
            i++;
        }
        else {
            tempStr += preStr[i];
            i++;
        }
    }
    return reconPreOrder(reconStr);
}

//class Solution {
//public:
//    vector<int> buf;
//    void dfs1(TreeNode* root) {
//        if (!root) buf.push_back(0xFFFFFFFF);
//        else {
//            buf.push_back(root->val);
//            dfs1(root->left);
//            dfs1(root->right);
//        }
//    }
//    char* serialByPre(TreeNode* root) {
//        buf.clear();
//        dfs1(root);
//        int bufSize = buf.size();
//        int* res = new int[bufSize];
//        for (int i = 0; i < bufSize; i++) res[i] = buf[i];
//        return (char*)res;
//    }
//
//    TreeNode* dfs2(int* p) {
//        if (*p == 0xFFFFFFFF) {
//            p++;
//            return NULL;
//        }
//        TreeNode* res = new TreeNode(*p);
//        p++;
//        res->left = dfs2(p);
//        res->right = dfs2(p);
//        return res;
//    }
//
//    TreeNode* reconByPreString(char* str) {
//        int* p = (int*)str;
//        return dfs2(p);
//    }
//};


void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}


int main()
{
    string str = "1!2!#!#!2!#!#!";
    TreeNode* root = reconByPreString(str);
    printTree(root);
    string str2 = serialByPre(root);
    for (int i = 0; i < str2.size(); i++) {
        cout << str2[i];
    }
    return 0;
}
