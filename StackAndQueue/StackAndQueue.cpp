#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#if 0
template <class T>
class CQueue
{
public:
	CQueue(void)
	{}

	~CQueue(void)
	{}
	
	void Push(const T& value)//直接往stack1中push数据
	{
		stack1.push(value);
	}

	T Pop()//stack2里存放队列的输出顺序
	{
		if (stack2.size() <= 0)//如果stack2为空，则将stack1中的说有数据加载到stack2中
		{
			while (stack1.size() > 0)
			{
				T value = stack1.top();
				stack1.pop();
				stack2.push(value);
			}
		}
		
		if (stack2.size() == 0)
			throw  new exception("queue is empty");

		T front = stack2.top();
		stack2.pop();

		return front;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};
#endif

#if 1
template <class T>
class CStack
{
public:

	CStack(void)
	{}

	~CStack(void)
	{}

	void Push(const T& value)
	{
		//往不为空的一个队列中push数据
		if (queue1.size() > 0)
			queue1.push(value);
		else if (queue2.size() > 0)
			queue2.push(value);
		else
			queue1.push(value);
	}

	//Pop操作每次都要将数据进行来回移动
	T Pop()
	{
		//q2位空，则将q1的数据除最后一个外，全部转移到q2中，将剩下的有一个pop掉
		if (queue2.size() == 0)
		{
			//最后一个就是待pop的数据
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
#endif


int main()
{
#if 0
	CQueue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);

	cout<<q.Pop()<<endl;

#endif

#if 1
	CStack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);

	cout << s.Pop()<<endl;
	cout << s.Pop() << endl;
	//cout << s.deleteTop() << endl;
	system("pause");
#endif
	return 0;
}