#include<iostream>
#include<stack>
#include<string>


bool paren(const std::string &str)
{
	std::stack<char> s;
	for (auto i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '(':s.push(str[i]);break;
		case '{':s.push(str[i]); break;
		case '[':s.push(str[i]); break;
		case ')':
			if (s.top() != '(')
				return false;
			else
				s.pop(); break;
		case '}':
			if (s.top() != '{')
				return false;
			else
				s.pop(); break;
		case ']':
			if (s.top() != '[')
				return false;
			else
				s.pop(); break;
		}
	}
	return s.empty();
}
int main()
{
	std::string strBuf = "()[]{}";
	std::cout << "The string is:" << strBuf << " ";
	if (paren(strBuf))
		std::cout << "����ƥ��";
	else
		std::cout << "���Ų�ƥ��";
	std::cout << std::endl;
	return 0;
}
