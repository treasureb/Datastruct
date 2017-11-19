#ifndef __QUICKSORT__
#define __QUICKSORT__

#include<iostream>
#include<assert.h>
using namespace std;

int PartSort(int* array,int left,int right)
{
    assert(array);
    int& key = array[right];
    while(left < right)
    {
        while(left < right && array[left] <= key)
            ++left;
        while(left < right && array[right] >= key)
            --right;

        swap(array[left],array[right]);
    }

    swap(array[left],key);
    return left;
}

void QuickSort(int* array,int left,int right)
{
    assert(array);
    if(left >= right)
        return;
    
    int index=PartSort(array,left,right);
    QuickSort(array,left,index-1);
    QuickSort(array,index+1,right);
}

void  Print(int* array,int size)
{
    assert(array);
    for(int i = 0;i<size;++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void TestQuickSort()
{
    int array[] = {1,3,7,0,4,8,2,6,9,5};
    QuickSort(array,0,sizeof(array)/sizeof(array[0])-1);
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif
