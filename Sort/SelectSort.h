#ifndef __SELECTSORT__
#define __SELECTSORT__

#include<iostream>
#include<assert.h>
using namespace std;

void SelectSort(int* array,int size)
{
    assert(array);
    int Begin = 0;
    int End = size - 1;
    while(Begin < End)
    {
        int MaxPos = Begin;
        int MinPos = Begin;
        for(int i = Begin;i <= End;++i)
        {
            if(array[i] > array[MaxPos])
                MaxPos = i;
            if(array[i] < array[MinPos])
                MinPos = i;
        }       
            swap(array[MaxPos],array[End]);
            if(MinPos == End)
                MinPos = MaxPos;
            
            swap(array[MinPos],array[Begin]);
            Begin++;
            End--;
    }
}

void SelectSort1(int* array,int size)
{
    assert(array);
    for(int i = 0 ;i < size - 1;i++)
    {
        int MaxPos = 0;
        for(int j =0;j < size- i;j++)
        {
            if(array[j] > array[MaxPos])
                MaxPos = j;
        }
        if(MaxPos != size-i-1)
        swap(array[MaxPos],array[size-i-1]);
    }
}

void Print(int* array,int size)
{
    for(int i = 0;i < size;++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void TestSelectSort()
{
    int array[] = {2,5,4,9,3,6,8,7,1,0};
    SelectSort(array,sizeof(array)/sizeof(array[0]));
   //SelectSort1(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif
