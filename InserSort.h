#include<stdio.h>
#pragma once

void InserSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int end = arr[i];
			int left = 0;
			int right = i - 1;
			while (left <= right)
			{
				int mid = left + ((right - left) >> 1);
				if (end < arr[mid])
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			for (int j = i; j>0 && j > right + 1; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[right + 1] = end;
		}
	}
}

void Test()
{
	int arr[] = { 2, 5, 3, 6, 0, 8, 7, 1, 9, 4 };
	InserSort(arr, 10);
	for(int i = 0; i < 10;i++)
	{
		printf("%2d",arr[i]);
	}
	
}