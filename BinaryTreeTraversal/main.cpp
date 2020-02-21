#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main()
{
    BinaryTree a;
    string s = "ABC##D#E##F##";
    a.createBinaryTree(s);
    //���ɵ�����ʽΪ
    //B-A-C
    //D-B-E
    //NULL-E-F
    cout << "�ݹ�������������" << endl;
    a.preOrderRecur();
    cout << "�ǵݹ�������������" << endl;
    a.preOrderUnRecur();
    cout << "�ݹ�������������" << endl;
    a.inOrderRecur();
    cout << "�ǵݹ�������������" << endl;
    a.inOrderUnRecur();
    cout << "�ݹ������������" << endl;
    a.postOrderRecur();
    cout << "�ǵݹ������������" << endl;
    a.postOrderUnRecur();
    cout << "�ǵݹ�������2�����" << endl;
    a.postOrderUnRecur2();
    cout << "��������Ľ����" << endl;
    a.levelOrder();
    cout << "�Ƿ��Ƕ����������" <<endl;
    bool res = a.checkBST();
    cout << res << endl;
    cout << "��ӡ��������" <<endl;
    vector<char> charBTree;
    charBTree = a.convertBinaryTree();
    for(vector<char>::iterator it = charBTree.begin(); it != charBTree.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    a.printBinaryTree(charBTree);
    a.printTree();
    return 0;
}
