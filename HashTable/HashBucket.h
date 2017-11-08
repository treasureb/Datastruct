#pragma once

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

//template <class K>
//struct _Function
//{
//	size_t operator()(const K& key)
//	{
//		return key;
//	}
//};
//
//template<>
//struct _Function<string>
//{
//	static size_t BKDRHash(const char*str)
//	{
//		unsigned int seed = 131;// 31 131 1313 13131 131313
//		unsigned int hash = 0;
//		while (*str)
//		{
//			hash = hash*seed + (*str++);
//		}
//		return(hash & 0x7FFFFFFF);
//	}
//	size_t operator ()(const string &key)
//	{
//		return BKDRHash(key.c_str());
//	}
//};
//
//static const int _PrimeSize = 28;
//static const unsigned long _PrimeList[_PrimeSize] =
//{
//	//素数表
//	53ul, 97ul, 193ul, 389ul, 769ul,
//	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//	49157ul, 98317ul, 196613ul, 393241ul,
//	786433ul,
//	1572869ul, 3145739ul, 6291469ul, 12582917ul,
//	25165843ul,
//	50331653ul, 100663319ul, 201326611ul, 402653189ul,
//	805306457ul,
//	1610612741ul, 3221225473ul, 4294967291ul
//};
//
//template <class K,class V>
//struct HashNode
//{
//	HashNode(const K& key, const V& value)
//	:_key(key)
//	, _value(value)
//	, _next(NULL)
//	{}
//
//	HashNode<K,V>* _next;
//	K              _key;
//	V              _value;
//};
//
//template <class K, class V,class _HashFunction = _Function<K>>
//class HashBucket
//{
//	typedef HashNode<K, V> Node;
//public:
//	HashBucket()
//	{}
//
//	HashBucket(size_t size)
//		:_size(0)
//	{
//		size_t newsize = GetPrimeList(size);
//			_table.resize(newsize);
//	}
//
//	pair<Node*, bool> Insert(const K& key, const V& value)
//	{
//		CheckCapacity();
//		//计算桶的位置
//		size_t index = HashFunction(key,_table.size());
//
//		//该桶还没有挂节点
//		if (_table[index] == NULL)
//		{
//			Node* newNode = new Node(key, value);
//			_table[index] = newNode;
//			++_size;
//
//			return make_pair(newNode, true);
//		}
//
//		Node* cur = _table[index];
//		Node* pre = NULL;
//		while (cur)
//		{
//			//如果待插入的节点已存在，则返回false
//			if (cur->_key == key)
//				return make_pair(cur, false);
//
//			pre = cur;
//			cur = cur->_next;
//		}
//		Node* newNode = new Node(key, value);
//		pre->_next = newNode;
//		_table[index] = pre;
//		++_size;
//
//		return make_pair(newNode, true);
//	}
//
//	bool Remove(const K& key)
//	{
//		size_t index = HashFunction(key,_table.size());
//
//		Node* cur = _table[index];
//		Node* pre = NULL;
//		while (cur)
//		{
//			if (cur->_key == key)
//			{
//				//如果前一个不存在，则是该桶唯一的节点
//				if (pre == NULL)
//					_table[index] = NULL;
//				else
//					pre->_next = cur->_next;
//
//				delete cur;
//				return true;
//			}
//
//			pre = cur;
//			cur = cur->_next;
//		}
//
//		return false;
//
//
//		//这里还可以采用替换法删除
//	}
//
//	size_t HashFunction(const K& key,size_t size)
//	{
//		_HashFunction hf;
//		return hf(key) % size;
//	}
//
//	void CheckCapacity()
//	{
//		if (_table.size() == 0)
//			_table.resize(_PrimeList[0]);
//
//		//考虑负载因子，因为是链式结构，所以让负载因子为1
//		if (_table.size() == _size)
//		{
//			HashBucket<K, V> NewHash(GetPrimeList(_table.size()));
//
//			for (size_t i = 0; i < _size; ++i)
//			{
//				Node* cur = _table[i];
//				while (cur)
//				{
//					size_t newindex = HashFunction(_table[i]->_key, GetPrimeList(_table.size()));
//					
//					//先保存之后的节点，在去新表中插入
//					Node* next = cur->_next;
//					
//					//头插
//					cur->_next = NewHash._table[newindex];
//					NewHash._table[newindex] = cur;
//					
//					cur = next;
//				}
//			}
//			_table.swap(NewHash._table);
//		}
//	}
//
//	Node* Find(const K& key)
//	{
//		size_t index = HashFunction(key，_table.size());
//
//		Node* cur = _table[index];
//		while (cur)
//		{
//			if (cur->_key == key)
//				return cur;
//
//			cur = cur->_next;
//		}
//
//		return NULL;
//	}
//
//protected:
//	size_t GetPrimeList(size_t size)
//	{
//		for (size_t i = 0; i < _PrimeSize; ++i)
//		{
//			if (_PrimeList[i] > size)
//			{
//				return _PrimeList[i];
//			}
//		}
//
//		//最大返回素数表中最后一个素数
//		return _PrimeList[_PrimeSize - 1];
//	}
//
//private:
//	vector<Node*> _table;
//	size_t _size;
//};


