#pragma once

#include<iostream>

template <class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
	:_ptr(ptr)
	{}

    //c++11 中可以采用delete关键字来拒绝拷贝
    ScopedPtr(ScopedPtr<T>& sp) = delete;
    ScopedPtr<T> operator=(ScopedPtr<T> sp) = delete;

	~ScopedPtr()
	{
		printf("ScopedPtrdelete:0x%p", _ptr);
		delete _ptr;
	}
	
	ScopedPtr& operator*()
	{
		return *_ptr;
	}

	ScopedPtr* operator->()
	{
		return _ptr;
	}
	
private:
	
	//ScopedPtr<T>& operator=(const ScopedPtr<T>&);
	//ScopedPtr(ScopedPtr<T>&);//防止链接用户自己链接失败后定义
private:
	T* _ptr;
};

void TestScopedPtr()
{
    //编译时直接报错
	ScopedPtr<int> sp1(new int(10));
	ScopedPtr<int> sp2(sp1);

}
