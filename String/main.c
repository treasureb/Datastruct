#include"String.h"
using namespace std;

#if 1
void TestCOW()
{
    String s1("hello");
    String s2;
    s2 = s1;
    printf("进行写入前:\n");
    cout<<"s1 :"<<s1;
    printf("   地址:%p\n",s1.C_Str());
    cout<<"s2 :"<<s2;
    printf("   地址:%p\n",s2.C_Str());

    s2[0] = 'H';

    printf("进行写入后:\n");
    cout<<"s1 :"<<s1;
    printf("   地址:%p\n",s1.C_Str());
    cout<<"s2 :"<<s2;
    printf("   地址:%p\n",s2.C_Str());
}
#endif

int main()
{
#if 0
    String s1("hello");
    cout<<s1[2]<<endl;

    s1[2] = 'o';
    
    cout<<s1<<endl;

    String s2(s1);
    cout<<s2<<endl;

    String s3;
    s3 = s1 + s2;
    cout<<s3<<endl;
    
    s2 += s1;
    cout<<s2<<endl;

    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
    cout<<"s3:"<<s3<<endl;
    cout<<(s3 == s2)<<endl;
    cout<<(s2 != s3)<<endl;
#endif
#if 0
    String s1("hello");
    String s2;
    s2 = s1;
    printf("s1:%p\n",s1.C_Str());
    printf("s2:%p\n",s2.C_Str());
    s2[0] = 'H';
    cout<<s2<<endl;
    printf("s1:%p\n",s1.C_Str());
    printf("s2:%p\n",s2.C_Str());
#endif
#if 0   
    String s1("hello");
    String s2;
    s2 = s1;
#endif
    //TestCOW();
    TestCOW();
    return 0;
}
