#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>

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
        //打印二叉树,需顺时针转90°查看
        string getSpace(int num);
        void printInOrder(BinaryNode* head, int height, string to, int len);
        void printTree();
        //Morris遍历
        void Morris();
        //Morris遍历->先序遍历
        void MorrisPre();
        //Morris遍历->中序遍历
        void MorrisIn();
        //Morris遍历->后序遍历
        BinaryNode* reverseEdge(BinaryNode* from);
        void printEdge(BinaryNode* head);
        void MorrisPos();
        //Morris遍历判断一棵二叉树是否是搜索二叉树
        bool MorrisBST();

    private:
        BinaryNode * root;
        int height = 0;
        BinaryNode* create(string &s, int &pos);

};

#endif // BINARYTREE_H
