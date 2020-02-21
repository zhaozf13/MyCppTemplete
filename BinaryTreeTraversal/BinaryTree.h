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
        //��������������������������ַ�����ȡ
        void createBinaryTree(string s);
        //����������������ݹ鷨
        void preOrderRecur();
        //����������������ݹ鷨
        void inOrderRecur();
        //����������������ݹ鷨
        void postOrderRecur();
        //����������������ǵݹ鷨
        void preOrderUnRecur();
        //����������������ǵݹ鷨
        void inOrderUnRecur();
        //����������������ǵݹ鷨1
        void postOrderUnRecur();
        //����������������ǵݹ鷨2
        void postOrderUnRecur2();
        //�������������
        void levelOrder();
        //��ӡ������,��ת��Ϊ�ַ������ٴ�ӡ
        vector<char> convertBinaryTree();
        void printBinaryTree(vector<char> &charBTree);
        //�ж�һ�ö������Ƿ��Ƕ��������
        bool checkBST();
        //˳ʱ���ӡ������
        string getSpace(int num);
        void printInOrder(BinaryNode* head, int height, string to, int len);
        void printTree();


    private:
        BinaryNode * root;
        int height;
        void pre_OrderRecur(BinaryNode *t);//�ݹ鷨
        void in_OrderRecur(BinaryNode *t);
        void post_OrderRecur(BinaryNode *t);
        BinaryNode* create(string &s, int &pos);
        void get_Height(BinaryNode *t, int h);

};

#endif // BINARYTREE_H
