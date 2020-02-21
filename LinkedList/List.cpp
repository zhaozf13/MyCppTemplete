#include "List.h"
#include <iostream>


List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

//�жϵ������Ƿ�Ϊ�գ��շ���true,���򷵻�false
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

//�����������
void List::ClearList()
{
	Node *currentNode = m_pList->next; // ָ��ͷָ����һ��Ԫ��
	while (currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;               // ͷָ����һ��Ϊ��

}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

// ͷ������һ���ڵ�
bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;            // ͷ�ڵ���һ��Ԫ��
	Node *newNode = new Node;              // ����һ���µĽڵ�
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

// β������һ���ڵ�
bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;   // ������β���
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

// ������λ�ò���ڵ�
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

// ������λ��ɾ�����
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

// ���ҵ�i��Ԫ��
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

// ���ҽ���λ��
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

// ��ָ���ǰ��ָ�룬ʵ�������ж�pPreNode�Ƿ���PCurrentNode��ǰ���ڵ�
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

// ��ָ��ĺ��ָ�룬ʵ�������ж�pNextNode�Ƿ���PCurrentNode�ĺ�̽ڵ�
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
