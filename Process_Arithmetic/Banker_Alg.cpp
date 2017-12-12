//#include<iostream>
//#include<vector>
//using namespace std;
//
////初始化资源
//class InitResource
//{
//public:
//	InitResource(int A,int B,int C,int D)
//	: _A(A)
//	, _B(B)
//	, _C(C)
//	, _D(D)
//	{}
//
//	//重载标准输出
//	friend ostream& operator << (ostream& os, const InitResource& obj)
//	{
//		os << "A:" << obj._A << " B:" << obj._B << " C:" << obj._C << " D:" << obj._D << endl;
//		return os;
//	}
//
//	//重载+
//	InitResource operator+(const InitResource& rs)
//	{
//		int A = this->_A + rs._A;
//		int B = this->_B + rs._B;
//		int C = this->_C + rs._C;
//		int D = this->_D + rs._D;
//
//		return InitResource(A, B, C, D);
//	}
//
//	//重载-
//	InitResource operator-(const InitResource& rs)
//	{
//		int A = this->_A - rs._A;
//		int B = this->_B - rs._B;
//		int C = this->_C - rs._C;
//		int D = this->_D - rs._D;
//
//		return InitResource(A, B, C, D);
//	}
//
//	//赋值运算符重载
//	void operator = (const InitResource& rs)
//	{
//		this->_A = rs._A;
//		this->_B = rs._B;
//		this->_C = rs._C;
//		this->_D = rs._D;
//	}
//
//	//重载<=
//	bool operator <= (const InitResource& rs)
//	{
//		return (this->_A <= rs._A) && (this->_B <= rs._B) && (this->_C <= rs._C) && (this->_D <= rs._D);
//	}
//
//private:
//	int _A;
//	int _B;
//	int _C;
//	int _D;
//};
//
////进程类
//class Process
//{
//	//由于成员函数声明为私有，银行家算法中要使用，必须声明为友元
//	friend int BankerAlgorithm();
//public:
//	Process(int id, const InitResource& Maxmum, const InitResource& Current)
//		:_id(id)
//		, _Maxmum(Maxmum)
//		, _Current(Current)
//	{}
//
//	//重载标准输出
//	friend ostream& operator <<(ostream& os, const Process & obj)
//	{
//		
//		os<<endl<< " Max" << obj._Maxmum << " Cur" << obj._Current;
//			return os;
//	}
//private:
//	int _id;
//
//	//对于还需要的资源数量直接相减，不用在多声明一个成员变量
//	InitResource _Maxmum;//最大需求
//	InitResource _Current;//当前已有
//};
//
//
////银行家算法
//int BankerAlgorithm()
//{
//
//	//输出数据的输入
//	cout << "Please Enter Available Resources!\n" << endl;
//	cout << "A:" << "B:" << "C:" << "D:" << endl;
//	int A = 0, B = 0, C = 0, D = 0;
//	cin >> A >> B >> C >> D;
//
//	//当前可使用资源数
//	InitResource SystemAvaliable(A, B, C, D);
//	//采用vector存储进程各项资源
//	vector<Process> Processes;
//	cout << "Please Enter The Process Number" << endl;
//	int number = 0;s
//	cin >> number;
//	cout << "Please Enter The Number Of Resources Per Process" << endl;
//	int E = 0, F = 0, G = 0, H = 0;
//	for (int i = 0; i < number; i++)
//	{
//		cin >> A >> B >> C >> D >> E >> F >> G >> H;	 
//		Processes.push_back(Process(i, InitResource(A, B, C, D), InitResource(E, F, G, H)));
//	}
//
//	//银行家算法判断安全序列
//	while (!Processes.empty())
//	{
//		//标识是否安全
//		bool flag = false;
//		//使用迭代器遍历
//		vector<Process>::iterator it = Processes.begin();
//		while (it != Processes.end())
//		{
//			cout << "---System" << SystemAvaliable<<endl;
//			cout << "---For Process " << it->_id<<" " << (*it)<<endl;
//			//当前可使用资源数大于进程的需要
//			if (it->_Maxmum - it->_Current <= SystemAvaliable)
//			{
//				cout << "---Process   " << it->_id << "  Could  be Terminated.n" << endl;
//				//将运行结束的进程拥有的资源回收
//				SystemAvaliable = SystemAvaliable + it->_Current;
//				Processes.erase(it);
//				flag = true;//该进程成功执行，标识为true
//				break;
//			}
//			else
//			{
//				cout << "---Process   " << it->_id<< "  Could  Not be Terminated.n" << endl;
//				++it;
//			}
//		}
//		//如果标识为false，说明当前运行顺序不安全
//		if (!flag)
//		{
//			cout << "Fail,It's an Unsafe State" << endl;
//			return 1;
//		}
//	}
//	cout << "Success,It's a Safe State" << endl;
//	return 0;
//}
//int main()
//{	
//	BankerAlgorithm();
//	system("pause");
//	return 0;
//}


#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

struct __TaskStruct
{
	const int _pid;//进程id
	const int _ppid;//父进程id
	const int _priority;//进程优先级
	int _nice;//优先级修正参数
	const int _s_time;//进程执行所需总时间
	int _r_time;//进程已经运行时间

	__TaskStruct(int pid, int priority, int run_time)
		:_pid(pid)
		, _priority(priority)
		, _ppid(1)
		, _nice(0)
		, _s_time(run_time)
		, _r_time(0)
	{}
};
typedef __TaskStruct PCB;
/***********冒泡排序*************/
template<class Compare>
void Sort(vector<PCB*>& p, Compare com)
{
	int n = p.size();
	bool flag = false;//标记是否有过交换
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = 1; j < n - i; ++j) {
			if (com(p[j], p[j - 1])) {
				swap(p[j - 1], p[j]);
				flag = true;
			}
		}

		if (!flag)//如果没交换过则已经有序，可以直接退出
			break;
	}
}

class process
{
public:
	process()
		:_time(0)
	{}

	void Push(PCB* p)
	{
		_p.push_back(p);
	}


	void HPFS()
	{
		cout << "HPFS:" << endl;

		struct Less
		{
			bool operator()(const PCB *l, const PCB *r)
			{
				return l->_priority < r->_priority;
			}
		};
		Sort(_p, Less());
		_Run();
	}

protected:
	void _Run()//进程依序执行
	{
		for (size_t i = 0; i < _p.size(); ++i) {
			//开始执行，打印当前执行进程相关信息。
			cout << "start! [" << "pid:" << _p[i]->_pid << " priorty:" <<
				_p[i]->_priority << " _s_time:" << _p[i]->_s_time << "]" << endl;

			//pid 为 i 的进程开始执行
			while (_p[i]->_r_time < _p[i]->_s_time) {
				//getchar();
				++_p[i]->_r_time;
				++_time;
				cout << "time:" << _time << " pid:" << _p[i]->_pid << " priorty:" <<
					_p[i]->_priority << " _r_time:" << _p[i]->_r_time << endl;
			}

			cout << "finish!" << endl << endl;;
		}
	}
private:
	vector<PCB*> _p;
	int _time;
};

void test()
{
	PCB* p;
	size_t num = 0;//进程个数
	int priority = 0;//进程优先级
	int s_time = 0;//进程执行总时间
	process ps;
	cout << "Please input process number: ";
	cin >> num;
	for (size_t i = 0; i < num; ++i) {
		cin >> priority >> s_time;
		//	  pid    PR      s_time
		ps.Push(new PCB(i, priority, s_time));
	}
	ps.HPFS();
}
int main()
{
	test();
	system("pause");
}
