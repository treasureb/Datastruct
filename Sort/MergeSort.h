#ifndef __MERGESORT__
#define __MERGESORT__

#include<iostream>
#include<assert.h>
#include"InsertSort.h"
using namespace std;

void _MergeSort(int* array,int left,int right)
{
    assert(array);

    if(left >= right)
    {
        return;
    }

    //防止递归过深，采用直接插入优化
    if((right - left) > 5)
    {
        InsertSort(array,right - left);
    }
    
    int mid = left +((right - left) >> 1);
    _MergeSort(array,0,mid);
    _MergeSort(array,mid+1,right);
    
    int* tmp = new int[right -left +1];
    int i = left,j = mid+1,curTmp = 0;
    while(i <= mid && j <= right)
    {
        if(array[i] > array[j])
        {
            tmp[curTmp++] = array[j++];
        }
        else
        {
            tmp[curTmp++] = array[i++];
        }
    }
    if(i <= mid)
    {
        for(;i<=mid;i++)
        {
            tmp[curTmp++] = array[i];
        }
    }
    if(j<= right)
    {
        for(;j<=right;j++)
        {
            tmp[curTmp++] = array[j];
        }
    }

    curTmp = 0;
    for(int i = left;i<= right;i++)
    {
        array[i] = tmp[curTmp++];
    }

    delete[] tmp;
}

void MergeSort(int* array,int size)
{
    assert(array);
    _MergeSort(array,0,size - 1);
}

void Print(int* array,int size)
{
    for(int i =0;i<size;++i)
    {
        cout<<array[i] <<" ";
    }
    cout<<endl;
}

void TestMergeSort()
{
    int array[] = {5,2,7,4,9,1,3,0,6,8};
    MergeSort(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif
