#ifndef LIST_H
#define LIST_H
#pragma once
#include"Node.h"

class List
{
private:
	Node * m_pList;
	int m_iLength;

public:
	List();
	~List();
	void ClearList();                                    // 清空整个链表
	bool ListEmpty();                                    // 判断链表是否为空
	bool ListInsertHead(Node *pNode);                    // 头部插入一个节点
	bool ListInsertTail(Node *pNode);                    // 尾部插入一个节点
	bool ListInsert(int i, Node *pNode);                 // 从任意位置插入节点
	bool ListDelete(int i, Node *pNode);                 // 从任意位置删除结点
	bool ListGetElem(int i, Node *pNode);                // 查找第i个元素
	int  LocateElem(Node *pNode);                        // 查找结点的位序
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);  // 找指针的前驱指针
	bool NextElem(Node *pCurrentNode, Node *pNextNode);  // 找指针的后继指针
	void ListTraverse();                                 // 链表的遍历
};

#endif // LIST_H
