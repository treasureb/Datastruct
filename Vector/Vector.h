#pragma once
#pragma warning(disable:4996)

#include<memory.h>
#include<iostream>
using namespace std;

template <class T>
class Vector
{
public:
	Vector()//���캯��
		:_pData(NULL)
		, _capacity(0)
		, _size(0)
	{}

	Vector(const Vector& v)//�������캯��
		: _pData(new T[v._capacity])
		,_capacity(v._capacity)
		, _size(v._size)
	{
		memcpy(_pData, v._pData, sizeof(T)*_size);
	}
	~Vector()//��������
	{
		if (_pData)
		{
			delete[] _pData;
			cout << "~Vector" << endl;
		}
	}
	Vector& operator=(const Vector& v)
	{
		if (this != &v)//��ֹ�Ը���
		{
			delete[] _pData;
			_pData = new T[v._capacity];
			memcpy(_pData, v._pData, v._size*sizeof(T));
			_size = v._size;
			_capacity = v._capacity;
		}
		return *this;
	}


	void PushBack(const T& data)//β��
	{
		CheckCapacity();
		_pData[_size++] = data;
	}
	void PopBack()//βɾ
	{
		if (_size == 0)
		{
			cout << "Vector Is Empty!\n" << endl;
		}
		_size--;
	}
	void Insert(size_t pos, const T& data)//����
	{
		CheckCapacity();
		if (pos > _size)
		{
			cout << "Error pos!\n" << endl;
			return;
		}
		for (int index = _size - 1; index >= (int)pos; index--)//���iΪ�޷������ͣ�����Զ����<0,�ʻ��γ���ѭ��
		{
			_pData[index + 1] = _pData[index];
		}
		_pData[pos] = data;
		_size++;

	}
	size_t Find(const T& data)const//����ֵΪdata��λ��
	{
		for (size_t index = 0; index < _size-1; index++)
		{
			if (_pData[index] == data)
			{
				return index;
			}
		}
	}
	size_t Size()const//��size��С
	{
		return _size;
	}
	void ReSize(size_t size, const T& data = T())//����ָ����ЧԪ�صĸ���
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
	size_t Capacity()const//Capacity�Ĵ�С
	{
		return _capacity;
	}
	void PrintfVector()//��ӡVector
	{
		for (size_t index = 0; index < _size; index++)
		{
			cout << _pData[index] << " ";
		}
		cout << "" << endl;
	}
	bool Empty()const//�п�
	{
		return 0 == _size;
	}
		T& Front()//���ص�һ��λ���ϵ���ֵ
	{
		return _pData[0];
	}
		const T& Back()const//�������һ��λ���ϵ���ֵ
		{
			return _pData[_size - 1];
		}

	//[]�����������أ�
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
	void CheckCapacity()//���Capacity�����ռ䲻�㣬���������
	{
		if (_size == _capacity)
		{
			_capacity = _capacity * 2 + 3;//��Ϊ�ڹ���ʱ��capacityΪ0�����Ժ����3
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



