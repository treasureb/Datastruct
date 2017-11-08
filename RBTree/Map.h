#pragma once
#include"RBTree.h"
using namespace std;

template<class K,class V>
class Map
{
	typedef pair<K, V> ValueType;
public:
	typedef typename RBTree<K, V, __KeyOfValue>::Iterator Iterator;

	pair<Iterator, bool> Insert(ValueType& kv)
	{
		return _t.Insert(kv);
	}

	Iterator Begin()
	{
		return _t.Begin();
	}

	Iterator End()
	{
		return _t.End;
	}

	V& operator[](const K& key)
	{
		return (*(Insert(make_pair(key, V())).first)).second;
	}

private:
	RBTree<K, ValueType, __KeyOfValue> _t;
};