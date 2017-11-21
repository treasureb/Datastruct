#ifndef __COUNTSORT__
#define __COUNTSORT__

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

void CountSort(int* array,int size)
{
    assert(array);
    size_t max = array[0];
    size_t min = array[0];
    for(size_t i = 0; i< size;++i)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        if(array[i] < min)
        {
            min = array[i];
        }
    }
    
    size_t range = max -min + 1;
    size_t* count = new size_t[range];
    memset(count,0,sizeof(size_t)*range);

    for(size_t i = 0;i < size;++i)
    {
        count[array[i]-min]++;
    }
    size_t index = 0;
    for(size_t i = 0;i < range;++i)
    {
        while(count[i]--)
        {
            array[index++] = i + min;
        }
    }
    delete[] count;
}

void Print(int* array,size_t size)
{
    for(int i = 0;i < size;++i)
    {
        cout<<array[i] << " ";
    }
    cout<<endl;
}

void TestCountSort()
{
    int array[] = {1,2,3,4,5,6,7,6,6,7,2,2,0,9,8,5};
    CountSort(array,sizeof(array)/sizeof(array[0]));
    Print(array,sizeof(array)/sizeof(array[0]));
}

#endif
