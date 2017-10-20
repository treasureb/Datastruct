#include<iostream>
using namespace std;


template <class T>
struct Node
{
	Node(T& d)//改变外部实参的值，所以要传引用
	{
		data = d;
		next = NULL;
	}
	T data;
	Node* next;
};

template<class T>
class Queue
{
public:
	Queue(T& n)
	{
		Node<T> *p = new Node<T>(n);
		length = 0;
		front = rear = p;
	}

	bool Queuelength()
	{
		cout << "当前队列长度：" << length << endl;
		return true;
	}

	bool Empty()
	{
		return length == 0;
	}

	void Push(T n)
	{
		Node<T> *p = new Node<T>(n);
		rear->next = p;
		rear = p;
		length++;
	}

	bool Pop()
	{
		if (front == rear)
			return false;
		Node<T> *p = front->next;
		front->next = p->next;
		if (front->next == NULL)
			rear = front;
		delete p;
		length--;
		return true;
	}
	void PrintQueue()
	{
		Node<T> *p = front->next;

		cout << "遍历队列：" << endl;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}


private:
	int length;
	Node<T> *front;
	Node<T> *rear;
};
int main()
{
	int head = 0;
	Queue<int> *lq = new Queue<int>(head);
	lq->Queuelength();
	lq->Push(1);
	lq->Push(2);
	lq->Push(3);
	lq->Push(4);
	lq->Queuelength();
	lq->PrintQueue();
	lq->Pop();
	lq->Queuelength();
	return 0;
}