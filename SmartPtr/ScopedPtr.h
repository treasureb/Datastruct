#pragma once

#include<iostream>

template <class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
	:_ptr(ptr)
	{}

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
	
	ScopedPtr<T>& operator=(const ScopedPtr<T>&);
	ScopedPtr(ScopedPtr<T>&);//��ֹ�����û��Լ�����ʧ�ܺ���
private:
	T* _ptr;
};

void TestScopedPtr()
{
	//ScopedPtr<int> sp1(new int(10));
	//ScopedPtr<int> sp2(sp1);

}