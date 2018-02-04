#ifndef _STRING_H_
#define _STRING_H_

#include<string.h>
#include<iostream>
#include<utility>
/*
 * string类的浅拷贝
 */

/*
class String
{
public:
    String()
        :_str(new char[1])
    {
        *_str = '\0';
    }

    String(const char* str)
        :_str(new char[strlen(str)+1])
    {
        strcpy(_str,str);
    }

    String(const String& str)
        :_str(str._str)
    {}

    String& operator=(const String& str)
    {
        if(this != &str)
        {
            _str = str._str;
        }
        return *this;
    }

    ~String()
    {
        printf("~String\n");
        if(_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
//private:
    char* _str;
};
*/

/* Sting类的深拷贝实现
class String
{
public:
    String()
        :_str(new char[1])
    {
        *_str = '\0';
    }

    String(const char* str)
        :_str(new char[strlen(str)+1])
    {
        strcpy(_str,str);
    }

    String(const String& rhs)
        :_str(new char[rhs.Size()+1])
    {
        strcpy(_str,rhs.C_Str());
    }

    ~String()
    {
        delete[] _str;
    }
    
    // 最传统的写法
    String& operator=(const String& rhs)
    {
        if(this != &rhs)
        {
            char* tmp = new char[rhs.Size()+1];
            delete[] _str;
            strcpy(tmp,rhs.C_Str());
            _str = tmp;
        }
        return *this;
    }
    

    //传统的现代写法
    String& operator=(const String& rhs)
    {
        String tmp(rhs);
        Swap(tmp);
        return *this;
    }
    

    
    //采用pass-by-value
    String& operator=(String rhs)
    {
        Swap(rhs);
        return *this;
    }
    

    //Accessors
    
    size_t Size()const
    {
        return strlen(_str);
    }

    const char* C_Str()const
    {
        return _str;
    }

    void Swap(String& rhs)
    {
        std::swap(_str,rhs._str);
    }

    char& operator[](size_t index)
    {
        return _str[index];
    }
    
    friend std::ostream& operator<<(std::ostream& out,const String& rhs);
    friend std::istream& operator>>(std::istream& in,const String& rhs);
    friend String operator+(const String& str1,const String& str2);
    friend String operator+=(String& str1,const String& str2);
    friend bool operator ==(const String& str1,const String& str2);
    friend bool operator !=(const String& str1,const String& str2);
private:
    char* _str;   
};


std::ostream& operator<<(std::ostream& out,const String& rhs)
{
    out << rhs._str;
    return out;
}

std::istream& operator>>(std::istream& in,const String& rhs)
{
    in >> rhs._str; 
    return in;
}

String operator+(const String& str1,const String& str2)
{
    String tmp;
    delete[] tmp._str;
    size_t new_length = str1.Size()+str2.Size();
    tmp._str = new char[new_length+1];
    strcpy(tmp._str,str1._str);
    strcat(tmp._str,str2._str);
    return tmp;
}

String operator+=(String& str1,const String& str2)
{
    str1 = str1 + str2;
    return str1;
}

bool operator==(const String& str1,const String& str2)
{
    return strcmp(str1._str,str2._str);
}

bool operator!=(const String& str1,const String& str2)
{
    return !(strcmp(str1._str,str2._str));
}

*/

//1.0写实拷贝
/*
class String
{
public:
    String()
        :_str(new char[1])
        ,_count(new int(1))
    {
        *_str = '\0';
    }

    String(const char* str)
        :_str(new char[strlen(str)+1])
         ,_count(new int(1))
    {
        strcpy(_str,str);
    }

    ~String()
    {
        if(--(*_count) == 0)
        {
            delete[] _str;
            delete _count;
            _str = nullptr;
            _count = nullptr;
        }
    }

    String(const String& rhs)
        :_str(rhs._str)
         ,_count(rhs._count)
    {
        (*_count)++;
    }

    String& operator=(const String& rhs)
    {
        if(this != &rhs)
        {
            if(--(*_count) == 0)
            {
                delete[] _str;
                delete _count;
            }
            _str = rhs._str;
            _count = rhs._count;
            (*_count)++;
        }
        return *this;
    }

    char& operator[](size_t index)
    {
        if(*_count > 1)
        {
            char* tmp = new char[strlen(_str)+1];
            strcpy(tmp,_str);
            _str = tmp;
            (*_count)--;
            _count = new int(1);
        }
        return *(_str+index);
    }

    char* C_Str()
    {
        return _str;
    }
    friend std::ostream& operator<<(std::ostream& out,const String& rhs);
private:
    char* _str;
    int*  _count;
};
std::ostream& operator<<(std::ostream& out,const String& rhs)
{
    out<<rhs._str;
    return out;
}

*/

class String
{
public:
    String()
        :_str(new char[8+1])
    {
        _str = _str+8;
        *_str = '\0';
        int count = Count(_str);
        count = 1;
    }

    String(char* str)
        :_str(new char[strlen(str)+8+1])
    {
        _str = _str+8;
        strcpy(_str,str);
    }

    String(const String& rhs)
        :_str(rhs._str)
    {
        ++Count(_str);
    }

    String& operator=(const String& rhs)
    {
        if(--Count(_str) == 0)
        {
            delete[] (_str+8);
            _str = nullptr;
        }
        _str = rhs._str;
        ++Count(_str);
        return *this;
    }

    ~String()
    {
        if(--(Count(_str)) == 0)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
    
    char& operator[](size_t index)
    {
        if(Count(_str) > 1)
        {
            String tmp(_str); 
            Count(_str)--;
            Count(tmp._str) = 1;
        }
        return *(_str+8+index);
    }

    int& Count(char* str)
    {
        return *(int*)(str-8);
    }

    char* C_Str()
    {
        return _str;
    }
    friend std::ostream& operator<<(std::ostream& out,const String& rhs);
private:
    char* _str;
};


std::ostream& operator<<(std::ostream& out,const String& rhs)
{
    out<<rhs._str;
    return out;
}

#endif
