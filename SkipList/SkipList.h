#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>

using namespace std;
#define MAXLEVE 8

template<typename K,typename V>
struct SkipNode
{
    K _key;
    V _value;
    size_t _size;                   //表示该节点的层数
    vector<SkipNode<K,V>*> _pleve;  //存放每一层的指针

    SkipNode(K key=K(),V value=V(),size_t size=size_t())
    :_key(key)
     ,_value(value)
     ,_size(size)
    {
        _pleve.resize(0);
        for(size_t i = 0;i < size;i++){
            _pleve.push_back(NULL);
        }
    }

    ~SkipNode()
    {
        _key = -1;
        _value = -1;
        _size = -1;
        _pleve.clear();
    }
};

template<typename K,typename V>
class SkipList
{
public:
    typedef SkipNode<K,V> Node;
    SkipList();
    void Insert(K key,V value);
    bool Find(K key,V& value);
    bool Erase(K key);
    void Print();
    int GetLeve();
    size_t Size();
    ~SkipList();
private:
    int Random();
protected:
    SkipList(SkipList<K,V> &);
    SkipList<K,V>& operator=(SkipList<K,V>);
private:
    Node* _head;
    int _maxLeve;
    int _size;
};
#endif
