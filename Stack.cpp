#include<iostream>
using namespace std;

template <class T>
class Stack
{
public:
		Stack(int buffSize = 0)
			:m_buffSize(buffSize)
			, m_onceAlloc(10)
			, m_nCount(0)
			, m_Data(NULL)
		{
			if (0 > m_buffSize)
			{
				cout << "Application for space allocation(the stack space is above zero) is invalid:buffSize = " << m_buffSize << ",now we use default constructor" << endl;
				m_buffSize = 0;

			}
			else
			{
				m_Data = new T[buffSize];
			}
	}

		~Stack()
		{
			if (m_Data != NULL)
			{
				delete m_Data;
				m_Data = NULL;
			}
		}

		bool DestroyStack()
		{
			delete this;
			return TRUE;
		}

		bool Clear()
		{
			if (m_Data != NULL)
			{
				delete[] m_Data;
				m_Data = NULL;
				m_buffSize = 0;
				m_nCount = 0;
				return TRUE;
			}
			cout << "The stack is already empty !" << endl;
		}

	bool isEmpty()
	{
		return 0 == m_nCount;
	}

	int GetLength()
	{
		return m_nCount;
	}

	const T GetTop()
	{
		return m_Data[m_nCount - 1];
	}

	bool Push(const T& elem)
	{
		if (m_nCount < m_buffSize)
		{
			m_Data[m_nCount++] = elem;
		}
		else
		{
			//重新分配空间
			T* m_TempData = new T[m_buffSize + m_onceAlloc];
			memcpy(m_TempData, m_Data, m_nCount*sizeof(T));
			m_buffSize = m_nCount + m_onceAlloc;
			m_TempData[m_nCount++] = elem;
			//释放原空间
			delete[] m_Data;
			m_Data = m_TempData;
		}
		return TRUE;
	}

	bool Pop()
	{
		if (m_nCount == 0)
			return;
		else if (--m_nCount == m_buffSize - m_onceAlloc)
		{
			m_buffSize -= m_onceAlloc;
			T* TempDate = new T[m_buffSize];
			memcpy(TempDate, m_Data, m_buffSize*sizeof(T));
			delete[] m_Data;
			m_Data = TempDate;
			m_Data = TempDate;
		}
		else
		{
			m_Data[m_nCount + 1] = 0;
		}
	}
private:
	T *m_Data;
	int m_buffSize;//栈的大小
	int m_nCount;//栈中元素个数
	const int m_onceAlloc;//一次分配的最大元素个数
};


int main()
{
	Stack<int> s(10);
	GetLength();
	return 0;
}