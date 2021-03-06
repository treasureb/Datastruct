#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

typedef int DataType;
typedef struct Node
{
	struct Node* next;
	DataType data;
}Node, *PNode;//这里定义一个结构体类型和一个结构体指针类型

PNode BuyNode(DataType data);//声明

//初始化单链表
void InitList(PNode* pHead)
{
	*pHead = NULL;
}

//从尾部插入一个新的节点
void Pushback(PNode* pHead, DataType data)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pPre = *pHead;
        PNode pCur = BuyNode(data);
		while (pPre->next)
		{
			pPre = pPre->next;
		}
		pPre->next = pCur;
	}
}

//从尾部删除一个节点
void Popback(PNode *pHead)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else if (NULL == (*pHead)->next)//只有一个头结点
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		PNode pPre = pCur;//要删除该节点，必须保存其前一个节点

		while (pCur)
		{
			pPre = pCur;
			pCur = pCur->next;
		}

		free(pCur);
		pPre->next = NULL;

	}
}

//从头部插入一个新的节点
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

//从头部删除一个新的节点
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

//查找值为data的节点
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

//在Pos位插入一个节点
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

//删除Pos位的节点
void Erase(PNode *pHead, PNode Pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == Pos)
		return;
    //如果删除的是头节点
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

//移除链表中第一个值为data的节点
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

//移除链表中所有值为data的节点
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

//获取链表中节点的总个数
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

//获取链表中的第一个节点
PNode Front(PNode pHead)
{
	if (NULL == pHead)
	{
		return NULL;
	}
	return pHead;

}

//获取链表中的最后一个节点
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

//链表判空
bool Empty(PNode pHead)
{
	if (NULL == pHead)
		return 1;
	return 0;

}

//获取一个新的结点
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
//打印单链表
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

//从尾到头打印单链表
void PrintListFromTailToHead(PNode pHead)
{
	if (pHead)
	{
		PrintListFromTailToHead(pHead->next);
		printf("%d->", pHead->data);
	}
}

//删除无头单链表的非尾节点
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

//在无头单链表非头结点前插入新节点
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
		return;
	else
	{
		pNewNode = BuyNode(pos->data);
		if (pNewNode)
		{
			pNewNode->next = pos->next;
			pos->next = pNewNode;
			pos->data = data;
		}
	}

}

//对单链表进行排序
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

//逆置单链表
PNode ReverseList(PNode pHead)
{
	PNode pPre = NULL;
	PNode pCur = NULL;
	PNode Next = NULL;

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
	pHead = pPre;//pPre即为最后的头结点 

    return pHead;
}


//查找倒数第K个节点
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

//判断是否带环
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

    return false;
}

//寻找环的入口
 PNode FindLoopPort(PNode Head)
{
	PNode Slow = Head;
	PNode Fast = Head;

	while (Fast && Fast->next)
	{
		Slow = Slow->next;
		Fast = Fast->next->next;
		if (Slow == Fast) break;//找到相遇点
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

//求环的长度
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
		 return NULL;//如果有为空的链表，肯定是不相交的  
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
	 if (p1 != p2) //如果最后一个节点不相同,返回NULL  
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

//合并两个有序链表，合并完之后还是一个有序链表
PNode  MergeTwoList(PNode head1,PNode head2)
{
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* head = NULL;

    //选两个链表中第一个节点小的链表的头作为新链表的头
    if(head1->data > head2->data)
    {
        head = head2;
        p1 = head1;
        p2 = head2->next; 
    }
    else
    {
        head = head1;
        p2 = head2;
        p1 = head1->next;
    }

    //依次比较= hea
    Node* cur = head;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data >= p2->data)
        {
            cur->next = p2;
            cur = p2;
            p2 = p2->next;
        }
        else
        {
            cur->next = p1;
            cur = p1;
            p1 = p1->next;
        }
    }
    //链表1不为空，直接链在新表的后面
    if(p1 != NULL)
    {
        cur->next = p1;
    }
    //链表2不为空，直接链在新表的后面
    if(p2 != NULL)
    {
        cur->next = p2;
    }

    return head;
}

PNode MergeTwoListR(PNode Head1,PNode Head2)
{
    if(Head1 == NULL)
        return Head2;
    if(Head2 == NULL)
        return Head1;

    PNode MergeNode = NULL;
    if(Head1->data < Head2->data)
    {
        MergeNode = Head1;
        MergeNode->next = MergeTwoListR(Head1->next,Head2);
    }
    else
    {
        MergeNode = Head2->next;
        MergeNode->next = MergeTwoListR(Head2,Head1->next);
    }

    return MergeNode;
}

PNode JosephCircle(PNode Head,int Number)
{
    int count = Number;
    Node* pre = Head;
    Node* cur = Head;

    while(pre->next != pre)
    {
        //每次都要转m次
        count = Number;
        while(count--)
        {
            cur = pre;
            pre = pre->next;
        }

        cur->next = pre->next;
        free(pre);
        pre = cur->next;
    }
    return pre;
}

void TestMergeTwoList()
{
    PNode Head1,Head2;
    InitList(&Head1);
    InitList(&Head2);
    Pushback(&Head1,1);
    Pushback(&Head1,3);
    Pushback(&Head1,5);
    Pushback(&Head1,7);

    
    Pushback(&Head2,2);
    Pushback(&Head2,4);
    Pushback(&Head2,6);
    Pushback(&Head2,8);
    
    Printlist(Head1); 
    Printlist(Head2);
    PNode Tmp = MergeTwoList(Head1,Head2);
   // PNode Tmp = MergeTwoListR(Head1,Head2);
    Printlist(Tmp);
}

int main()
{
    TestMergeTwoList();
	return 0;
}
