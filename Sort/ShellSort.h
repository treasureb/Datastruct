#ifndef __SHELLSORT__
#define __SHELLSORT__

#include<iostream>
#include<assert.h>
using namespace std;

void ShellSort1(int *array, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = gap; i < size; ++i)//如果是++gap,则外层需要在加一层循环来排每个组，++gap可以每次排每个组的一个数
		{
			int end = i - gap;
			int key = array[i];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end] = key;
		}
	}
}

void ShellSort2(int* array,int size)
{
    assert(array);
    int gap = size;
    while(gap > 1)
    {
        gap = gap/3 + 1;
        for(int i = 0;i < size-gap;++i)
        {
            int end = i;
            int tmp =array[end + gap];
            while(end >= 0)
            {
                if(array[end] > tmp)
                    array[end + gap] = array[end];
                else
                    break;
                end -= gap;
            }
            array[end+gap] = tmp; 
        }
    }
}

void TestShellSort()
{
	int array[] = { 2, 5, 3, 6, 0, 8, 7, 1, 9, 4 };
	ShellSort2(array, 10);
	for (int i = 0; i < 10; i++)
	{
		cout<<array[i] <<" ";
	}

    cout<<endl;

}
#endif
