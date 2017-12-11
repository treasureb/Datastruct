#include<iostream>

#if 0
//暴力枚举法
int GetCommonDivisor(int number1, int number2)
{
	int smallNumber = number1 < number2 ? number1 : number2;
	int bigNumber = number1 > number2 ? number1 : number2;

	//如果两个数本身是倍数关系，则最大公约数为小的数
	if (bigNumber % smallNumber == 0)
		return smallNumber;

	//两个数的公约数至少为1
	int commonDivisor = 1;

	//如果两个数本身不是倍数关系，则最大公约数最大是较小值得一半
	for (int i = 2; i <= smallNumber / 2; ++i)
	{
		if ((smallNumber%i == 0) && (bigNumber%i == 0))
			commonDivisor = i;
	}
	return commonDivisor;
}
#endif


//递归求最大公约数
int gcd(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

#if 0
//辗转相除法
int GetCommonDivisor(int number1, int number2)
{
	int commonDivisor = 1;
	//转化为求余数和较小值的最大公约数
	if (number1 > number2)
		commonDivisor = gcd(number1, number2);
	else
		commonDivisor = gcd(number2, number1);

	return commonDivisor;
}
#endif

#if 0
//更相减损术
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
//两者结合
int GetCommonDivisor(int number1, int number2)
{
	//如果两数相等，直接返回任意一个就是最大公约数
	if (number1 == number2)
		return number1;
	
	if (number1 < number2)
		//保证参数1始终大于参数2
		return GetCommonDivisor(number2, number1);
	else
	{
		//两个都为偶数，同时除以2再进行求解
		if (!(number1 & 1) && !(number2 & 1))
			return GetCommonDivisor(number1 >> 1, number2 >> 1) << 1;
		//number1为偶数，除以2
		else if (!(number1 & 1) && number2 & 1)
			return GetCommonDivisor(number1 >> 1, number2);
		//number2为偶数，除以2
		else if (number1 & 1 && !(number2 & 1))
			return GetCommonDivisor(number1, number2 >> 1);
		else
			//两个数都为奇数，使用一次更相减损术
			return GetCommonDivisor(number1, number1 - number2);
	}
}
#endif

int main()
{
	int ret = GetCommonDivisor(12, 4);
	return 0;
}