#include "BinaryTree.h"
#include <stack>
#include <queue>

BinaryTree::BinaryTree()
{
    root = NULL;
    height = 0;
}

//������������ݹ鴴�����������������#��ʾ�ǿսڵ�
BinaryNode* BinaryTree::create(string &s, int &pos){
    ++pos;
    BinaryNode *t;
    if((unsigned)pos >= s.size()){
        return NULL;
    }else{
        if(s[pos] == '#'){
            t = NULL;
        }else{
            t = new BinaryNode;
            t->data = s[pos];
            t->lchild = create(s, pos);
            t->rchild = create(s, pos);
        }
    }
    return t;
}
void BinaryTree::createBinaryTree(string s){
    int pos = -1;
    root = create(s, pos);
}

//��ӡ������
//˳ʱ���ӡ������
string BinaryTree::getSpace(int num) {
    string space = " ";
    string buf = "";
    for (int i = 0; i < num; i++) {
        buf.append(space);
    }
    return buf;
}
void BinaryTree::printInOrder(BinaryNode* head, int height, string to, int len) {
    if (head == NULL) {
        return;
    }
    printInOrder(head->rchild, height + 1, "v", len);
    string val = to;
    //val += to_string(head->data);
    val += head->data;
    val += to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) << val << endl;
    printInOrder(head->lchild, height + 1, "^", len);
}

void BinaryTree::printTree() {
    cout << "Binary Tree:" << endl;
    printInOrder(root, 0, "h", 16);
    cout << endl;
}

//Morris����
void BinaryTree::Morris() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight��¼�������ҽڵ�
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        cout << cur->data << ' ';//��һ���ߵ�curʱ�ʹ�ӡ
        mostright = cur->lchild;//mostright��cur����
        if (mostright != NULL) {//cur�����ӣ���������2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright���Һ�����Ϊ�ն��Ҳ���ָ��ȥ
                mostright = mostright->rchild;
            }
            //��ʱmostright��������cur�����������ҵĽڵ�
            if (mostright->rchild == NULL) {//��һ������cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//ֱ������while����һ��ѭ��
            }
            else {//�ڶ�������cur
                mostright->rchild = NULL;
            }
        }
        cur = cur->rchild;//cur���󺢣�������1
    }
    cout << endl;
}

//Morris����->�������
// 1.ֻ����һ�ε�ֱ�Ӵ�ӡ
// 2.�������εģ���һ�α���ʱ��ӡ
void BinaryTree::MorrisPre() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight��¼�������ҽڵ�
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright��cur����
        if (mostright != NULL) {//cur�����ӣ���������2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright���Һ�����Ϊ�ն��Ҳ���ָ��ȥ
                mostright = mostright->rchild;
            }
            //��ʱmostright��������cur�����������ҵĽڵ�
            if (mostright->rchild == NULL) {//��һ������cur
                mostright->rchild = cur;
                cout << cur->data << ' ';//��һ�α���ʱ��ӡ
                cur = cur->lchild;
                continue;//ֱ������while����һ��ѭ��
            }
            else {//�ڶ�������cur������ӡҪ���������������һ��else
                mostright->rchild = NULL;
            }
        }
        else {//curû�����ӣ���ֻ����һ�Σ�����ֱ�Ӵ�ӡ
            cout << cur->data << ' ';
        }
        cur = cur->rchild;//cur���󺢣�������1
    }
    cout << endl;
}

//Morris����->�������
// 1.ֻ����һ�ε�ֱ�Ӵ�ӡ
// 2.�������εģ��ڶ��α���ʱ��ӡ
void BinaryTree::MorrisIn() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight��¼�������ҽڵ�
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright��cur����
        if (mostright != NULL) {//cur�����ӣ���������2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright���Һ�����Ϊ�ն��Ҳ���ָ��ȥ
                mostright = mostright->rchild;
            }
            //��ʱmostright��������cur�����������ҵĽڵ�
            if (mostright->rchild == NULL) {//��һ������cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//ֱ������while����һ��ѭ��
            }
            else {//�ڶ�������cur
                mostright->rchild = NULL;
            }
        }
        cout << cur->data << ' ';//��һ�α�������Ϊcontinue�����ˣ�����ֻ�ܵڶ��α���ʱ�Ŵ�ӡ
        cur = cur->rchild;//cur���󺢣�������1
    }
    cout << endl;
}

//Morris����->�������
// ��ӡʱ�����ڵڶ��α���ʱ��
// 1.�������ӡ�������ұ߽�
// 2.�����󵥶������ӡ���������ұ߽�

//����
BinaryNode* BinaryTree::reverseEdge(BinaryNode* from) {
    BinaryNode* pre = NULL;
    BinaryNode* next = NULL;
    while (from != NULL) {
        next = from->rchild;
        from->rchild = pre;
        pre = from;
        from = next;
    }
    return pre;
}
//�����ӡ�ұ߽�
void BinaryTree::printEdge(BinaryNode* head) {
    BinaryNode* tail = reverseEdge(head);
    BinaryNode* cur = tail;
    while (cur != NULL) {
        cout << cur->data << ' ';
        cur = cur->rchild;
    }
    reverseEdge(tail);
}

void BinaryTree::MorrisPos() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight��¼�������ҽڵ�
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright��cur����
        if (mostright != NULL) {//cur�����ӣ���������2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright���Һ�����Ϊ�ն��Ҳ���ָ��ȥ
                mostright = mostright->rchild;
            }
            //��ʱmostright��������cur�����������ҵĽڵ�
            if (mostright->rchild == NULL) {//��һ������cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//ֱ������while����һ��ѭ��
            }
            else {//�ڶ�������cur
                mostright->rchild = NULL;
                printEdge(cur->lchild);//�����ӡ�����ұ߽�
            }
        }
        cur = cur->rchild;//cur���󺢣�������1
    }
    printEdge(root);//�����ӡ���������ұ߽�
    cout << endl;
}

//Morris���������ж�һ�ö������Ƿ�������������
//���øĳ�����������Ѵ�ӡ��Ϊ�滻Ϊ�Ƚ���Ϊ����
bool BinaryTree::MorrisBST() {
    if (root == NULL) {
        return true;
    }
    char preData = 'A';
    BinaryNode* cur = root;
    //mostRight��¼�������ҽڵ�
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright��cur����
        if (mostright != NULL) {//cur�����ӣ���������2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright���Һ�����Ϊ�ն��Ҳ���ָ��ȥ
                mostright = mostright->rchild;
            }
            //��ʱmostright��������cur�����������ҵĽڵ�
            if (mostright->rchild == NULL) {//��һ������cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//ֱ������while����һ��ѭ��
            }
            else {//�ڶ�������cur
                mostright->rchild = NULL;
            }
        }
        //�жϵ�ǰ�ڵ���ǰһ�ڵ��ֵ��С��ϵ
        if (cur->data <= preData) {
            return false;
        }
        preData = cur->data;
        cur = cur->rchild;//cur���󺢣�������1
    }
    return true;
}


BinaryTree::~BinaryTree()
{
    //dtor
}
