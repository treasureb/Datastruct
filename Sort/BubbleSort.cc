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

    int last_swap = 0;
    bool flag = true;
    int sortBorder = len-1;
    for(int i = 0;i < len;++i){
        for(int j = 0;j < sortBorder;++j){
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
                flag = false;
                last_swap = j;
            }
        }
        sortBorder = last_swap;
        if(flag)
            break;
    }
}

void cocktail_sort(int* array,int len){
    assert(array);
    int begin = 0;
    int end = len - 1;
    int sortBorder = 0;
    bool Swap = true;
    while(Swap){
        Swap = false;
        //最大的数放在最后一位
        for(int i = begin;i < end;++i){
            if(array[i] > array[i+1]){
                swap(array[i],array[i+1]);
                Swap = true;
                sortBorder = i;
            }
        }

        end = sortBorder;
        for(int j = end;j > begin;--j){
            if(array[j] < array[j-1]){
                swap(array[j],array[j-1]);
                Swap = true;
                sortBorder = j;
            }
        }
        begin = sortBorder;
    }
}

int main(){
    int array[10] = {2,5,3,7,8,1,6,0,4,9};
    cocktail_sort(array,sizeof(array)/sizeof(array[0]));
    for(int i = 0;i < 10;++i){
        printf("%d ",array[i]);
    }
    return 0;
}
