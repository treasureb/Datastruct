#include<iostream>

#if 0
//����ö�ٷ�
int GetCommonDivisor(int number1, int number2)
{
	int smallNumber = number1 < number2 ? number1 : number2;
	int bigNumber = number1 > number2 ? number1 : number2;

	//��������������Ǳ�����ϵ�������Լ��ΪС����
	if (bigNumber % smallNumber == 0)
		return smallNumber;

	//�������Ĺ�Լ������Ϊ1
	int commonDivisor = 1;

	//��������������Ǳ�����ϵ�������Լ������ǽ�Сֵ��һ��
	for (int i = 2; i <= smallNumber / 2; ++i)
	{
		if ((smallNumber%i == 0) && (bigNumber%i == 0))
			commonDivisor = i;
	}
	return commonDivisor;
}
#endif


//�ݹ������Լ��
int gcd(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

#if 0
//շת�����
int GetCommonDivisor(int number1, int number2)
{
	int commonDivisor = 1;
	//ת��Ϊ�������ͽ�Сֵ�����Լ��
	if (number1 > number2)
		commonDivisor = gcd(number1, number2);
	else
		commonDivisor = gcd(number2, number1);

	return commonDivisor;
}
#endif

#if 0
//���������
int GetCommonDivisor(int number1, int number2)
{
	if (number1 == number2)
		return number1;

	if (number1 < number2)
		return GetCommonDivisor(number2 - number1, number1);
	else
		return GetCommonDivisor(number1 - number2, number2);
}
#endif

#if 1
//���߽��
int GetCommonDivisor(int number1, int number2)
{
	//���������ȣ�ֱ�ӷ�������һ���������Լ��
	if (number1 == number2)
		return number1;
	
	if (number1 < number2)
		//��֤����1ʼ�մ��ڲ���2
		return GetCommonDivisor(number2, number1);
	else
	{
		//������Ϊż����ͬʱ����2�ٽ������
		if (!(number1 & 1) && !(number2 & 1))
			return GetCommonDivisor(number1 >> 1, number2 >> 1) << 1;
		//number1Ϊż��������2
		else if (!(number1 & 1) && number2 & 1)
			return GetCommonDivisor(number1 >> 1, number2);
		//number2Ϊż��������2
		else if (number1 & 1 && !(number2 & 1))
			return GetCommonDivisor(number1, number2 >> 1);
		else
			//��������Ϊ������ʹ��һ�θ��������
			return GetCommonDivisor(number1, number1 - number2);
	}
}
#endif

int main()
{
	int ret = GetCommonDivisor(12, 4);
	return 0;
}