//template <class K>
//struct _Function
//{
//	size_t operator()(const K& key)
//	{
//		return key;
//	}
//};
//
//template<>
//struct _Function<string>
//{
//	static size_t BKDRHash(const char*str)
//	{
//		unsigned int seed = 131;// 31 131 1313 13131 131313
//		unsigned int hash = 0;
//		while (*str)
//		{
//			hash = hash*seed + (*str++);
//		}
//		return(hash & 0x7FFFFFFF);
//	}
//	size_t operator ()(const string &key)
//	{
//		return BKDRHash(key.c_str());
//	}
//};
//
//static const int _PrimeSize = 28;
//static const unsigned long _PrimeList[_PrimeSize] =
//{
//	//素数表
//	53ul, 97ul, 193ul, 389ul, 769ul,
//	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
//	49157ul, 98317ul, 196613ul, 393241ul,
//	786433ul,
//	1572869ul, 3145739ul, 6291469ul, 12582917ul,
//	25165843ul,
//	50331653ul, 100663319ul, 201326611ul, 402653189ul,
//	805306457ul,
//	1610612741ul, 3221225473ul, 4294967291ul
//};
//
//template <class K, class V>
//struct HashNode
//{
//	HashNode(const K& key = K(), const V& value = V())
//	:_key(key)
//	, _value(value)
//	, _next(NULL)
//	{}
//
//	HashNode<K, V>* _next;
//	K              _key;
//	V              _value;
//};
//template<class K, class V, class _HashFunction>
//class HashBucket;
//
//template<class K, class V, class _HashFunction>
//struct HashTableIterator
//{
//	typedef HashNode<K, V> Node;
//	typedef HashTableIterator<K, V,_HashFunction> Self;
//	typedef HashBucket<K,V,_HashFunction> HashBucket;
//
//	Node* _node;
//	HashBucket* _hash;
//	
//	HashTableIterator()
//	{}
//
//	HashTableIterator(Node* node,HashBucket* hash)
//		:_node(node)
//		, _hash(hash)
//	{}
//
//	K& operator*()
//	{
//		return _node->_key;
//	}
//
//	K* operator->()
//	{
//		return &(operator*());
//	}
//
//	bool operator==(const Self& it)const
//	{
//		return _node == it._node;
//	}
//
//	bool operator!=(const Self& it)const
//	{
//		return _node != it._node;
//	}
//
//	Self& operator++()
//	{
//		const Node* old = _node;
//		_node = _node->_next;
//		if (!_node)
//		{
//			size_t index = _hash->HashFunction(old->_key,_hash->_table.size());
//			while (!_node && ++index < _hash->_table.size())
//			{
//				_node = _hash->_table[index];
//			}
//		}
//		return *this;
//	}
//
//	Self operator++(int)
//	{
//		Self tmp = *this;
//		++(*this);
//		return tmp;
//	}
//};
//
//template <class K, class V, class _HashFunction = _Function<K>>
//class HashBucket
//{
//	friend HashTableIterator<K, V,_HashFunction>;
//	typedef HashNode<K, V> Node;
//public:
//	typedef HashTableIterator<K, V, _HashFunction> Iterator;
//	HashBucket()
//	{}
//
//	//要将哈希表下挂的节点都释放掉
//	~HashBucket()
//	{
//		Clear();
//	}
//	
//	HashBucket(size_t size)
//		:_size(0)
//	{
//		size_t newsize = GetPrimeList(size);
//		_table.resize(newsize);
//	}
//
//	//如何返回一个迭代器
//	Iterator Begin()
//	{
//		for (size_t i = 0; i < _table.size(); ++i)
//		{
//			if (_table[i])
//			{
//				return Iterator(_table[i], this);
//			}
//		}
//		return End();
//	}
//
//	Iterator& End()
//	{
//		return Iterator(0,this);
//	}
//
//	pair<Node*, bool> Insert(const K& key, const V& value)
//	{
//		CheckCapacity();
//		//计算桶的位置
//		size_t index = HashFunction(key, _table.size());
//
//		Node* cur = _table[index];
//		Node* newNode = new Node(key, value);
//		newNode->_next = cur;
//		_table[index] = newNode;
//		++_size;
//
//		return make_pair(newNode, true);
//	}
//
//	bool Remove(const K& key)
//	{
//		size_t index = HashFunction(key, _table.size());
//
//		Node* cur = _table[index];
//		Node* pre = NULL;
//		while (cur)
//		{
//			if (cur->_key == key)
//			{
//				//如果前一个不存在，则是该桶唯一的节点
//				if (pre == NULL)
//					_table[index] = NULL;
//				else
//					pre->_next = cur->_next;
//
//				delete cur;
//				return true;
//			}
//
//			pre = cur;
//			cur = cur->_next;
//		}
//
//		return false;
//
//
//		//这里还可以采用替换法删除
//	}
//
//	size_t HashFunction(const K& key, size_t size)
//	{
//		_HashFunction hf;
//		return hf(key) % size;
//	}
//
//	void CheckCapacity()
//	{
//		if (_table.size() == 0)
//			_table.resize(_PrimeList[0]);
//
//		//考虑负载因子，因为是链式结构，所以让负载因子为1
//		if (_table.size() == _size)
//		{
//			HashBucket<K, V> NewHash(GetPrimeList(_table.size()));
//
//			for (size_t i = 0; i < _size; ++i)
//			{
//				Node* cur = _table[i];
//				while (cur)
//				{
//					size_t newindex = HashFunction(_table[i]->_key, GetPrimeList(_table.size()));
//
//					//先保存之后的节点，在去新表中插入
//					Node* next = cur->_next;
//
//					//头插
//					cur->_next = NewHash._table[newindex];
//					NewHash._table[newindex] = cur;
//
//					cur = next;
//				}
//			}
//			_table.swap(NewHash._table);
//		}
//	}
//
//	Node* Find(const K& key)
//	{
//		size_t index = HashFunction(key，_table.size());
//
//		Node* cur = _table[index];
//		while (cur)
//		{
//			if (cur->_key == key)
//				return cur;
//
//			cur = cur->_next;
//		}
//
//		return NULL;
//	}
//
//	size_t Size()
//	{
//		return _size;
//	}
//
//protected:
//	size_t GetPrimeList(size_t size)
//	{
//		for (size_t i = 0; i < _PrimeSize; ++i)
//		{
//			if (_PrimeList[i] > size)
//			{
//				return _PrimeList[i];
//			}
//		}
//
//		//最大返回素数表中最后一个素数
//		return _PrimeList[_PrimeSize - 1];
//	}
//
//	void Clear()
//	{
//		for (size_t i = 0; i < _table.size(); ++i)
//		{
//			Node* cur = _table[i];
//			while (cur)
//			{
//				Node* next = cur->_next;
//				delete cur;
//				cur = next;
//			}
//			
//			//将桶的结点置空
//			_table[i] = NULL;
//		}
//		//将size置0
//		_size = 0;
//	}
//
//
//private:
//	vector<Node*> _table;
//	size_t _size;
//};

