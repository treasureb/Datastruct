#pragma once

#include<iostream>

class Delete{
public:
    template<class T>
        void operator()(T* ptr)const {
            delete ptr;
        }
};

template <class T,class D = Delete>
class unique_ptr
{ 
public:

    explicit unique_ptr(T* ptr = nullptr,const D& dd = D()) 
    :ptr_(ptr)
     ,del_(dd)
    {}

    unique_ptr(const unique_ptr<T>& ptr) = delete;
    unique_ptr<T>& operator=(unique_ptr<T>& ptr) = delete; 

    ~unique_ptr() {
        del_(ptr_);
    }
    
    //可是使用右值引用来拷贝或者赋值一个即将被销毁的unique_ptr
    unique_ptr(unique_ptr&& right_value)
        :ptr_(right_value.ptr_)
         ,del_(std::move(right_value.del)){
             right_value.ptr_ = nullptr;
         }

    unique_ptr& operator=(unique_ptr&& right_value) noexcept{
        if(this != &right_value){
            std::cout<<"operator && right_value"<<std::endl;
            del_(*this);
            ptr_ = right_value.ptr_;
            del_ = std::move(right_value.del_);
            right_value.ptr_ = nullptr;
        }
        return *this;
    }

    //放弃对指针的控制权
    T* release(){
        T* tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }

    void reset(){
        del_(ptr_);
    }

    void reset(T* ptr){
        if(ptr_){
            del_(ptr_);
            ptr_ = ptr;
        }else{
            ptr_ = nullptr;
        }
    }

    void swap(unique_ptr& other) noexcept{
        using std::swap;
        swap(ptr_,other.ptr_);
        swap(del_,other.del_);
    }
    
    T* get(){
        return ptr_;
    }

    D& get_deleter(){
        return del_;
    }

    T& operator*(){
        return *ptr_;
    }

    T* operator->(){
        return ptr_;
    }
private:
    T* ptr_;
    D del_;
};

