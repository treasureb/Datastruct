#ifndef __BTREE__
#define __BTREE__

#include<iostream>
using namespace std;

template <class K,class V,size_t M>
struct BTreeNode
{
    pair<K,V> _kvs[M];
    BTreeNode<K,V,M>* _subs[M+1];
    BTreeNode<K,V,M>* _parent;
    size_t _size;

    BTreeNode()
         :_parent(NULL)
         ,_size(0)
    {
        for(size_t i = 0;i < M+1; ++i)
        {
            _subs[i] = NULL;
        }

    }

};

template <class K,class V,size_t M>
class BTree
{
    typedef BTreeNode<K,V,M> Node;
public:
    BTree()
        :_root(NULL)
    {}

    pair<Node*,int> Find(const K& key)
    {
        Node* parent = NULL;
        Node* cur = _root;
        while(cur)
        {
            size_t i = 0;
            while(i < cur->_size)
            {
                if(cur->_kvs[i].first > key)
                    break;
                else if(cur->_kvs[i].first < key)
                    ++i;
                else
                    return make_pair(cur,i);
            }
            parent = cur;
            cur = cur->_subs[i];
        }

        return make_pair(parent,-1);
    }

    bool Insert(const pair<K,V>& kv)
    {
        if(_root == NULL)
        {
            _root = new Node;
            _root->_kvs[0] = kv;
            _root->_size = 1;

            return true;
        }

        pair<Node*,int> ret = Find(kv.first);
        if(ret.second >= 0)
        {
            return false;
        }

        Node* cur = ret.first;
        pair<K,V> newKV = kv;
        Node* sub = NULL;

        //往cur插入newKV,sub
        while(1)
        {
            InsertKV(cur,newKV,sub);

            if(cur->_size < M)
            {
                return true;
            }
            else
            {
                //分裂
                Node* newNode = DivideNode(cur);

                pair<K,V> midKV = cur->_kvs[cur->_size >> 1];
                cur->_size -= (newNode->_size+1);

                //1、根节点分裂
                if(cur == _root)
                {
                    _root = new Node;
                    _root->_kvs[0] = midKV;
                    _root->_size = 1;
                    _root->_subs[0] = cur;
                    _root->_subs[1] = newNode;
                    cur->_parent = _root;
                    newNode->_parent = _root;
                    return true;
                }
                else
                {
                    sub = newNode;
                    newKV = midKV;
                    cur = cur->_parent;
                }

              }
         }
    }
    
    Node* DivideNode(Node* cur)
    {
        Node* newNode = new Node;
        int mid = cur->_size >> 1;

        size_t j = 0;
        size_t i = mid + 1;
        for(;i < cur->_size;++i)
        {
            newNode->_kvs[j] = cur->_kvs[i];
            newNode->_subs[j] = cur->_subs[i];
            if(newNode->_subs[j])
                newNode->_subs[j]->_parent = newNode;
            newNode->_size++;
            j++;
        }

        newNode->_subs[j] = cur->_subs[i];
        if(newNode->_subs[j])
            newNode->_subs[j]->_parent = newNode;

        return newNode;
    }

    void InsertKV(Node* cur,const pair<K,V>& kv,Node* sub)
    {
        int end = cur->_size-1;
        while(end >= 0)
        {
            if(cur->_kvs[end].first > kv.first)
            {
                cur->_kvs[end+1] = cur->_kvs[end];
                cur->_subs[end+2] = cur->_subs[end+1];
                --end;
            }
            else
            {
                break;
            }
        }

        cur->_kvs[end+1] = kv;
        cur->_subs[end+2] = sub;
        if(sub)
            sub->_parent = cur;

        cur->_size++;
    }

    void InOrder()
    {
        _InOrder(_root);
        cout<<endl;
    }

    void _InOrder(Node* _root)
    {
        if(_root == NULL)
            return;

        Node* cur = _root;
        size_t i = 0;
        for(; i < cur->_size;++i)
        {
            _InOrder(cur->_subs[i]);
            cout<<cur->_kvs[i].first<<" ";
        }

        _InOrder(cur->_subs[i]);
    }
private:
    Node* _root;
};

void TestBTree()
{
    BTree<int,int,3> t;
    int a[] = {53,75,139,49,145,36,101};
    for(size_t i = 0;i < sizeof(a)/sizeof(a[0]);++i)
    {
        t.Insert(make_pair(a[i],i));
    }
     t.InOrder();
}
#endif
