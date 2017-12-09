#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template <class T>
class ArrayStack
{
public:
	ArrayStack()
		:_array1(new T)
		, _size1(0)
		, _size2(0)
		, _capacity(1)
		, _size(_capacity - 1)
	{
		assert(_array1);
		_array2 = &_array1[_capacity - 1];
	}

	~ArrayStack()
	{
		if (!_array1)
		{
			delete[] _array1;
			_size1 = 0;
			_size2 = 0;
			_capacity = 0;
			_size = 0;
 		}
	}

	ArrayStack(ArrayStack<T>& arr)
		:_size1(arr._size1)
		, _capacity(_capacity)
		, _size2(arr._size2)
		, _size(arr._size)
	{		
		_array1 = new T[_capacity];
		for (int i = 0; i < _capacity; i++)
		{
			_array1[1] = arr._array1[i];
		}
	}

	ArrayStack<T>& operator=(ArrayStack<T> arr)
	{
		swap(_array1, arr._array1);
		swap(_array2, arr._array2);

		swap(_size1, arr._size1);
		swap(_size2, arr._size2);

		swap(_capacity, arr._capacity);
		return *this;
	}

	void Arr1_Push_Back(T value)
	{
		Check_Cap();
		_array1[_size1] = value;
		_size1++;
	}

	void Arr2_Push_Back(T value)
	{
		Check_Cap();
		_array1[_capacity - _size2 - 1] = value;
		_size2++;
	}

	void Arr1_Pop_Back()
	{
		assert(_size1 > 0);
		_size1--;
	}

	void Arr2_Pop_Back()
	{
		assert(_size2 > 0);
		_size2--;
	}

	void Arr_DisPlay()
	{
		for (int i = 0; i < _capacity; i++)
		{
			cout << _array1[i] << " ";
		}
		cout << endl;
	}

	void Arr1_DisPlay()
	{
		for (int i = 0; i < _size1; i++)
		{
			cout << _array1[i] << " ";
		}
		cout << endl;
	}

	void Arr2_DisPlay()
	{
		for (int j = _capacity - 1; j > _capacity - _size2 - 1; j--)
		{
			cout << _array1[j] << " ";
		}
		cout << endl;
	}
private:
	void Check_Cap()
	{
		if (&_array1[_size] == &_array1[_capacity - _size2 - 1])
		{
			int t_capacity = _capacity * 2 + 1;
			int t = t_capacity;
			int s = _size2;
			T* tmp = new T[t_capacity];
			for (int i = 0; i < _size1; i++)
			{
				tmp[i] = _array1[i];
			}
			while (s--)
			{
				tmp[t - 1] = _array1[_capacity - 1];
				t--;
				_capacity--;
			}
			delete[] _array1;
			_array1 = tmp;
			_capacity = t_capacity;
			_size = _capacity - 1;
			_array2 = &_array1[_capacity - 1];
		}
	}
protected:
	T* _array1;
	T* _array2;
	int _size1;
	int _size2;
	int _capacity;
	int _size;
};
int main()
{
	ArrayStack<int> as;
	as.Arr1_Push_Back(1);
	as.Arr1_Push_Back(2);

	as.Arr2_Push_Back(6);
	as.Arr_DisPlay();
	as.Arr1_DisPlay();
	as.Arr2_DisPlay();
	system("pause");
	return 0;
}