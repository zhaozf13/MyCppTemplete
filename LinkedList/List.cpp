#include "List.h"
#include <iostream>


List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

//判断单链表是否为空，空返回true,否则返回false
bool List::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//清空整个链表
void List::ClearList()
{
	Node *currentNode = m_pList->next; // 指向头指针后第一个元素
	while (currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;               // 头指针下一个为空

}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

// 头部插入一个节点
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;            // 头节点后第一个元素
	Node *newNode = new Node;              // 创建一个新的节点
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

// 尾部插入一个节点
bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;   // 遍历到尾结点
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

// 从任意位置插入节点
bool List::ListInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
		return false;
	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}

	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;

}

// 从任意位置删除结点
bool List::ListDelete(int i, Node *pNode)
{
	if (i < 0 || i >m_iLength)
		return false;
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

// 查找第i个元素
bool List::ListGetElem(int i, Node *pNode)
{
	if (i < 0 || i >m_iLength)
		return false;
	Node *currentNode = m_pList;
	for (int k = 0; k <= i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

// 查找结点的位序
int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	int count = 0;
	while (currentNode->next!= NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}

// 找指针的前驱指针，实际上是判断pPreNode是否是PCurrentNode的前驱节点
bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
				return false;
			else
			{
				pPreNode->data = tempNode->data;
				return true;
			}

		}
	}
	return false;
}

// 找指针的后继指针，实际上是判断pNextNode是否是PCurrentNode的后继节点
bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				return false;
			}
			else
			{
				pNextNode->data = currentNode->next->data;
				return true;
			}

		}
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}

}
