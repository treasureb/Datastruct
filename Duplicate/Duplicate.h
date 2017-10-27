#include<iostream>

bool duplicate(int numbers[], int length, int* duplication)
{
	if (NULL == numbers || length < 0)
		return false;

	for (int i = 0; i < length; ++i)//判断输入的合法性
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				std::cout << *duplication <<std::endl;
				return true;
			}
			std::swap(numbers[i], numbers[numbers[i]]);
		}
	}

	return false;
}

void Test1()
{
	int arr[] = { 3, 1, 2, 0, 2, 5, 3 };
	int duplication[7];
	std::cout<<duplicate(arr, sizeof(arr) / sizeof(arr[0]), duplication)<<" ";
}