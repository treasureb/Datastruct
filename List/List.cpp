#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>


typedef int DataType;
typedef struct Node
{
	struct Node* next;
	DataType data;
}Node, *PNode;//���ﶨ��һ���ṹ�����ͺ�һ���ṹ��ָ������

PNode BuyNode(DataType data);//����

//��ʼ��������
void InitList(PNode* pHead)
{
	*pHead = NULL;
}

//��β������һ���µĽڵ�
void Pushback(PNode* pHead, DataType data)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = NULL;
	}
}

//��β��ɾ��һ���ڵ�
void Popback(PNode *pHead)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->next)//ֻ��һ��ͷ���
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		PNode pPre = pCur;//Ҫɾ���ýڵ㣬���뱣����ǰһ���ڵ�

		while (pCur)
		{
			pPre = pCur;
			pCur = pCur->next;
		}

		free(pCur);
		pPre->next = NULL;

	}
}

//��ͷ������һ���µĽڵ�
void PushFront(PNode *pHead, DataType data)
{
	PNode pNewNode = BuyNode(data);
	assert(pHead);
	if (pNewNode)
	{
		pNewNode->next = *pHead;
		*pHead = pNewNode;
	}
}

//��ͷ��ɾ��һ���µĽڵ�
void PopFront(PNode *pHead)
{
	PNode Del = NULL;
	assert(*pHead);
	if (NULL == pHead)
	{
		return;
	}

	Del = *pHead;
	*pHead = (*pHead)->next;
	free(Del);
}

//����ֵΪdata�Ľڵ�
PNode Find(PNode *pHead, DataType data)
{
	PNode pCurNode = *pHead;
	while (pCurNode)
	{
		if (pCurNode->data == data)
		return pCurNode;

		pCurNode = pCurNode->next;
	}
	return NULL;
}

//��Posλ����һ���ڵ�
void Insert(PNode Pos, DataType data)
{
	PNode pNewNode = NULL;

	if (NULL == Pos)
	{
		return;
	}

	pNewNode = BuyNode(data);
	pNewNode->next = Pos->next;
	Pos->next = pNewNode;
}

//ɾ��Posλ�Ľڵ�
void Erase(PNode *pHead, PNode Pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == Pos)
		return;
	else if (Pos == *pHead)
	{
		*pHead = Pos->next;
		free(Pos);
	}
	else
	{
		PNode pPre = *pHead;
		while (pPre->next != Pos)
		{
			pPre = pPre->next;
		}
		pPre->next = Pos->next;
		free(Pos);
	}
}

//�Ƴ������е�һ��ֵΪdata�Ľڵ�
void Remove(PNode *pHead, DataType data)
{
	PNode pPreNode = NULL;
	PNode pCurNode = *pHead;
	assert(*pHead);
	while (pCurNode->data != data)
	{
		pPreNode = pCurNode;
		pCurNode = pCurNode->next;
	}
	pPreNode->next = pCurNode->next;
	free(pCurNode);
}

//�Ƴ�����������ֵΪdata�Ľڵ�
void RemoveAll(PNode *pHead, DataType data)
{
	PNode pPreNode = NULL;
	PNode pCurNode = NULL;
	assert(*pHead);

	pPreNode = *pHead;
	pCurNode = (*pHead)->next;

	while (pCurNode)
	{
		if (pCurNode->data == data)
		{
			pPreNode->next = pCurNode->next;
			free(pCurNode);
			pCurNode->next = pPreNode->next;
		}
		pCurNode = pCurNode->next;
	}
	if ((*pHead)->data == data)
	{
		pCurNode = *pHead;
		*pHead = (*pHead)->next;
		free(pCurNode);
	}
}

//��ȡ�����нڵ���ܸ���
size_t Size(PNode pHead)
{
	int count = 0;
	while (pHead)
	{
		pHead = pHead->next;
		count++;
	}
	return count;
}

//��ȡ�����еĵ�һ���ڵ�
PNode Front(PNode pHead)
{
	if (NULL == pHead)
	{
		return NULL;
	}
	return pHead;

}

//��ȡ�����е����һ���ڵ�
PNode Back(PNode pHead)
{
	if (NULL == pHead)
		return NULL;
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	return pHead;
}

//�����п�
bool Empty(PNode pHead)
{
	if (NULL == pHead)
		return 1;
	return 0;

}

//��ȡһ���µĽ��
PNode BuyNode(DataType data)
{
	PNode pTemp = (PNode)malloc(sizeof(Node));
	if (NULL == pTemp)
	{
		printf("malloc error!");
	}
	else
	{
		pTemp->data = data;
		pTemp->next = NULL;
	}
	return pTemp;
}
//��ӡ������
void Printlist(PNode pHead)
{
	PNode pCur = pHead;

	while (pCur)
	{
		printf("%d ->", pCur->data);
		pCur = pCur->next;
	}

	printf("\n");
}

