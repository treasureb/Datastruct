#ifndef __HEAPSORT__
#define __HEAPSORT__

#include<iostream>
#include<assert.h>
using namespace std;

void AdJustDown(int* array,int root,int size)
{
    int parent = root;
    int child = (root << 1)+1;
    while(child < size)
    {
        if(child + 1<size && array[child+1] > array[child])
            ++child;

        if(array[child] > array[parent])
        {
            swap(array[child],array[parent]);
            parent = child;
            child = (child<<1)+1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *array,int size)
{
    for(int root = ((size-2)>>1);root >= 0;--root)
    {
        AdJustDown(array,root,size);
    }

    int end = size-1;
    while(end)
    {
        swap(array[0],array[end]);
        AdJustDown(array,0,end);
        --end;
    }
}

void Print(int* array,int size)
{
    assert(array);
    for(int i =0;i<size;++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void TestHeapSort()
{
    int arr[] = {2,7,4,0,8,1,5,9,6,3};
    HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
    Print(arr,sizeof(arr)/sizeof(arr[0]));
}
#endif
