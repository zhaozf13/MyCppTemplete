// MorrisTraversal.cpp : 
//Morris遍历细节，时间复杂度o(N),空间复杂度o(1)
//假设来到当前节点cur，开始时cur来到头节点位置
//1）如果cur没有左孩子，cur向右移动(cur = cur.right)
//2）如果cur有左孩子，找到左子树上最右的节点mostRight：
//   a.如果mostRight的右指针指向空，让其指向cur，然后cur向左移动(cur = cur.left)
//   b.如果mostRight的右指针指向cur，让其指向null，然后cur向右移动(cur = cur.right)
//3）cur为空时遍历停止

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree a;
    string s = "ABC##D#E##F##";
    //对应的树形状是      A
    //                 B   F
    //                C  D 
    //                     E
    a.createBinaryTree(s);
    a.printTree();
    a.Morris();
    a.MorrisPre();
    a.MorrisIn();
    a.MorrisPos();
    bool res = a.MorrisBST();
    cout << res << endl;
}


