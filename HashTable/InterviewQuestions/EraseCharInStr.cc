#include<iostream>
#include<vector>
using namespace std;

void EraseChar(char *src,const char *dst)
{

    vector<bool> hashtable;
    hashtable.resize(256,false);

    //将dst中出现的字符保存在类似哈希表的结构，提高查找效率
    while(*dst != '\0')
    {
        
        int index;
        if(*dst >= 0)
        {
            index = *dst;
        }
        else
        {
            index = *dst + 256;    
        }
        //出现过的字符置为true
        hashtable[index] = true;
        ++dst;
    }
    
    //定义两个指针，快的一直走，慢的只有的当该字符串不需要删除时才往前走
    char *Fast = src;
    char *Slow = src;
    while(*Fast != '\0')
    {
        int index;
        if(*Fast >= 0)
        {
            index = *Fast;
        }
        else
        {
            index = *Fast + 256;
        }

        //该字符串不需要删除
        if(!hashtable[index])
            *Slow++ = *Fast;
        
        ++Fast;
    }
    *Slow = '\0';
}

int main()
{
    char str1[] = "Thay are student";
    char str2[] = "Tt";
    EraseChar(str1,str2);
    puts(str1);
    return 0;
}
