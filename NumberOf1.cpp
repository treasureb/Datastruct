#include<stdlib.h>
#include<iostream>

int NumberOf1(int n)//���������Ǹ��������λΪ1����Ϊ�Ǹ��������Բ�����ô��λ���λʼ��Ϊ1�����Ի������ѭ��
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;

		n = n >> 1;
	}

	return count;
}

int NumberOf1(int n)//Ϊ�˷�ֹ��ѭ��������һ���޷��ŵ�flag��Ȼ��ÿ��һ�ξͽ�������
{
	//ȱ�㣺�ж���λ��Ҫ���ж��ٴεıȶԺ���λ
	int count = 0;
	unsigned flag = 1;
	while (flag)
	{
		if (flag & n)
			count++;

		flag = flag << 1;
	}
	return count;
}



//һ��������ȥ1���ں�ԭ�����������㣬��������1�ĸ������1��
//��1֮�����ұߵ�1֮���0�����1��ǰ���λ���ֲ��䡣����һ�������㣬������������1�ĸ�����1
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;


int main()
{

	std::cout<<NumberOf1(10)<<" ";
	system("pause");
	return 0;
}