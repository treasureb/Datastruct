#include<iostream>
#include<list>

using namespace std;

/* 测试splice函数的三种重载 */

/* splice函数是将两个list按照位置和区间进行合并的函数 */

void print_list(list<int> l){
    for( int c : l)
        cout<<c<<"->";
    cout<<endl;
}

int main(){
    list<int> mylist1,mylist2;
    list<int>::iterator it;

    for(int i = 1;i <= 4;++i)
        mylist1.push_back(i);

    for(int i = 1;i <= 3;++i)
        mylist2.push_back(i*10);

    it = mylist1.begin();
    ++it;


    /* 第一个参数为位置 */
    /* 第二个参数为待合并的链表 */

    mylist1.splice(it,mylist2);
    print_list(mylist1);
    //1 10 20 30 2 3 4

    //第三个参数为只转移此一个元素
    mylist2.splice(mylist2.begin(),mylist1,it);
    print_list(mylist2);

    it = mylist1.begin();

    /* 该函数会自动进行迭代器的类型萃取,从而对迭代器进行移动操作 */
    advance(it,3);

    /* 后两个参数表示要移动的区间 */ 
    mylist1.splice(mylist1.begin(),mylist1,it,mylist1.end());
    print_list(mylist1);


    return 0;
}
