#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool CheckStack(vector<int> In, vector<int> Out)
{
	if (In.size() != Out.size())//判断入栈和出栈的个数是否相同
		cout << "Input Error!\n" << endl;
	
	stack<int> s;
	size_t InIndex = 0;
	size_t OutIndex = 0;
	while (InIndex <= In.size() && OutIndex <= Out.size())
	{
		if (In[InIndex] == Out[OutIndex])//如果入栈等于出栈，继续往后比较
		{
			++InIndex;
			++OutIndex;
		}
		else if (!s.empty() && Out[OutIndex] == s.top())//如果入栈和出栈不匹配，就去和栈顶比
		{
			while (!s.empty() && Out[OutIndex] == s.top())
			{
				s.pop();
				++OutIndex;
			}
		}
		else//当前不匹配，入栈的序列继续往后走
		{
			s.push(In[InIndex]);
			++InIndex;
		}

		if (InIndex >= In.size())//入栈序列已经走完，出栈序列和栈顶元素一一比较
		{
			while (!s.empty() && Out[OutIndex] == s.top())
			{
				s.pop();
				++OutIndex;
			}

			if (InIndex == In.size() && OutIndex == Out.size())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int main()
{
#if 0
	vector<int> In = { 1, 2, 3, 4, 5 };
	vector<int> Out = { 5, 4, 3, 2, 1 };
	cout<<CheckStack(In, Out)<<endl;
#endif

#if 1
	vector<int> In = { 1, 2, 3, 4, 5 };
	vector<int> Out = { 3, 2, 4, 5, 1 };
	cout << CheckStack(In, Out) << endl;
#endif

#if 0
	vector<int> In = { 1, 2, 3, 4, 5 };
	vector<int> Out = { 5, 4, 2, 3, 1 };
	cout << CheckStack(In, Out) << endl;
#endif
	system("pause");
	return 0;
}