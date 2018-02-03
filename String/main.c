#include"String.h"

int main()
{
    String s1("hello");
    String s2(s1);
    printf("s1 address:%p\n",s1._str);
    printf("s2 address:%p\n",s2._str);
    //String s3;
    //s3 = s1;
    return 0;
}