//��β��ͷ��ӡ������
void PrintListFromTailToHead(PNode pHead)
{
	if (pHead)
	{
		PrintListFromTailToHead(pHead->next);
		printf("%d->", pHead->data);
	}
}
//ɾ����ͷ������ķ�β�ڵ�
void DeleteNotTailNode(PNode pPos)
{
	PNode pDelNode = NULL;
	if (NULL == pPos || NULL == pPos)
		return;

	pDelNode = pPos->next;
	pPos->data = pDelNode->data;
	pPos->next = pDelNode->next;
	free(pDelNode);

}
//����ͷ�������ͷ���ǰ�����½ڵ�
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
		return;
	else
	{
		PNode pNewNode = BuyNode(pos->data);
		if (pNewNode)
		{
			pNewNode->next = pos->next;
			pos->next = pNewNode;
			pos->data = data;
		}
	}

}

void Sort(PNode l1, PNode l2)
{
	PNode p1, p2, tmp;
	p1 = l1;
	p2 = l2->next;
	while (p1->next && p2)
	{
		if (p1->next->data > p2->data)
		{
			tmp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = tmp;
		}
		else
			p1 = p1->next;
	}
	if (p2)
		p1->next = p2;
}

PNode ReverseList(PNode pHead)
{
	PNode pPre;
	PNode pCur;
	PNode Next;

	pPre = pHead;
	pCur = pHead->next;
	Next = NULL;
	while (pCur)
	{
		Next = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = Next;
	}
	pHead->next = NULL;
	pHead = pPre;//pPre��Ϊ����ͷ��� 
}


PNode Search(PNode Head, int k)
{

	int length = 0;
	PNode pCur = Head;
	while (pCur != NULL)
	{
		length++;
		pCur = pCur->next;
	}
	if (Head == NULL || k == 0 || k > length)
	{
		return NULL;
	}

	PNode Fast = Head;
	PNode Slow = Head;

	for (int i = 0; i<k - 1; i++)
	{
		Fast = Fast->next;
	}

	while (Fast->next != NULL)
	{
		Fast = Fast->next;
		Slow = Slow->next;
	}
	return Slow;
}

bool IsExitsLoop(PNode Head)
{
	PNode Fast = Head;
	PNode Slow = Head;
	while (Fast && Fast->next)
	{
		Slow = Slow->next;
		Fast = Fast->next->next;
		if (Fast == Slow)
			return true;
	}

	if (Fast == NULL || Fast->next == NULL)
		return false;

}

 PNode FindLoopPort(PNode Head)
{
	PNode Slow = Head;
	PNode Fast = Head;

	while (Fast && Fast->next)
	{
		Slow = Slow->next;
		Fast = Fast->next->next;
		if (Slow == Fast) break;//�ҵ�������
	}

	if (Fast == NULL || Fast->next == NULL)
		return NULL;

	Slow = Head;
	while (Slow != Fast)
	{
		Slow = Slow->next;
		Fast = Fast->next;
	}

	return Slow;
}

 unsigned int GetLoopLength(PNode Head)
 {
	 PNode Slow = Head, Fast = Head;

	 while (Fast && Fast->next)
	 {
		 Slow = Slow->next;
		 Fast = Fast->next->next;
		 if (Slow == Fast) break;
	 }

	 if (Fast == NULL || Fast->next == NULL)
		 return 0;

	 PNode meet = Slow;
	 Slow = meet->next;
	 Fast = meet->next->next;
	 unsigned int len = 1;
	 while (Slow != Fast)
	 {
		 len++;
		 Slow = Slow->next;
		 Fast = Fast->next->next;
	 }

	 return len;
 }


 PNode Find_Node(PNode Head1, PNode Head2)
 {
	 if (NULL == Head1 || NULL == Head2)
	 {
		 return NULL;//�����Ϊ�յ������϶��ǲ��ཻ��  
	 }
	 PNode p1, p2;
	 p1 = Head1;
	 p2 = Head2;
	 int len1 = 0;
	 int len2 = 0;
	 int diff = 0;
	 while (NULL != p1->next)
	 {
		 p1 = p1->next;
		 len1++;
	 }
	 while (NULL != p2->next)
	 {
		 p2 = p2->next;
		 len2++;
	 }
	 if (p1 != p2) //������һ���ڵ㲻��ͬ,����NULL  
	 {
		 return NULL;
	 }
	 diff = abs(len1 - len2);
	 if (len1 > len2)
	 {
		 p1 = Head1;
		 p2 = Head2;
	 }
	 else
	 {
		 p1 = Head2;
		 p2 = Head1;
	 }
	 for (int i = 0; i<diff; i++)
	 {
		 p1 = p1->next;
	 }
	 while (p1 != p2)
	 {
		 p1 = p1->next;
		 p2 = p2->next;
	 }
	 return p1;
 }
int main()
{

	return 0;
}