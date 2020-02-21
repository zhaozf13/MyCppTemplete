#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main()
{
    BinaryTree a;
    string s = "ABC##D#E##F##";
    a.createBinaryTree(s);
    //建成的树样式为
    //B-A-C
    //D-B-E
    //NULL-E-F
    cout << "递归先序遍历结果：" << endl;
    a.preOrderRecur();
    cout << "非递归先序遍历结果：" << endl;
    a.preOrderUnRecur();
    cout << "递归中序遍历结果：" << endl;
    a.inOrderRecur();
    cout << "非递归中序遍历结果：" << endl;
    a.inOrderUnRecur();
    cout << "递归后序遍历结果：" << endl;
    a.postOrderRecur();
    cout << "非递归后序遍历结果：" << endl;
    a.postOrderUnRecur();
    cout << "非递归后序遍历2结果：" << endl;
    a.postOrderUnRecur2();
    cout << "层序遍历的结果：" << endl;
    a.levelOrder();
    cout << "是否是二叉查找树：" <<endl;
    bool res = a.checkBST();
    cout << res << endl;
    cout << "打印二叉树：" <<endl;
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
