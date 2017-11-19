#ifndef __BUBBLESORT__
#define __BUBBLESORT__ 

#include<iostream>
#include<assert.h>
using namespace std;

void BubbleSort(int* array,int size)
{
    assert(array);
    bool Flag = false;
    for(int end = size-1;end>0;--end)
    {
        for(int i = 0;i < size-1;++i)
        {
            if(array[i] > array[i+1])
             swap(array[i],array[i+1]);
            Flag = true;
        }   

        if(!Flag)
            break;
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

void TestBubbleSort()
{
    int array[10] = {2,6,4,8,9,1,5,0,7,3};
    BubbleSort(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif




