#include<iostream>
#include<vector>
using namespace std;

//初始化资源
class InitResource
{
public:
	InitResource(int A,int B,int C,int D)
	: _A(A)
	, _B(B)
	, _C(C)
	, _D(D)
	{}

	//重载标准输出
	friend ostream& operator << (ostream& os, const InitResource& obj)
	{
		os << "A:" << obj._A << " B:" << obj._B << " C:" << obj._C << " D:" << obj._D << endl;
		return os;
	}

	//重载+
	InitResource operator+(const InitResource& rs)
	{
		int A = this->_A + rs._A;
		int B = this->_B + rs._B;
		int C = this->_C + rs._C;
		int D = this->_D + rs._D;

		return InitResource(A, B, C, D);
	}

	//重载-
	InitResource operator-(const InitResource& rs)
	{
		int A = this->_A - rs._A;
		int B = this->_B - rs._B;
		int C = this->_C - rs._C;
		int D = this->_D - rs._D;

		return InitResource(A, B, C, D);
	}

	//赋值运算符重载
	void operator = (const InitResource& rs)
	{
		this->_A = rs._A;
		this->_B = rs._B;
		this->_C = rs._C;
		this->_D = rs._D;
	}

	//重载<=
	bool operator <= (const InitResource& rs)
	{
		return (this->_A <= rs._A) && (this->_B <= rs._B) && (this->_C <= rs._C) && (this->_D <= rs._D);
	}

private:
	int _A;
	int _B;
	int _C;
	int _D;
};

//进程类
class Process
{
	//由于成员函数声明为私有，银行家算法中要使用，必须声明为友元
	friend int BankerAlgorithm();
public:
	Process(int id, const InitResource& Maxmum, const InitResource& Current)
		:_id(id)
		, _Maxmum(Maxmum)
		, _Current(Current)
	{}

	//重载标准输出
	friend ostream& operator <<(ostream& os, const Process & obj)
	{
		
		os<<endl<< " Max" << obj._Maxmum << " Cur" << obj._Current;
			return os;
	}
private:
	int _id;

	//对于还需要的资源数量直接相减，不用在多声明一个成员变量
	InitResource _Maxmum;//最大需求
	InitResource _Current;//当前已有
};

//银行家算法
int BankerAlgorithm()
{
	//当前可使用资源数
	InitResource SystemAvaliable(3, 1, 0, 2);
	//采用vector存储进程各项资源
	vector<Process> Processes;
	Processes.push_back(Process(1, InitResource(3, 3, 2, 2), InitResource(1, 2, 0, 1)));
	Processes.push_back(Process(2, InitResource(1, 2, 3, 4), InitResource(1, 2, 3, 3)));
	Processes.push_back(Process(3, InitResource(1, 1, 5, 0), InitResource(1, 1, 2, 0)));

	while (!Processes.empty())
	{
		//标识是否安全
		bool flag = false;
		//使用迭代器遍历
		vector<Process>::iterator it = Processes.begin();
		while (it != Processes.end())
		{
			cout << "---System" << SystemAvaliable<<endl;
			cout << "---For Process " << it->_id<<" " << (*it)<<endl;
			//当前可使用资源数大于进程的需要
			if (it->_Maxmum - it->_Current <= SystemAvaliable)
			{
				cout << "---Process   " << it->_id << "  Could  be Terminated.n" << endl;
				//将运行结束的进程拥有的资源回收
				SystemAvaliable = SystemAvaliable + it->_Current;
				Processes.erase(it);
				flag = true;//该进程成功执行，标识为true
				break;
			}
			else
			{
				cout << "---Process   " << it->_id<< "  Could  Not be Terminated.n" << endl;
				++it;
			}
		}
		//如果标识为false，说明当前运行顺序不安全
		if (!flag)
		{
			cout << "Fail,It's an Unsafe State" << endl;
			return 1;
		}
	}
	cout << "Success,It's a Safe State" << endl;
	return 0;
}
int main()
{	
	BankerAlgorithm();
	system("pause");
	return 0;
}