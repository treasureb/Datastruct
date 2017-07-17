#pragma once
#include<stdio.h>

void ShellSort(int *arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = gap; i < size; ++i)//如果是++gap,则外层需要在加一层循环来排每个组，++gap可以每次排每个组的一个数
		{
			int end = i - gap;
			int key = arr[i];
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end] = key;
		}
	}
}

void Test2()
{
	int arr[] = { 2, 5, 3, 6, 0, 8, 7, 1, 9, 4 };
	ShellSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%2d", arr[i]);
	}
}