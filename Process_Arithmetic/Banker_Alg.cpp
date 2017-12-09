#include<iostream>
#include<vector>
using namespace std;

//��ʼ����Դ
class InitResource
{
public:
	InitResource(int A,int B,int C,int D)
	: _A(A)
	, _B(B)
	, _C(C)
	, _D(D)
	{}

	//���ر�׼���
	friend ostream& operator << (ostream& os, const InitResource& obj)
	{
		os << "A:" << obj._A << " B:" << obj._B << " C:" << obj._C << " D:" << obj._D << endl;
		return os;
	}

	//����+
	InitResource operator+(const InitResource& rs)
	{
		int A = this->_A + rs._A;
		int B = this->_B + rs._B;
		int C = this->_C + rs._C;
		int D = this->_D + rs._D;

		return InitResource(A, B, C, D);
	}

	//����-
	InitResource operator-(const InitResource& rs)
	{
		int A = this->_A - rs._A;
		int B = this->_B - rs._B;
		int C = this->_C - rs._C;
		int D = this->_D - rs._D;

		return InitResource(A, B, C, D);
	}

	//��ֵ���������
	void operator = (const InitResource& rs)
	{
		this->_A = rs._A;
		this->_B = rs._B;
		this->_C = rs._C;
		this->_D = rs._D;
	}

	//����<=
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

//������
class Process
{
	//���ڳ�Ա��������Ϊ˽�У����м��㷨��Ҫʹ�ã���������Ϊ��Ԫ
	friend int BankerAlgorithm();
public:
	Process(int id, const InitResource& Maxmum, const InitResource& Current)
		:_id(id)
		, _Maxmum(Maxmum)
		, _Current(Current)
	{}

	//���ر�׼���
	friend ostream& operator <<(ostream& os, const Process & obj)
	{
		
		os<<endl<< " Max" << obj._Maxmum << " Cur" << obj._Current;
			return os;
	}
private:
	int _id;

	//���ڻ���Ҫ����Դ����ֱ������������ڶ�����һ����Ա����
	InitResource _Maxmum;//�������
	InitResource _Current;//��ǰ����
};

//���м��㷨
int BankerAlgorithm()
{
	//��ǰ��ʹ����Դ��
	InitResource SystemAvaliable(3, 1, 0, 2);
	//����vector�洢���̸�����Դ
	vector<Process> Processes;
	Processes.push_back(Process(1, InitResource(3, 3, 2, 2), InitResource(1, 2, 0, 1)));
	Processes.push_back(Process(2, InitResource(1, 2, 3, 4), InitResource(1, 2, 3, 3)));
	Processes.push_back(Process(3, InitResource(1, 1, 5, 0), InitResource(1, 1, 2, 0)));

	while (!Processes.empty())
	{
		//��ʶ�Ƿ�ȫ
		bool flag = false;
		//ʹ�õ���������
		vector<Process>::iterator it = Processes.begin();
		while (it != Processes.end())
		{
			cout << "---System" << SystemAvaliable<<endl;
			cout << "---For Process " << it->_id<<" " << (*it)<<endl;
			//��ǰ��ʹ����Դ�����ڽ��̵���Ҫ
			if (it->_Maxmum - it->_Current <= SystemAvaliable)
			{
				cout << "---Process   " << it->_id << "  Could  be Terminated.n" << endl;
				//�����н����Ľ���ӵ�е���Դ����
				SystemAvaliable = SystemAvaliable + it->_Current;
				Processes.erase(it);
				flag = true;//�ý��̳ɹ�ִ�У���ʶΪtrue
				break;
			}
			else
			{
				cout << "---Process   " << it->_id<< "  Could  Not be Terminated.n" << endl;
				++it;
			}
		}
		//�����ʶΪfalse��˵����ǰ����˳�򲻰�ȫ
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