#include<iostream>
#include<stack>
using namespace std;


#if 0 
template<class T>
class MinStack
{
public:
	void Push2(const T value)
	{
		if (_s.empty() || _min.top() > value)
		{
			_s.push(value);
			_min.push(value);
		}
		else
		{
			_s.push(value);
			_min.push(_min.top());
		}

	}

	void Pop()
	{
		_s.pop();
		_min.pop();
	}

	T Min()
	{
		return _min.top();
	}
private:
	stack<T> _s;
	stack<T> _min;
};
#endif

#if 0 
template <class T>
class MinStack
{
public:
	void Push(const T& value)
	{
		if (_s.empty() || _s.top().second > value)
		{

			_s.push(make_pair(value, value));
		}
		else
		{
			_s.push(make_pair(value, _s.top().second));
		}
	}

	void Pop()
	{
		_s.pop();
	}

	T Min()
	{
		return _s.top().second;
	}
private:
	stack<pair<int, int>> _s;
};
#endif

#if 0
template <class T>
class MinStack
{
public:
	void Push(const T value)
	{
		if (_s.empty() || _s.top() > value)
		{
			_s.push(value);
			_s.push(value);
		}
		else
		{
			T top = _s.top();
			_s.push(value);
			_s.push(top);
		}
	}

	void Pop()
	{
		_s.pop();
		_s.pop();
	}

	int Min()
	{
		return _s.top();
	}
private:
	stack<int> _s;
};
#endif

template <class T>
class MinStack
{
public:
	void Push(const T value)
	{
		if (_s.empty() || _min.top().first > value)
		{
			_s.push(value);
			_min.push(make_pair(value, 1));
		}
		else if (_min.top().first == value)
		{
			_s.push(value);
			_min.top().second += 1;
		}
		else
		{
			_s.push(value);
		}
	}

	void Pop()
	{
		T top = _s.top();
		if (top == _min.top().first)
		{
			if (_min.top().second > 1)
				--_min.top().second;
			else
				_min.pop();

			_s.pop();
		}
		else
		{
			_s.pop();
		}
	}

	int Min()
	{
		return _min.top().first;
	}
private:
	stack<int> _s;
	stack<pair<int, int>> _min;
};

int main()
{
#if 0 
	MinStack<int> min;
	min.Push1(1);
	min.Push1(2);
	min.Push1(3);
	min.Push1(2);
	min.Push1(4);
	min.Min();
#endif

	MinStack<int> min;
	min.Push(5);
	min.Push(2);
	min.Push(3);
	min.Push(2);
	min.Push(1);
	min.Min();

	min.Pop();
	min.Pop();
	min.Pop();
	min.Pop();
	system("pause");
	return 0;
}