#include<stdlib.h>
#include<iostream>

int NumberOf1(int n)//如果输入的是负数，最高位为1，因为是负数，所以不管怎么移位最高位始终为1，所以会进入死循环
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

int NumberOf1(int n)//为了防止死循环，定义一个无符号的flag，然后每与一次就进行左移
{
	//缺点：有多少位就要进行多少次的比对和移位
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



//一个整数减去1，在和原数进行与运算，二进制中1的个数会减1。
//减1之后，最右边的1之后的0都变成1，前面的位保持不变。进行一次与运算，整个二进制中1的个数少1
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