//void TestHashBucket()
//{
//	int arr[] = { 52, 3, 105, 46 ,64,23,87,12,8};
//	HashBucket<int, int> _hash;
//	_hash.Insert(54, 0);
//	_hash.Insert(107, 0);
//	/*for (int i = 0; i <100; ++i)
//	{
//		_hash.Insert(i, 0);
//	}*/
//	/*_hash.Insert("INsert", 0);
//	_hash.Insert("sdsd", 0);
//	_hash.Insert("Idfasfrt", 0);
//	_hash.Insert("Idasd", 0);
//	_hash.Insert("Isafft", 0);
//	_hash.Insert("Isdfgsdt", 0);
//	_hash.Insert("Isdgf", 0);
//	_hash.Insert("fdsft", 0);*/
//
//
//
//	HashBucket<int, int>::Iterator it = _hash.Begin();
//
//	while (it != _hash.End())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//}

template <class K,class V>
struct KeyOfValue
{
	const K& operator()(const V& value)
	{
		return value;
	}
};

template <class K,class V>
struct PairOfValue
{
	const K& operator()(const V& value)
	{
		return value.first;
	}
};

template <class K>
struct _Function
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>
struct _Function<string>
{
	static size_t BKDRHash(const char*str)
	{
		unsigned int seed = 131;// 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash*seed + (*str++);
		}
		return(hash & 0x7FFFFFFF);
	}
	size_t operator ()(const string &key)
	{
		return BKDRHash(key.c_str());
	}
};

