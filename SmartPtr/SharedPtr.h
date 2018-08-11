#pragma once

#include<iostream>

using namespace std;

class Counter{
public:
    Counter()
        :s(0)
         ,w(0)
    {}

    int s;  //shared_ptr中引用计数
    int w;  //weak_ptr中引用计数
};

template<class T>
class WeakPtr;

template <class T>
class SharedPtr
{
	friend class WeakPtr<T>;
public:
	SharedPtr(T* ptr = NULL)//给出缺省的构造函数
		:ptr_(ptr)
    {
        cnt_ = new Counter();
        if(ptr)
            cnt_->s = 1;

        cout<<" in construct "<<cnt_->s<<endl;
    }

	~SharedPtr()
	{
		release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		:ptr_(sp.ptr_)
		,cnt_(sp.cnt_)
	{
        cnt_->s++;
        cout<<" in copy construct "<<cnt_->s<<endl; 
	}

    SharedPtr(const WeakPtr<T>& wp){
        ptr_ = wp.ptr_;
        cnt_ = wp._cnt;
        cnt_->w++;

        cout<<" in copy weak construct "<<cnt_->w<<endl;
    }

	SharedPtr<T>& operator=(SharedPtr<T>& sp)
	{
		if (*this != &sp)
		{		
			release();
			ptr_ = sp._ptr;
			cnt_ = sp.cnt_;
			cnt_->s++;
		}
        cout<<" assign construct "<<cnt_->s<<endl;
		return *this;
	}


	int Count()
	{
		return cnt_->s;
	}
	T& operator*()
	{
		return *ptr_;
	}

	T* operator->()
	{
		return ptr_;
	}
private:
	void release()
	{
		if (--(cnt_->s) < 1)
		{	
            cout<<" release "<<cnt_->s<<endl;
			delete ptr_;		
            if(cnt_->w < 1){
                delete cnt_;
                cnt_ = nullptr;
            }
		}
	}

	T* ptr_;
	Counter* cnt_;
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
    friend class SharedPtr<T>;

	WeakPtr()
		:ptr_(nullptr)
         ,cnt_(nullptr)
	{}

	WeakPtr(const SharedPtr<T>& sp)
		:ptr_(sp.ptr_)
         ,cnt_(sp.cnt_)
    {
        cnt_->w++;
        cout<<" weak_ptr construct "<<endl;
    }

    WeakPtr(const WeakPtr<T>& wp)
        :ptr_(wp.ptr_)
         ,cnt_(wp.cnt_)
    {
        cnt_->w++;
    }

    ~WeakPtr(){
        release();
    }

    WeakPtr<T>& operator=(const WeakPtr<T>& wp){
        if(*this != &wp){
            release();
            ptr_ = wp.ptr_;
            cnt_ = wp.cnt_;
            cnt_->w++;
        }
        return *this;
    }

    WeakPtr<T>& operator=(SharedPtr<T>& sp){
        cout<<" w = s"<<endl;
        release();
        cnt_ = sp.cnt_;
        ptr_ = sp.ptr_;
        return *this;
    }

    SharedPtr<T> lock(){
        return SharedPtr<T>(*this);
    }

    bool expired(){
        if(cnt_){
            if(cnt_->s > 0){
                cout<<" empty "<<cnt_->s<<endl;
                return false;
            }
        }
        return true;
    }

	T& operator*()
	{
		return *ptr_;
	}

	T* operator->()
	{
		return ptr_;
	}

private:

    void release(){
        if(cnt_){
            cnt_->w--;
            cout<<" weak_ptr release "<<cnt_->w<<endl;
            if(cnt_->w < 1 && cnt_->s < 1){
                delete cnt_;
                cnt_ = nullptr;
            }
        }
    }

	T* ptr_;
    Counter* cnt_;
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


