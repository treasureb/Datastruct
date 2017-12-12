//#include<iostream>
//#include<vector>
//using namespace std;
//
////��ʼ����Դ
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
//	//���ر�׼���
//	friend ostream& operator << (ostream& os, const InitResource& obj)
//	{
//		os << "A:" << obj._A << " B:" << obj._B << " C:" << obj._C << " D:" << obj._D << endl;
//		return os;
//	}
//
//	//����+
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
//	//����-
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
//	//��ֵ���������
//	void operator = (const InitResource& rs)
//	{
//		this->_A = rs._A;
//		this->_B = rs._B;
//		this->_C = rs._C;
//		this->_D = rs._D;
//	}
//
//	//����<=
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
////������
//class Process
//{
//	//���ڳ�Ա��������Ϊ˽�У����м��㷨��Ҫʹ�ã���������Ϊ��Ԫ
//	friend int BankerAlgorithm();
//public:
//	Process(int id, const InitResource& Maxmum, const InitResource& Current)
//		:_id(id)
//		, _Maxmum(Maxmum)
//		, _Current(Current)
//	{}
//
//	//���ر�׼���
//	friend ostream& operator <<(ostream& os, const Process & obj)
//	{
//		
//		os<<endl<< " Max" << obj._Maxmum << " Cur" << obj._Current;
//			return os;
//	}
//private:
//	int _id;
//
//	//���ڻ���Ҫ����Դ����ֱ������������ڶ�����һ����Ա����
//	InitResource _Maxmum;//�������
//	InitResource _Current;//��ǰ����
//};
//
//
////���м��㷨
//int BankerAlgorithm()
//{
//
//	//������ݵ�����
//	cout << "Please Enter Available Resources!\n" << endl;
//	cout << "A:" << "B:" << "C:" << "D:" << endl;
//	int A = 0, B = 0, C = 0, D = 0;
//	cin >> A >> B >> C >> D;
//
//	//��ǰ��ʹ����Դ��
//	InitResource SystemAvaliable(A, B, C, D);
//	//����vector�洢���̸�����Դ
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
//	//���м��㷨�жϰ�ȫ����
//	while (!Processes.empty())
//	{
//		//��ʶ�Ƿ�ȫ
//		bool flag = false;
//		//ʹ�õ���������
//		vector<Process>::iterator it = Processes.begin();
//		while (it != Processes.end())
//		{
//			cout << "---System" << SystemAvaliable<<endl;
//			cout << "---For Process " << it->_id<<" " << (*it)<<endl;
//			//��ǰ��ʹ����Դ�����ڽ��̵���Ҫ
//			if (it->_Maxmum - it->_Current <= SystemAvaliable)
//			{
//				cout << "---Process   " << it->_id << "  Could  be Terminated.n" << endl;
//				//�����н����Ľ���ӵ�е���Դ����
//				SystemAvaliable = SystemAvaliable + it->_Current;
//				Processes.erase(it);
//				flag = true;//�ý��̳ɹ�ִ�У���ʶΪtrue
//				break;
//			}
//			else
//			{
//				cout << "---Process   " << it->_id<< "  Could  Not be Terminated.n" << endl;
//				++it;
//			}
//		}
//		//�����ʶΪfalse��˵����ǰ����˳�򲻰�ȫ
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
	const int _pid;//����id
	const int _ppid;//������id
	const int _priority;//�������ȼ�
	int _nice;//���ȼ���������
	const int _s_time;//����ִ��������ʱ��
	int _r_time;//�����Ѿ�����ʱ��

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
/***********ð������*************/
template<class Compare>
void Sort(vector<PCB*>& p, Compare com)
{
	int n = p.size();
	bool flag = false;//����Ƿ��й�����
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = 1; j < n - i; ++j) {
			if (com(p[j], p[j - 1])) {
				swap(p[j - 1], p[j]);
				flag = true;
			}
		}

		if (!flag)//���û���������Ѿ����򣬿���ֱ���˳�
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
	void _Run()//��������ִ��
	{
		for (size_t i = 0; i < _p.size(); ++i) {
			//��ʼִ�У���ӡ��ǰִ�н��������Ϣ��
			cout << "start! [" << "pid:" << _p[i]->_pid << " priorty:" <<
				_p[i]->_priority << " _s_time:" << _p[i]->_s_time << "]" << endl;

			//pid Ϊ i �Ľ��̿�ʼִ��
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
	size_t num = 0;//���̸���
	int priority = 0;//�������ȼ�
	int s_time = 0;//����ִ����ʱ��
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
