#pragma once
#include<iostream>
using namespace std;


struct AA
{
	int a1;;
	int a2;
};

template <class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}

	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}

		return *this;
	}
	
		~AutoPtr()
	{
		if (_ptr)
		{
            cout<<"delete ptr"<<&_ptr<<endl;
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};


void Test()
{
    int* p1 = new int(10);
   // *p1 = 100;
   // cout << *p1 << " "<<endl;
   // 
   // AutoPtr<int> ap1(new int(20));
   // *ap1 = 200;
   // cout << *ap1 << " "<<endl;
   // 
   // 
   // AA* p2 = new AA();//定义AA时后面加了()则初始化为0，否则为随机数
   // cout << p2->a1 << " ";
   // cout << p2->a2 <<" ";
   // 
   // p2->a1 = 10;
   // (*p2).a2 = 10;
   // 
   // AutoPtr<AA> ap2(new AA());
   // (*ap2).a1 = 10;
   // (ap2.operator*()).a1 = 100;
   // 
   // ap2->a2 = 10;//ap2->->a2编译器优化成ap2->a2
   // (ap2.operator->())->a2 = 100;
	

	AutoPtr<int> ap3(new int());
	AutoPtr<int> ap4(ap3);//两个对象指向同一个空间，会被析构两次

	AutoPtr<int> ap5(ap3);
	(*ap3) = 10;//因为ap1指针现在悬空，所以给空指针赋一个常量会崩溃

	//AutoPtr<int> ap6(new int(10));
	//ap3 = ap4;

}
