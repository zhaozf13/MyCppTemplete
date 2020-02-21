#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BinaryNode{
    public:
        char data;
        struct BinaryNode *lchild,*rchild;
};


class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        //按照先序遍历创建二叉树，由字符串读取
        void createBinaryTree(string s);
        //先序遍历二叉树，递归法
        void preOrderRecur();
        //中序遍历二叉树，递归法
        void inOrderRecur();
        //后序遍历二叉树，递归法
        void postOrderRecur();
        //先序遍历二叉树，非递归法
        void preOrderUnRecur();
        //中序遍历二叉树，非递归法
        void inOrderUnRecur();
        //后序遍历二叉树，非递归法1
        void postOrderUnRecur();
        //后序遍历二叉树，非递归法2
        void postOrderUnRecur2();
        //层序遍历二叉树
        void levelOrder();
        //打印二叉树,先转化为字符串，再打印
        vector<char> convertBinaryTree();
        void printBinaryTree(vector<char> &charBTree);
        //判断一棵二叉树是否是二叉查找树
        bool checkBST();
        //顺时针打印二叉树
        string getSpace(int num);
        void printInOrder(BinaryNode* head, int height, string to, int len);
        void printTree();


    private:
        BinaryNode * root;
        int height;
        void pre_OrderRecur(BinaryNode *t);//递归法
        void in_OrderRecur(BinaryNode *t);
        void post_OrderRecur(BinaryNode *t);
        BinaryNode* create(string &s, int &pos);
        void get_Height(BinaryNode *t, int h);

};

#endif // BINARYTREE_H