static const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] =
{
	//素数表
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul,
	786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul,
	25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul,
	805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};

template <class ValueType>
struct HashNode
{
	HashNode(const ValueType& valuefield)
	/*:_key(key)
	, _value(value)*/
	:_ValueField(valuefield)
	, _next(NULL)
	{}

	HashNode<ValueType>* _next;
	ValueType       _ValueField;
	//K              _key;
	//V              _value;
};
template<class K, class V, class _HashFunction,class _KeyOfValue = KeyOfValue<K,V>>
class HashBucket;

template<class K, class V, class _HashFunction, class _KeyOfValue = KeyOfValue<K, V>>
struct HashTableIterator
{
	typedef HashNode<V> Node;
	typedef HashTableIterator<K, V, _HashFunction,_KeyOfValue> Self;
	typedef HashBucket<K, V, _HashFunction,_KeyOfValue> HashBucket;

	Node* _node;
	HashBucket* _hash;

	HashTableIterator(Node* node, HashBucket* hash)
		:_node(node)
		, _hash(hash)
	{}

	V& operator*()
	{
		return _node->_ValueField;
	}

	V* operator->()
	{
		return &(operator*());
	}

	bool operator==(const Self& it)const
	{
		return _node == it._node;
	}

	bool operator!=(const Self& it)const
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		const Node* old = _node;
		_node = _node->_next;
		if (!_node)
		{
			_KeyOfValue KeyOfValue;
			size_t index = _hash->HashFunction(KeyOfValue(old->_ValueField), _hash->_table.size());
			while (!_node && ++index < _hash->_table.size())
			{
				_node = _hash->_table[index];
			}
		}
		return *this;
	}

	Self operator++(int)
	{
		Self tmp = *this;
		++(*this);
		return tmp;
	}
};

template <class K, class V, class _HashFunction = _Function<K>, class _KeyOfValue = KeyOfValue<K, V>>
class HashBucket
{
	typedef V ValueType;
	typedef HashNode<V> Node;
	friend  struct HashTableIterator<K, V, _HashFunction, _KeyOfValue>;

public:
	typedef HashTableIterator<K, V, _HashFunction,_KeyOfValue> Iterator;
	HashBucket()
	{}

	//要将哈希表下挂的节点都释放掉
	~HashBucket()
	{
		Clear();
	}

	HashBucket(size_t size)
		:_size(0)
	{
		size_t newsize = GetPrimeList(size);
		_table.resize(newsize);
	}

