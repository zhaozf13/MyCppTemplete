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

//��������ݹ鷨
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

//��������ݹ鷨
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

//��������ݹ鷨
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

//��������ǵݹ鷨
//1.����һ��ջ����ͷ�ڵ�ѹ��ջ��
//2.����ջ���ڵ㣬��ӡ�����ýڵ���Һ��ӣ��ǿ�ʱ��ѹ��ջ�У���ѹ����
//3.�ظ�2���裬ֱ��ջΪ��
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

//����������������ǵݹ鷨
//1.����һ��ջ����Ϊst
//2.��ͷ�ڵ�ѹ��ջ�У�����ڵ�һֱѹ��ջ�У��ظ�����2
//3.��cur==NULLʱ������st��һ���ڵ㣬����ӡ���ҽ��ýڵ���ҽڵ�ѹ��ջ�У������ظ�����2
//4.stΪ����curΪ��ʱֹͣ
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

//����������ǵݹ鷨
//1.����һ��ջ����Ϊs1����ͷ�ڵ�ѹ��s1�У�
//2.��s1�е����ڵ��Ϊcur,���ν�cur�����Ӻ��Һ���ѹ��s1;
//3.ÿһ����s1�е����Ľڵ㶼ѹ��s2�У�
//4.�����ظ�2 3������ֱ��s1�գ�
//5.��s2�е����ڵ㲢��ӡ��
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

//��������ǵݹ鷨2������һ��ջʵ��
//1.��ͷ�ڵ�ѹ��stack,������������h,c,h�������һ�ε�������ӡ�Ľڵ㣬c����ջ������ʼhΪͷ�ڵ㣬cΪNULL
//2.c��Ϊ���������
//  1.c�����Ӳ�Ϊnull��h��Ϊc���󺢺��Һ������c����ѹ��ջ��
//  2.1����������������c���Һ��Ӳ�Ϊnull,h��Ϊc���Һ��ӣ����c���Һ���ѹ��ջ��
//  3.1��2�����������򵯳�c����ӡ��Ȼ����h=c
//3.һֱ�ظ�����2��ֱ��ջΪ��
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

//�������
//1.��ͷ�ڵ�ѹ�����
//2.�������׽ڵ㲢��ӡ���������ӽ����У������Һ��ӽ�����
//3.�ظ�����2��ֱ������Ϊ��
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

//��ӡ������
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



//�ж�һ�ö������Ƿ��Ƕ������������������������������������������
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
