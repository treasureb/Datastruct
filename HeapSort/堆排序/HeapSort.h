#pragma once

#include<iostream>
using namespace std;


void AdJustDown(int *arr, size_t size, int root)
{
	int parent = root;
	int child = root * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size  && arr[child + 1] > arr[child])
			++child;

		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int *arr, size_t size)
{
	//½¨¶Ñ
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdJustDown(arr, size, root);
	}
	
	int end = size - 1;
	while (end)
	{
		swap(arr[0], arr[end]);
		AdJustDown(arr, end, 0);
		--end;
	}
}


void Test()
{
	int arr[] = {9,8,7,6,5,4,3,2,1};
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
}