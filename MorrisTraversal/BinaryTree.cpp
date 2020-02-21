#include "BinaryTree.h"
#include <stack>
#include <queue>

BinaryTree::BinaryTree()
{
    root = NULL;
    height = 0;
}

//按照先序遍历递归创建二叉树，如果遇到#表示是空节点
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

//打印二叉树
//顺时针打印二叉树
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

//Morris遍历
void BinaryTree::Morris() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight记录树的最右节点
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        cout << cur->data << ' ';//第一次走到cur时就打印
        mostright = cur->lchild;//mostright是cur的左孩
        if (mostright != NULL) {//cur有左孩子，即走流程2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright的右孩不能为空而且不能指回去
                mostright = mostright->rchild;
            }
            //此时mostright已来到了cur左子树上最右的节点
            if (mostright->rchild == NULL) {//第一次来到cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//直接跳到while的下一次循环
            }
            else {//第二次来到cur
                mostright->rchild = NULL;
            }
        }
        cur = cur->rchild;//cur无左孩，走流程1
    }
    cout << endl;
}

//Morris遍历->先序遍历
// 1.只遍历一次的直接打印
// 2.遍历二次的，第一次遍历时打印
void BinaryTree::MorrisPre() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight记录树的最右节点
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright是cur的左孩
        if (mostright != NULL) {//cur有左孩子，即走流程2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright的右孩不能为空而且不能指回去
                mostright = mostright->rchild;
            }
            //此时mostright已来到了cur左子树上最右的节点
            if (mostright->rchild == NULL) {//第一次来到cur
                mostright->rchild = cur;
                cout << cur->data << ' ';//第一次遍历时打印
                cur = cur->lchild;
                continue;//直接跳到while的下一次循环
            }
            else {//第二次来到cur，不打印要跳过，所以另外加一个else
                mostright->rchild = NULL;
            }
        }
        else {//cur没有左孩子，即只遍历一次，所以直接打印
            cout << cur->data << ' ';
        }
        cur = cur->rchild;//cur无左孩，走流程1
    }
    cout << endl;
}

//Morris遍历->中序遍历
// 1.只遍历一次的直接打印
// 2.遍历二次的，第二次遍历时打印
void BinaryTree::MorrisIn() {
    if (root == NULL) {
        return;
    }
    BinaryNode* cur = root;
    //mostRight记录树的最右节点
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright是cur的左孩
        if (mostright != NULL) {//cur有左孩子，即走流程2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright的右孩不能为空而且不能指回去
                mostright = mostright->rchild;
            }
            //此时mostright已来到了cur左子树上最右的节点
            if (mostright->rchild == NULL) {//第一次来到cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//直接跳到while的下一次循环
            }
            else {//第二次来到cur
                mostright->rchild = NULL;
            }
        }
        cout << cur->data << ' ';//第一次遍历的因为continue跳过了，所以只能第二次遍历时才打印
        cur = cur->rchild;//cur无左孩，走流程1
    }
    cout << endl;
}

//Morris遍历->后序遍历
// 打印时机放在第二次遍历时：
// 1.先逆序打印左树的右边界
// 2.结束后单独逆序打印整棵树的右边界

//逆序
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
//逆序打印右边界
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
    //mostRight记录树的最右节点
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright是cur的左孩
        if (mostright != NULL) {//cur有左孩子，即走流程2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright的右孩不能为空而且不能指回去
                mostright = mostright->rchild;
            }
            //此时mostright已来到了cur左子树上最右的节点
            if (mostright->rchild == NULL) {//第一次来到cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//直接跳到while的下一次循环
            }
            else {//第二次来到cur
                mostright->rchild = NULL;
                printEdge(cur->lchild);//逆序打印左树右边界
            }
        }
        cur = cur->rchild;//cur无左孩，走流程1
    }
    printEdge(root);//逆序打印整棵树的右边界
    cout << endl;
}

//Morris遍历用于判断一棵二叉树是否是搜索二叉树
//利用改成中序遍历，把打印行为替换为比较行为即可
bool BinaryTree::MorrisBST() {
    if (root == NULL) {
        return true;
    }
    char preData = 'A';
    BinaryNode* cur = root;
    //mostRight记录树的最右节点
    BinaryNode* mostright = NULL;
    while (cur != NULL) {
        mostright = cur->lchild;//mostright是cur的左孩
        if (mostright != NULL) {//cur有左孩子，即走流程2
            while (mostright->rchild != NULL && mostright->rchild != cur) {//mostright的右孩不能为空而且不能指回去
                mostright = mostright->rchild;
            }
            //此时mostright已来到了cur左子树上最右的节点
            if (mostright->rchild == NULL) {//第一次来到cur
                mostright->rchild = cur;
                cur = cur->lchild;
                continue;//直接跳到while的下一次循环
            }
            else {//第二次来到cur
                mostright->rchild = NULL;
            }
        }
        //判断当前节点与前一节点的值大小关系
        if (cur->data <= preData) {
            return false;
        }
        preData = cur->data;
        cur = cur->rchild;//cur无左孩，走流程1
    }
    return true;
}


BinaryTree::~BinaryTree()
{
    //dtor
}