	//如何返回一个迭代器
	Iterator Begin()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
			{
				return Iterator(_table[i], this);
			}
		}
		return End();
	}

	Iterator End()
	{
		return Iterator(0, this);
	}

	pair<Iterator, bool> Insert(const ValueType& valuefield)
	{
		CheckCapacity();
		//计算桶的位置
		_KeyOfValue KeyOfValue;
		size_t index = HashFunction(KeyOfValue(valuefield), _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (KeyOfValue(cur->_ValueField) == KeyOfValue(valuefield))
			{
				return make_pair(Iterator(cur, this), false);
			}

			cur = cur->_next;
		}

		Node* newNode = new Node(valuefield);
		newNode->_next = cur;
		_table[index] = newNode;
		++_size;

		return make_pair(Iterator(newNode,this), true);
	}

	Iterator Erase(Iterator Pos)
	{
		Iterator next = Pos;
		++next;

		_KeyOfValue KeyOfValue;
		size_t index = HashFunction(KeyOfValue(Pos._node->_ValueField), _table.size());

		Node* cur = _table[index];
		Node* pre = NULL;

		while (cur)
		{
			if (KeyOfValue(cur->_ValueField) == KeyOfValue(*Pos))
			{
				if (pre == NULL)
				{
					_table[index] = cur->_next;
				}
				else
				{
					pre->_next = cur->_next;
				}
				delete cur;

				return next;
			}
			else
			{
				pre = cur;
				cur = cur->_next;
			}
			assert(false);
		}
	}

	size_t Erase(const ValueType& valuefield)
	{
		_KeyOfValue KeyOfValue;
		size_t index = HashFunction(KeyOfValue(valuefield), _table.size());
		Node* cur = _table[index];
		if (cur && cur->_ValueField == valuefield)
		{
			_table[index] = cur->_next;
			delete cur;
			return 1;
		}

		Node* pre = NULL;
		while (cur)
		{
			if (cur->_ValueField == key)
			{
				//如果前一个不存在，则是该桶唯一的节点
				if (pre == NULL)
					_table[index] = NULL;
				else
					pre->_next = cur->_next;

				delete cur;
				return 1;
			}
				pre = cur;
				cur = cur->_next;
		}

		return 0;


		//这里还可以采用替换法删除
	}

	size_t HashFunction(const K& key, size_t size)
	{
		_HashFunction hf;
		return hf(key) % size;
	}

	void CheckCapacity()
	{
		if (_table.size() == 0)
			_table.resize(_PrimeList[0]);

		//考虑负载因子，因为是链式结构，所以让负载因子为1
		if (_table.size() == _size)
		{
			vector<Node*> Newtable;
			Newtable.resize(GetPrimeList(_table.size()), NULL);

			for (size_t i = 0; i < _size; ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					_KeyOfValue KeyOfValue;
					size_t newindex = HashFunction(KeyOfValue(_table[i]->_ValueField), GetPrimeList(_table.size()));

					//先保存之后的节点，在去新表中插入
					Node* next = cur->_next;

					//头插
					cur->_next = Newtable[newindex];
					Newtable[newindex] = cur;

					cur = next;
				}
			}
			_table.swap(Newtable);
		}
	}

	Iterator Find(const K& key)
	{
		size_t index = HashFunction(key,_table.size());

		Node* cur = _table[index];
		while (cur)
		{
			_KeyOfValue KeyOfValue;
			if (KeyOfValue(cur->_ValueField) == key)
				return Iterator(cur,this);

			cur = cur->_next;
		}

		return Iterator(NULL,this);
	}

	size_t Size()
	{
		return _size;
	}

protected:
	size_t GetPrimeList(size_t size)
	{
		for (size_t i = 0; i < _PrimeSize; ++i)
		{
			if (_PrimeList[i] > size)
			{
				return _PrimeList[i];
			}
		}

		//最大返回素数表中最后一个素数
		return _PrimeList[_PrimeSize - 1];
	}

	void Clear()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			Node* cur = _table[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}

			//将桶的结点置空
			_table[i] = NULL;
		}
		//将size置0
		_size = 0;
	}

private:
	vector<Node*> _table;
	size_t _size;
};

void TestHashBucket()
{
	int arr[] = { 52, 3, 105, 46 ,64,23,87,12,8};
	HashBucket<int, int> _hash;
	_hash.Insert(5);
	_hash.Insert(107);
	/*for (int i = 0; i <100; ++i)
	{
		_hash.Insert(i, 0);
	}*/
	/*_hash.Insert("INsert", 0);
	_hash.Insert("sdsd", 0);
	_hash.Insert("Idfasfrt", 0);
	_hash.Insert("Idasd", 0);
	_hash.Insert("Isafft", 0);
	_hash.Insert("Isdfgsdt", 0);
	_hash.Insert("Isdgf", 0);
	_hash.Insert("fdsft", 0);*/



	HashBucket<int, int>::Iterator it = _hash.Begin();

	while (it != _hash.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}