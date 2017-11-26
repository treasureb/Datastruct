#ifndef __QUICKSORT__
#define __QUICKSORT__

#include<iostream>
#include"InsertSort.h"
#include<stack>
#include<assert.h>
using namespace std;

int GetMid(int* array,int left,int right)
{
    assert(array);
    int mid = left + ((right - left)>>1);
    if(array[left] <= array[right])
    {
        if(array[mid] <  array[left])
            return left;
        else if(array[mid] > array[right])
            return right;
        else
            return mid;
    }
    else
    {
        if(array[mid] < array[right])
            return right;
        else if(array[mid] > array[left])
            return left;
        else
            return mid;
    }

}

int PartSort1(int* array,int left,int right)
{
    assert(array);
    int mid = GetMid(array,left,right);
    swap(array[mid],array[right]);
    
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

int PartSort2(int* array,int left,int right)
{
    assert(array);
    int mid = GetMid(array,left,right);
    swap(array[mid],array[right]);
    
    int key = array[right];
    while(left < right)
    {
        while(left < right && array[left] <= key)
            ++left;
        array[right] = array[left];
       
        while(left < right && array[right] >= key)
            --right;
        array[left] = array[right];
    }
    array[right] = key;
    return right;
}

int PartSort3(int* array,int left,int right)
{
    assert(array);
    int mid = GetMid(array,left,right);
    swap(array[mid],array[right]);
    if(left < right)
    {
        int key = array[right];
        int cur = left;
        int pre = left - 1;
        while(cur < right)
        {
            while(array[cur] < key && ++pre != cur)
            {
                swap(array[cur],array[pre]);
            }
            ++cur;
        }
        swap(array[++pre],array[right]);
        return pre;
    }
    return -1;
}

void QuickSort(int* array,int left,int right)
{
    assert(array);
    if(left >= right)
        return;

    if((right - left) <= 5)
    InsertSort(array,right-left+1);
    
    int index = PartSort3(array,left,right);
    QuickSort(array,left,index-1);
    QuickSort(array,index+1,right);
}


void QuickSortNotR(int* array,int left,int right)
{
    assert(array);
    stack<int> s;
    s.push(left);
    s.push(right);
    while(!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int index = PartSort3(array,left,right);
        if((index - 1) > left)
        {
            s.push(left);
            s.push(index -1);
        }  
        if((index + 1) < right)
        {
            s.push(index + 1);
            s.push(right);
        }
    }

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
    int array[] = {23,765,234,123,7,54,9,45,98};
    QuickSort(array,0,sizeof(array)/sizeof(array[0])-1);
    Print(array,sizeof(array)/sizeof(array[0]));

    int array2[] = {23,765,234,123,7,54,9,45,98};
    QuickSortNotR(array2,0,sizeof(array2)/sizeof(array2[0] -1));
    Print(array2,sizeof(array2)/sizeof(array2[0]));
}
#endif
