//#ifndef __BUBBLESORT__
//#define __BUBBLESORT__ 
//
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;
//
//void BubbleSort(int* array,int size)
//{
//    assert(array);
//    bool Flag = false;
//    for(int end = size-1;end>0;--end)
//    {
//        for(int i = 0;i < size-1;++i)
//        {
//            if(array[i] > array[i+1])
//             swap(array[i],array[i+1]);
//            Flag = true;
//        }   
//
//        if(!Flag)
//            break;
//    }
//}
//
//void Print(int* array,int size)
//{
//    for(int i = 0;i < size;++i)
//    {
//        cout<<array[i]<<" ";
//    }
//    cout<<endl;
//}
//
//void TestBubbleSort()
//{
//    int array[10] = {2,6,4,8,9,1,5,0,7,3};
//    BubbleSort(array,sizeof(array)/sizeof(array[0]));
//    Print(array,sizeof(array)/sizeof(array[0]));
//}
//#endif
//



void bubble_sort(int* array,int len){
    assert(array);

    bool flag = true;
    for(int i = 0;i < len;++i){
        for(int j = 0;j < len-i-1;++j){
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }
}

int main(){
    int array[10] = {2,5,3,7,8,1,6,0,4,9};
    bubble_sort(array,sizeof(array)/sizeof(array[0]));
    for(int i = 0;i < 10;++i){
        printf("%d ",array[i]);
    }
    return 0;
}
