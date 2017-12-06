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
	
	void Push(const T& value)//ֱ����stack1��push����
	{
		stack1.push(value);
	}

	T Pop()//stack2���Ŷ��е����˳��
	{
		if (stack2.size() <= 0)//���stack2Ϊ�գ���stack1�е�˵�����ݼ��ص�stack2��
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
		//����Ϊ�յ�һ��������push����
		if (queue1.size() > 0)
			queue1.push(value);
		else if (queue2.size() > 0)
			queue2.push(value);
		else
			queue1.push(value);
	}

	//Pop����ÿ�ζ�Ҫ�����ݽ��������ƶ�
	T Pop()
	{
		//q2λ�գ���q1�����ݳ����һ���⣬ȫ��ת�Ƶ�q2�У���ʣ�µ���һ��pop��
		if (queue2.size() == 0)
		{
			//���һ�����Ǵ�pop������
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