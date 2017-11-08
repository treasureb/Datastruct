#pragma once

#include"HashBucket.h"
using namespace std;

template< class K, class _HashFunction = _Function<K>>
class UnOrderSet
{
	typedef HashBucket<K, K, _Function<K>> HashBucket;
public:
	typedef typename HashBucket::Iterator Iterator;

	pair<Iterator, bool> Insert(const K& key)
	{
		return _hash.Insert(key);
	}

	Iterator Begin()
	{
		return _hash.Begin();
	}

	Iterator End()
	{
		return _hash.End();
	}
	
	Iterator Find(const K& key)
	{
		return _hash.Find(key);
	}

	Iterator Erase(Iterator Pos)
	{
		return _hash.Erase(Pos);
	}

	size_t Erase(const K& key)
	{
		Iterator Pos = _hash.Find(key);
		if (Pos != _hash.End())
		{
			_hash.End(Pos);
			return 1;
		}
		else
			return 0;
	}


private:
	HashBucket _hash;
};

void TestUnOrderSet()
{
	UnOrderSet<int> ht;

	ht.Insert(1);
	ht.Insert(7);
	ht.Insert(20);
	ht.Insert(39);
	ht.Insert(5);
	ht.Insert(35);

	UnOrderSet<int>::Iterator it = ht.Begin();
	while (it != ht.End())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
	
	it = ht.Find(1);
	it = ht.Erase(it);

	it = ht.Begin();
	while (it != ht.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}