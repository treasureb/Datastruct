#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool CheckStack(vector<int> In, vector<int> Out)
{
	if (In.size() != Out.size())//�ж���ջ�ͳ�ջ�ĸ����Ƿ���ͬ
		cout << "Input Error!\n" << endl;
	
	stack<int> s;
	size_t InIndex = 0;
	size_t OutIndex = 0;
	while (InIndex <= In.size() && OutIndex <= Out.size())
	{
		if (In[InIndex] == Out[OutIndex])//�����ջ���ڳ�ջ����������Ƚ�
		{
			++InIndex;
			++OutIndex;
		}
		else if (!s.empty() && Out[OutIndex] == s.top())//�����ջ�ͳ�ջ��ƥ�䣬��ȥ��ջ����
		{
			while (!s.empty() && Out[OutIndex] == s.top())
			{
				s.pop();
				++OutIndex;
			}
		}
		else//��ǰ��ƥ�䣬��ջ�����м���������
		{
			s.push(In[InIndex]);
			++InIndex;
		}

		if (InIndex >= In.size())//��ջ�����Ѿ����꣬��ջ���к�ջ��Ԫ��һһ�Ƚ�
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