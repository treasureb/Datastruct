#include"SkipList.h"

template<typename K,typename V>
size_t SkipList<K,V>::Size()
{
    return _size;
}

template<typename K,typename V>
int SkipList<K,V>::GetLeve()
{
    return _maxLeve;
}

template<typename K,typename V>
int SkipList<K,V>::Random()
{
    int leve = 1;
    while(rand()%2&&leve<=MAXLEVE)
    {
        leve++;
    }
    return leve;
}

template<typename K,typename V>
SkipList<K,V>::SkipList()
{
    _maxLeve = 1;
    _size = 0;
    _head = new Node(-1,-1,MAXLEVE);
}

template<typename K,typename V>
SkipList<K,V>::~SkipList()
{
    ;
}
template<typename K,typename V>
void SkipList<K,V>::Insert(K key,V value)
{
    int i = _maxLeve - 1;
    int j = 0;
    Node* cur = _head;
    Node* s[MAXLEVE];
    while(i >= 0){
        while(cur->_pleve[i]){
            if(key >= cur->_pleve[i]->_key){
                cur = cur->_pleve[i];
            }else
                break;
        }
        s[j++] = cur;
        i--;
    }

    i = 0;
    int leve = Random();
    _maxLeve<leve?_maxLeve = leve:_maxLeve;
    Node* newNode = new Node(key,value,leve);
    for(i = 0;i < leve;i++){
        if(i < j){
            newNode->_pleve[i] = s[j-i-1]->_pleve[i];
            s[j-i-1]->_pleve[i] = newNode;
        }else{
            _head->_pleve[i] = newNode;
        }
    }
    _size++;
}

template<typename K,typename V>
bool SkipList<K,V>::Find(K key,V& value)
{
    int i = _maxLeve - 1;
    Node* cur = _head;
    while(i >= 0){
        while(cur->_pleve[i]){
            if(key >= cur->_pleve[i]->_key){
                cur = cur->_pleve[i];
            }else
                break;
        }
        i--;
    }
    i = 0;
    if(cur->_key == key){
        value = cur->_value;
        return true;
    }
    return false;
}

template<typename K,typename V>
bool SkipList<K,V>::Erase(K key)
{
    int i = _maxLeve - 1;
    int j = 0;
    Node* cur = _head;
    Node* s[MAXLEVE];
    while(i >= 0){
        while(cur->_pleve[i]){
            if(key > cur->_pleve[i]->_key){
                cur = cur->_pleve[i];
            }else
                break;
        }
        s[j++] = cur;
        i--;
    }
    if(cur->_pleve[0]&&cur->_pleve[0]->key == key){
        cur = cur->_pleve[0];
        int leve = cur->_size;
        Node* del = nullptr;
        del = cur;
        for(i = 0;i < leve;i++){
            s[j-i-1]->_pleve[i] = cur->_pleve[i];
        }
        delete del;

        while(_maxLeve > 1){
            if(nullptr == _head->_pleve[_maxLeve-1])
                _maxLeve--;
            else
                break;
        }
        if(_size > 0)
            _size--;
    }
    return false;
}

template<typename K,typename V>
void SkipList<K,V>::Print()
{
    int i = _maxLeve-1;
    while(i >= 0){
        Node* cur = _head;
        printf("this is %d leve:\n",i+1);
        while(cur){
            cout<<cur->_key<<":"<<"["<<cur->_value<<"]"<<" ";
            cur = cur->_pleve[i];
        }
        i--;
        printf("\n");
    }
}

int main()
{
    SkipList<int,int> s;
    s.Insert(1,1);
    return 0;
}
