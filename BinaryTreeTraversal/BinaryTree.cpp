#include "BinaryTree.h"
#include <stack>
#include <queue>
#include <vector>
#include <math.h>

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

//先序遍历递归法
void BinaryTree::preOrderRecur(){
    pre_OrderRecur(root);
    cout << endl;
}
void BinaryTree::pre_OrderRecur(BinaryNode *t){
    if(t == NULL){
        return;
    }else{
        cout << t->data << ' ';
        pre_OrderRecur(t->lchild);
        pre_OrderRecur(t->rchild);
    }
}

//中序遍历递归法
void BinaryTree::inOrderRecur(){
    in_OrderRecur(root);
    cout << endl;
}
void BinaryTree::in_OrderRecur(BinaryNode *t){
    if(t == NULL){
        return;
    }else{
        in_OrderRecur(t->lchild);
        cout << t->data << ' ';
        in_OrderRecur(t->rchild);
    }
}

//后序遍历递归法
void BinaryTree::postOrderRecur(){
    post_OrderRecur(root);
    cout << endl;
}
void BinaryTree::post_OrderRecur(BinaryNode *t){
    if(t == NULL){
        return;
    }else{
        post_OrderRecur(t->lchild);
        post_OrderRecur(t->rchild);
        cout << t->data << ' ';
    }
}

//先序遍历非递归法
//1.申请一个栈，将头节点压入栈中
//2.弹出栈顶节点，打印，将该节点的右孩子（非空时）压入栈中，再压左孩子
//3.重复2步骤，直到栈为空
void BinaryTree::preOrderUnRecur(){
    BinaryNode *cur = NULL;
    if(root == NULL){
        return;
    }else{
        stack<BinaryNode*> st;
        st.push(root);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            cout << cur->data << ' ';
            if(cur->rchild != NULL){
                st.push(cur->rchild);
            }
            if(cur->lchild != NULL){
                st.push(cur->lchild);
            }
        }
    }
    cout << endl;
}

//中序遍历二叉树，非递归法
//1.申请一个栈，记为st
//2.将头节点压入栈中，把左节点一直压到栈中，重复步骤2
//3.当cur==NULL时，弹出st中一个节点，并打印，且将该节点的右节点压入栈中，继续重复步骤2
//4.st为空且cur为空时停止
void BinaryTree::inOrderUnRecur(){
    BinaryNode *cur = NULL;
    stack<BinaryNode*> st;
    cur = root;
    if(cur == NULL){
        return;
    }else{
        while(!st.empty() || cur!=NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->lchild;
            }else{
                cur = st.top();
                cout << cur->data << ' ';
                st.pop();
                cur = cur->rchild;
            }
        }
    }
    cout << endl;
}

//后序遍历，非递归法
//1.申请一个栈，记为s1，将头节点压入s1中；
//2.从s1中弹出节点记为cur,依次将cur的左孩子和右孩子压入s1;
//3.每一个从s1中弹出的节点都压入s2中；
//4.不断重复2 3两步，直到s1空；
//5.从s2中弹出节点并打印。
void  BinaryTree::postOrderUnRecur(){
    BinaryNode *cur = NULL;
    stack<BinaryNode*> s1;
    stack<BinaryNode*> s2;
    cur = root;
    if(cur == NULL){
        return;
    }else{
        s1.push(cur);
        while(!s1.empty()){
            cur = s1.top();
            s1.pop();
            s2.push(cur);
            if(cur->lchild != NULL){
                s1.push(cur->lchild);
            }
            if(cur->rchild != NULL){
                s1.push(cur->rchild);
            }
        }
        while(!s2.empty()){
            cur = s2.top();
            cout << cur->data << ' ';
            s2.pop();
        }
    }
    cout << endl;

}

//后序遍历非递归法2，利用一个栈实现
//1.将头节点压入stack,设置两个变量h,c,h代表最近一次弹出并打印的节点，c代表栈顶，初始h为头节点，c为NULL
//2.c分为三种情况：
//  1.c的左孩子不为null，h不为c的左孩和右孩，则把c的左孩压入栈中
//  2.1中条件不成立，若c的右孩子不为null,h不为c的右孩子，则把c的右孩子压入栈中
//  3.1和2均不成立，则弹出c并打印，然后令h=c
//3.一直重复步骤2，直到栈为空
void BinaryTree::postOrderUnRecur2(){
    if(root == NULL){
        return;
    }else{
        stack<BinaryNode*> st;
        BinaryNode *h = root;
        st.push(h);
        BinaryNode *c = NULL;
        while(!st.empty()){
            c = st.top();
            if(c->lchild != NULL && h != c->lchild && h != c->rchild){
                st.push(c->lchild);
            }else if(c->rchild != NULL && h != c->rchild){
                st.push(c->rchild);
            }else{
                cout << c->data << ' ';
                st.pop();
                h = c;
            }

        }
    }
    cout << endl;
}

