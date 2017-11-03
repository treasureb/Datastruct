#pragma once

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


namespace HashTableSQL
{

	enum State
	{
		EMPTY,
		DELETE,
		EXISTS
	};

	template<class K>
	struct _Function
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	template<>//模板特化
	class _Function<string>
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

	template <class K, class V>
	struct HashNode
	{
		HashNode()
		{}

		HashNode(const K& key, const V& value)
			:_state(EMPTY)
			, _key(key)
			, _value(value)
		{}

		K _key;
		V _value;
		State _state;
	};

	//给出素数表
	static const int _PrimeSize = 28;
	static const unsigned long _PrimeList[_PrimeSize] =//ul为后缀，表明是无符号的long
	{
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

	template<class K, class V, class _HashFunction = _Function<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
		{}

		HashTable(size_t size)
			:_size(0)
		{
			assert(size > 0);
			_table.resize(size);
		}

		pair<Node*, bool> Insert(const K& key, const V& value)
		{
			CheckCapacity();
			size_t index = HashFunction(key);
			while (_table[index]._state == EXISTS)
			{
				++index;
				if (index == _table.size())//走到最后一个位置,从头开始
					index = 0;
			}
			_table[index]._key = key;
			_table[index]._value = value;
			_table[index]._state = EXISTS;

			_size++;

			return make_pair<Node*, bool>(&_table[index], true);
		}

		size_t HashFunction(const K& key)
		{
			//创建一个哈希函数的对象，然后调用()
			_HashFunction hf;
			size_t hash = hf(key);

			return hash % _table.size();
		}

		void CheckCapacity()
		{
			/*if (_table.size() == 0)
				_table.resize(10);

				_table.resize(_size * 2);*/

			if (_table.size() == 0)//这里摒弃上面的做法，直接用素数表中的大小
			{
				_table.resize(_PrimeList[0]);
			}

			//考虑负载因子
			if (_size * 10 / _table.size() >= 7)
			{
				size_t index = 0;
				while (index < _PrimeSize)
				{
					++index;
				}
				size_t newsize = _PrimeList[index];

				//现代写法，创建一个临时对象，将数据重新插入后，将两个对象的表换一下
				//临时对象会自己调用析构
				HashTable<K, V> tmp(newsize);
				for (size_t i = 0; i < tmp._size; ++i)
				{
					if (_table[i]._state == EXISTS)
					{
						tmp.Insert(_table[i]._key, _table[i]._value);
					}
				}

				//要调用vector的swap函数，否则就是一直深拷贝
				_table.swap(tmp._table);
			}
		}


		Node* Find(const K& key)
		{
			size_t index = HashFunction(key);

			while (_table[index]._state != EXISTS)
			{
				if (_table[index]._key == key)
				{
					if (_table[index]._state == DELETE)
					{
						return NULL;

						return &_table[index];
					}

					++index;
					if (index == _size)
						index = 0;
				}

				return &_table[index];
			}
		}

		void Remove(const K& key)
		{
			//直接利用Find函数
			Node* DelNode = Find(key);

			if (DelNode != NULL)
			{
				//如果真的删除节点的话，会影响后来数据的查询与插入，所以只需改下状态
				_table[index]._state = DELETE;
			}

		}
	private:
		vector<Node> _table;
		size_t _size;
	};
}


//void TestHash()
//{
//	//HashTable<int,int> _v;
//	int arr[] = { 49, 19, 28, 38 };
//	for (size_t i = 0; i < sizeof arr / sizeof arr[0]; ++i)
//	{
//		_v.Insert(arr[i], 0);
//	}
//}