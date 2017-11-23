#ifndef __RADIXSORT__
#define __RADIXSORT__

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

int GetMaxBit(int* array,int size)
{
    assert(array);
    int base = 10;
    int digits = 1;
    for(int i = 0;i < size;++i)
    {
        while(array[i] >= base)
        {
            ++digits;
            base *= 10;
        }
    }

    return digits;
}

void RadixSort(int* array,int size)
{
    assert(array);
    int* buckets = new int[size];
    int base = 1;
    int maxbit = GetMaxBit(array,size);
    for(int i = 0;i < maxbit; ++i)
    {
        //统计0~9号桶中的个数
        int counts[10] = {0};
        for(int i = 0;i < size;++i)
        {
            int num = (array[i]/base)%10;
            counts[num]++;
        }

        int start[10] = {0};
        //计算定位数组
        for(int i = 1;i < 10;++i)
        {
           start[i] =  start[i-1] + counts[i - 1];
        }

        //往桶里扔
        for(int i = 0;i < size;++i)
        {
            int num = (array[i]/base)%10;
            int& pos = start[num];
            buckets[pos] = array[i];
            ++pos;
        }

        memcpy(array,buckets,sizeof(int)*size);
        base *= 10;
        delete[] buckets;
    }
}

void Print(int* array,int size)
{
    assert(array);
    for(int i = 0;i < size;++i)
    {
        cout<<array[i] << " ";
    }
    cout<< endl;
}

void TestRadixSort()
{
    int array[] = {4,4,12,14,35,3,3,3,7,7,7,9,9,9,9,53,98};
    RadixSort(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}
#endif
