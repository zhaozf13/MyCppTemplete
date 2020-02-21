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
	void ClearList();                                    // �����������
	bool ListEmpty();                                    // �ж������Ƿ�Ϊ��
	bool ListInsertHead(Node *pNode);                    // ͷ������һ���ڵ�
	bool ListInsertTail(Node *pNode);                    // β������һ���ڵ�
	bool ListInsert(int i, Node *pNode);                 // ������λ�ò���ڵ�
	bool ListDelete(int i, Node *pNode);                 // ������λ��ɾ�����
	bool ListGetElem(int i, Node *pNode);                // ���ҵ�i��Ԫ��
	int  LocateElem(Node *pNode);                        // ���ҽ���λ��
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);  // ��ָ���ǰ��ָ��
	bool NextElem(Node *pCurrentNode, Node *pNextNode);  // ��ָ��ĺ��ָ��
	void ListTraverse();                                 // ����ı���
};

#endif // LIST_H
