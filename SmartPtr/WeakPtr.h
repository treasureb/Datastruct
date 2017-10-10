//#pragma once
//
//#include"SharedPtr.h"
//
//template <class T>
//class WeakPtr
//{
//public:
//	WeakPtr()
//		:_ptr(NULL)
//	{}
//
//	WeakPtr(SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//	{}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
