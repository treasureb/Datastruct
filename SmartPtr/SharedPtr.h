#pragma once

#include<iostream>
template<class T>
class WeakPtr;

template <class T>
class SharedPtr
{
	friend class WeakPtr<T>;
public:
	SharedPtr(T* ptr = NULL)//给出缺省的构造函数
		:_ptr(ptr)
		, _refCount(new int(1))
	{}

	void Release()
	{
		if (--(*_refCount) == 0)
		{	
			printf("SharedPtrdelete:0x:%p\n", _ptr);
			delete _ptr;		
			delete _refCount;
			_ptr = NULL;
			_refCount = NULL;
		}
	}

	~SharedPtr()
	{
		Release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _refCount(sp._refCount)
	{
		++(*_refCount);
	}

	SharedPtr<T>& operator=(SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{		
			Release();
			_ptr = sp._ptr;
			_refCount = sp._refCount;
			++(*_refCount);
		}
		return *this;
	}


	int Count()
	{
		return *(_refCount);
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
	int* _refCount;
};

//void TestSharedPtr()
//{
//	SharedPtr<int> sp1(new int(10));
//	SharedPtr<int> sp2(sp1);
//	SharedPtr<int> sp3(sp1);
//	//SharedPtr<int> sp4(sp1);
//
//	/*if (1)
//	{
//		SharedPtr<int> sp5(sp4);
//	}
//	*sp1 = 1;
//*/
//	SharedPtr<int> sp4(new int(20));
//	SharedPtr<int> sp5(new int(30));
//	sp1 = sp4;
//	sp5 = sp4;
//	std::cout << sp1.Count() << " ";
//    std::cout << sp4.Count() << " ";
//}

template <class T>
class WeakPtr
{
public:
	WeakPtr()
		:_ptr(NULL)
	{}

	WeakPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
	{}

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

struct ListNode
{
	WeakPtr<ListNode> _prev;
	WeakPtr<ListNode> _next;
};

void TestCycleRef()
{
	SharedPtr<ListNode> cur = new ListNode;
	SharedPtr<ListNode> next = new ListNode;
	
	cur->_next = next;// 没有默认的构造函数可以调用
	next->_next = cur;
}


