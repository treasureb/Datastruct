#ifndef __RADIXSORT__
#define __RADIXSORT__

#include<iostream>
#include<assert.h>
using namespace std;

int GetMaxBit(int* array,int size)
{
    assert(array);
    int base = 10;
    int digits = 1;
    for(int i =0;i<size;++i)
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
    int maxbit = GetMaxBit(array,size);
    for(int i = 0;i<maxbit ++i)
    {
        int counts[10] = 0;
        //统计0~9号桶中的个数
        for(int i =0;i<size;++i)
        {
            int num = array[i]%10;
            count[num] = array[i];
        }

        int start[10];
        start[0] = 0;
        //计算定位数组
        for(int i = 1;i < 10;++i)
        {
            start[i-1] = counts[i-1];
        }

        //往桶里扔
        for(int i =0;i<size;++i)
        {
            int num = array[i]%10;
            int& pos = start[num];
            counts[pos] = array[i];
        }

    }
}
#endif
