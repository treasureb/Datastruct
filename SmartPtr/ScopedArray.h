#pragma once

#include<iostream>

using namespace std;

template <class T>
class ScopedArray
{
public:
	ScopedArray(T* ptr)
	:_ptr(ptr)
	{}

	~ScopedArray()
	{
		if (_ptr)
		{
			printf("ScopedArrardelete[]: 0x%p\n", _ptr);
			delete[] _ptr;
		}

	}

	T& operator[](size_t pos)
	{
		return _ptr[pos];
	}
private:
	ScopedArray(ScopedArray<T>&);
	ScopedArray<T>& operator=(const ScopedArray<T>);
private:
	T* _ptr;
};

struct BB
{
	int a1;
	int a2;
};

void TestScopedArray()
{
	ScopedArray<int> sp1(new int[10]);
	sp1[3] = 10;
    cout<<sp1[3]<<endl;

	ScopedArray<BB> sp2(new BB[10]);
	sp2[5].a1 = 10;
	sp2[5].a2 = 20;
	cout << sp2[5].a1 <<endl;
	cout << sp2[5].a2 <<endl;
}
