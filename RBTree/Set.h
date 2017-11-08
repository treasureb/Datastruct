#pragma once
#include"RBTree.h"
using namespace std;

template <class K>
class Set
{
	struct __KeyOfValue
	{
		const K operator()(const K& value)
		{
			return value;
		}
	};

public:
	typedef typename RBTree<K, K, __KeyOfValue> ::Iterator Iterator;

	pair<Iterator, bool> Insert(const K& key)
	{
		return _t.Insert(key);
	}

	Iterator Begin()
	{
		return _t.Begin();
	}

	Iterator End()
	{
		return _t.End();
	}
private:
	RBTree<K,K,__KeyOfValue> _t;
};

void TestSet()
{
	Set<int> set;
	set.Insert(1);
	set.Insert(2);
	set.Insert(3);
	set.Insert(4);
	set.Insert(5);
	set.Insert(6);

	Set<int>::Iterator it = set.Begin();
	while (it != set.End())
	{
		cout << *it << " ";
		++it;
	}

}