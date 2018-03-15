#ifndef __QUICKSORT__
#define __QUICKSORT__

#include<iostream>
#include"InsertSort.h"
#include<stack>
#include<assert.h>
using namespace std;

//防止选到极端值，故采用三数取中法
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

//左右指针法
int PartSort1(int* array,int left,int right)
{
    assert(array);
    int mid = GetMid(array,left,right);
    swap(array[mid],array[right]);
    
    //这里是引用！！！
    int& key = array[right];
    while(left < right)
    {
        while(left < right && array[left] <= key)
            ++left;
        while(left < right && array[right] >= key)
            --right;

        swap(array[left],array[right]);
    }

    //依次遍历后将小的和大的交换
    swap(array[left],key);
    return left;
}

//挖坑法
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

        //将左边小的那个数，放入右边的坑位
        array[right] = array[left];
       
        while(left < right && array[right] >= key)
            --right;

        //将右边大的数，放入左边的坑位
        array[left] = array[right];
    }

    //最后一个坑位肯定再array[right]处
    array[right] = key;
    return right;
}

//前后指针法
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

    //当递归过深时，采用直接插入
    if((right - left) <= 5)
    InsertSort(array,right-left+1);
    
    //具体采用的方法
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
