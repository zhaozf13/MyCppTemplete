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
        //��������������������������ַ�����ȡ
        void createBinaryTree(string s);
        //��ӡ������,��˳ʱ��ת90��鿴
        string getSpace(int num);
        void printInOrder(BinaryNode* head, int height, string to, int len);
        void printTree();
        //Morris����
        void Morris();
        //Morris����->�������
        void MorrisPre();
        //Morris����->�������
        void MorrisIn();
        //Morris����->�������
        BinaryNode* reverseEdge(BinaryNode* from);
        void printEdge(BinaryNode* head);
        void MorrisPos();
        //Morris�����ж�һ�ö������Ƿ�������������
        bool MorrisBST();

    private:
        BinaryNode * root;
        int height = 0;
        BinaryNode* create(string &s, int &pos);

};

#endif // BINARYTREE_H
