#ifndef __INSERTSORT__
#define __INSERTSORT__

#include<iostream>
#include<assert.h>
using namespace std;


void InsertSort(int* array,int size)
{
    assert(array);
    for(int i = 0;i < size;++i)
    {
        int end = i - 1;
        int tmp = array[i];
        while(end >= 0)
        {
            if(array[end] > tmp)
                array[end + 1] = array[end];
            else
            {
                break;
            }
            end--;
        }
        array[end + 1] = tmp;
    }
}

void InsertSort2(int* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[i - 1])
        {
            int end = array[i];
            int left = 0;
            int right = i - 1;
            while (left <= right)
            {
                int mid = left + ((right - left) >> 1);
                if (end < array[mid])
                {
                    right = mid - 1;
                }
			else
				left = mid + 1;
		}
		for (int j = i; j>0 && j > right + 1; j--)
		{
			array[j] = array[j - 1];
		}
		array[right + 1] = end;
	   }
      }
}

void TestInsertSort()
{
	int array[] = { 2, 5, 3, 6, 0, 8, 7, 1, 9, 4 };
	InsertSort(array, 10);
	for(int i = 0; i < 10;i++)
	{
		printf("%2d",array[i]);
	}
	
}
#endif