//层序遍历
//1.将头节点压入队列
//2.弹出队首节点并打印，若有左孩子进队列，若有右孩子进队列
//3.重复步骤2，直到队列为空
void BinaryTree::levelOrder(){
    if(root == NULL){
        return;
    }else{
        queue<BinaryNode*> qu;
        BinaryNode *cur = root;
        qu.push(cur);
        while(!qu.empty()){
            cur = qu.front();
            cout << cur->data << ' ';
            qu.pop();
            if(cur->lchild != NULL){
                qu.push(cur->lchild);
            }
            if(cur->rchild != NULL){
                qu.push(cur->rchild);
            }
        }
    }
    cout << endl;
}

//打印二叉树
vector<char> BinaryTree::convertBinaryTree(){
    vector<char> charBinary;
    if(root == NULL){
        return charBinary;
    }else{
        queue<BinaryNode*> qu;
        BinaryNode *cur = root;
        BinaryNode *nullNode = new BinaryNode;
        nullNode->data = '#';
        nullNode->lchild = NULL;
        nullNode->rchild = NULL;
        qu.push(cur);
        while(!qu.empty()){
            cur = qu.front();
            qu.pop();
            if(cur->lchild != NULL){
                qu.push(cur->lchild);
            }
            if(cur->lchild == NULL){
                cur->lchild = nullNode;
            }
            if(cur->rchild != NULL){
                qu.push(cur->rchild);
            }
            if(cur->rchild == NULL){
                cur->rchild = nullNode;
            }
        }
        cur = root;
        qu.push(cur);

        while(!qu.empty()){
            cur = qu.front();
            charBinary.push_back(cur->data);
            qu.pop();
            if(cur->lchild != NULL){
                qu.push(cur->lchild);
            }
            if(cur->rchild != NULL){
                qu.push(cur->rchild);
            }
        }
    }
    return charBinary;
}

void BinaryTree::printBinaryTree(vector<char> &charBTree){
    int i;
	int num = charBTree.size();
	int row = 0;
	for(i = num; charBTree[i]=='#' && i < 100; i--){
		num--;
	}
	cout << num << endl;
	for(i = 0;i < 10; i++){
		if(pow(2,i) >= num){
			row = i;
			break;
		}
	}
	int p=(int)pow(2,row)-1;
	int temp;
	row = 0;
	while(p != 0){
		for(i = 0;i < num; i++){
			if(i+1 == pow(2,row)){
				row++;
				cout << endl;
				for(int j = 0; j < p; j++){
					cout<<" ";
				}
				cout << charBTree[i];
				temp = p*2+1;
				p= (p-1)/2;
			}else{
				for(int j = 0; j < temp; j++){
					cout<<" ";
				}
				cout<<charBTree[i];
			}
		}
	}
	cout<<endl;
}


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
    string val = to ;
    //val += to_string(head->data);
    val += head->data;
    val += to;
    int lenM = (int)val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head->lchild, height + 1, "^", len);
}

 void BinaryTree::printTree() {
     cout<<"Binary Tree:";
     printInOrder(root, 0, "h", 17);
     cout<< endl;
 }



//判断一棵二叉树是否是二叉查找树（二叉搜索树）即中序遍历是依次增大的
bool BinaryTree::checkBST(){
    BinaryNode *cur = NULL;
    BinaryNode *pre = NULL;
    stack<BinaryNode*> st;
    cur = root;
    //pre = root;
    if(cur == NULL){
        return false;
    }else{
        while(!st.empty() || cur!=NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->lchild;
            }else{
                cur = st.top();
                if(pre != NULL){
                  if(cur->data <= pre->data){
                        return false;
                    }else{
                        return true;
                    }
                }

                pre = cur;
                st.pop();
                cur = cur->rchild;
            }
        }
    }
}

BinaryTree::~BinaryTree()
{
    //dtor
}
