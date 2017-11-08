#pragma once
#include"HashBucket.h"
#include<string>

template <class K, class V, class _HashFunction = _Function<K>>
class UnOrderMap
{
	typedef HashBucket<K, pair<K, V>, _HashFunction, PairOfValue<K, pair<K,V>>> HashBucket;
public:
	typedef typename HashBucket::Iterator Iterator;
	UnOrderMap()
	{}

	pair<Iterator, bool> Insert(const pair<K, V> kv)
	{
		return _hash.Insert(kv);
	}

	Iterator Find(const K& key)
	{
		return _hash.Find(key);
	}

	Iterator Erase(const K& key)
	{
		_hash.Erase(key);
	}

	Iterator Begin()
	{
		return _hash.Begin();
	}

	Iterator End()
	{
		return _hash.End();
	}

	size_t Size()
	{
		return _hash.Size();
	}

	V& operator[](const K& key)
	{
		pair<Iterator, bool> ret = Insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	HashBucket _hash;
};

void TestUnOrderMap()
{
	UnOrderMap<string, string> dict;
	dict["sort"] = "排序";
	dict["heap"] = "堆";
	dict["greade"] = "大于";
	dict["less"] = "小于";
	dict["less"] = "相同";

	UnOrderMap<string, string>::Iterator it = dict.Begin();
	while (it != dict.End())
	{
		cout <<it->first<< ": "<<it->second<<endl;
		++it;
	}

}