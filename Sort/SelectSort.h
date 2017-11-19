#ifndef __SELECTSORT__
#define __SELECTSORT__

#include<iostream>
#include<assert.h>
using namespace std;

void SelectSort(int* array,int size)
{
    assert(array);
    int Begin = 0;
    int End = size-1;
    while(Begin < End)
    {
        int MaxPos = Begin;
        int MinPos = Begin;
        for(int i = Begin;i < End;++i)
        {
            if(array[i] > array[MaxPos])
                MaxPos = i;
            if(array[i] < array[MinPos])
                MinPos = i;
        }       
            if(MaxPos != Begin)
            swap(array[MaxPos],array[End]);
           
            swap(array[MinPos],array[Begin]);
            ++Begin;
            --End;
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
    int array[10] = {2,6,4,8,9,1,5,0,7,3};
    SelectSort(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif
