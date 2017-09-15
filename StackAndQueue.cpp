#include<iostream>
#include<stack>
#include<queue>
using namespace std;


//template <class T>
//class CQueue
//{
//public:
//	CQueue(void)
//	{}
//
//	~CQueue(void)
//	{}
//	
//	void appendTail(const T& element)
//	{
//		stack1.push(element);
//	}
//
//	T deleteHead()//stack2里存放队列的输出顺序
//	{
//		if (stack2.size() <= 0)
//		{
//			while (stack1.size() > 0)
//			{
//				T& data = stack1.top();
//				stack1.pop();
//				stack2.push(data);
//			}
//		}
//		
//		if (stack2.size() == 0)
//			throw  new exception("queue is empty");
//
//		T head = stack2.top();
//		stack2.pop();
//
//		return head;
//	}
//
//private:
//	stack<T> stack1;
//	stack<T> stack2;
//};



template <class T>
class CStack
{
public:

	CStack(void)
	{}

	~CStack(void)
	{}

	void appendTop(const T& element)
	{
		if (queue1.size() > 0)
			queue1.push(element);
		else if (queue2.size() > 0)
			queue2.push(element);
		else
			queue1.push(element);
	}

	T deleteTop()
	{
		if (queue2.size() == 0)
		{
			while (queue1.size() > 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}

			T& top = queue1.front();
			queue1.pop();

			return top;
		}

		if (queue1.size() == 0)
		{
			while (queue2.size() > 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}

			T& top = queue2.front();
			queue2.pop();

			return top;
		}
	}

private:
	queue<T> queue1;
	queue<T> queue2;
};

int main()
{
	/*CQueue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);

	cout<<q.deleteHead()<<endl;
*/

	CStack<int> s;
	s.appendTop(1);
	s.appendTop(2);
	s.appendTop(3);

	cout << s.deleteTop()<<endl;
	cout << s.deleteTop() << endl;
	//cout << s.deleteTop() << endl;
	system("pause");
	return 0;
}