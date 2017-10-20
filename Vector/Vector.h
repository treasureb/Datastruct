#pragma once
#pragma warning(disable:4996)

#include<memory.h>
#include<iostream>
using namespace std;

template <class T>
class Vector
{
public:
	Vector()//构造函数
		:_pData(NULL)
		, _capacity(0)
		, _size(0)
	{}

	Vector(const Vector& v)//拷贝构造函数
		: _pData(new T[v._capacity])
		,_capacity(v._capacity)
		, _size(v._size)
	{
		memcpy(_pData, v._pData, sizeof(T)*_size);
	}
	~Vector()//析构函数
	{
		if (_pData)
		{
			delete[] _pData;
			cout << "~Vector" << endl;
		}
	}
	Vector& operator=(const Vector& v)
	{
		if (this != &v)//防止自复制
		{
			delete[] _pData;
			_pData = new T[v._capacity];
			memcpy(_pData, v._pData, v._size*sizeof(T));
			_size = v._size;
			_capacity = v._capacity;
		}
		return *this;
	}


	void PushBack(const T& data)//尾插
	{
		CheckCapacity();
		_pData[_size++] = data;
	}
	void PopBack()//尾删
	{
		if (_size == 0)
		{
			cout << "Vector Is Empty!\n" << endl;
		}
		_size--;
	}
	void Insert(size_t pos, const T& data)//插入
	{
		CheckCapacity();
		if (pos > _size)
		{
			cout << "Error pos!\n" << endl;
			return;
		}
		for (int index = _size - 1; index >= (int)pos; index--)//如果i为无符号类型，则永远不会<0,故会形成死循环
		{
			_pData[index + 1] = _pData[index];
		}
		_pData[pos] = data;
		_size++;

	}
	size_t Find(const T& data)const//查找值为data的位置
	{
		for (size_t index = 0; index < _size-1; index++)
		{
			if (_pData[index] == data)
			{
				return index;
			}
		}
	}
	size_t Size()const//求size大小
	{
		return _size;
	}
	void ReSize(size_t size, const T& data = T())//重新指定有效元素的个数
	{
		if (_size == size)
		{
			return;
		}
		else if (_size > size)
		{
			_size = size;
		}
		else
		{
			T* temp = (T*)malloc(size*sizeof(T));
			//memset();

		
		}

	}
	size_t Capacity()const//Capacity的大小
	{
		return _capacity;
	}
	void PrintfVector()//打印Vector
	{
		for (size_t index = 0; index < _size; index++)
		{
			cout << _pData[index] << " ";
		}
		cout << "" << endl;
	}
	bool Empty()const//判空
	{
		return 0 == _size;
	}
		T& Front()//返回第一个位置上的数值
	{
		return _pData[0];
	}
		const T& Back()const//返回最后一个位置上的数值
		{
			return _pData[_size - 1];
		}

	//[]操作符的重载：
		T& operator[](size_t index)
	{
		if (index > _size)
		{
			cout << "Error Index!\n" << endl;
		}
		return _pData[index];
	}
	const T& operator[](size_t index)const
	{
		if (index > _size)
		{
			cout << "Error Index!\n" << endl;
		}
		return _pData[index];
	}
	T& At(size_t index)
	{
		if (index > _size)
		{
			cout << "Error Index!\n" << endl;
		}
		return _pData[index];
	}
	const T& At(size_t index)const
	{
		if (index > _size)
		{
			cout << "Error Index!\n" << endl;
		}
		return _pData[index];
	}
private:
	void CheckCapacity()//检查Capacity，若空间不足，则进行扩容
	{
		if (_size == _capacity)
		{
			_capacity = _capacity * 2 + 3;//因为在构造时，capacity为0，所以后面加3
			T* temp = (T*)malloc(_capacity*sizeof(T));
			memcpy(temp, _pData, _size*sizeof(T));
			delete[] _pData;
			_pData = temp;
		}
	}
	friend ostream& operator<<(ostream& _cout, const Vector&v);
	
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};

ostream& operator<<(ostream& _cout, const Vector&v)
{
	for (size_t index = 0; index < v._size; index++)
	{
		cout << v._pData[index] << endl;
	}
	cout << "ostream!" << endl;
	return _cout;
}



