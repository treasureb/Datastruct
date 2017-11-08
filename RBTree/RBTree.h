#pragma once

#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

enum COLOUR{RED,BLACK};//颜色也可以用bool值代替

template <class ValueType>
struct RBTreeNode
{
	RBTreeNode(const ValueType& valueField)
	: _left(NULL)
	, _right(NULL)
	, _parent(NULL)
	/*, _key(key)
	, _value(value)*/
	, _valueField(valueField)
	, _colour(RED)
	{}

	RBTreeNode<ValueType>* _left;
	RBTreeNode<ValueType>* _right;
	RBTreeNode<ValueType>* _parent;
	/*K _key;
	V _value;*/
	ValueType _valueField;
	COLOUR _colour;
};

template <class T>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T> Self;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_valueField;
	}

	T* operator->()
	{
		//return (*_node)._valueField;
		return &(operator());
	}

	bool operator==(const Self& s)const
	{
		return _node == s._node;
	}
	
	bool operator!=(const Self& s)const
	{
		return _node != s._node;
	}

	Self& operator++()
	{
		if (NULL != _node->_right)//右子树存在的话，找右子树的最左节点
		{
			_node = _node->_right;
			while (_node->_left != NULL)
				_node = _node->_left;
		}
		else 
		{
			Node* Parent = _node->_parent;//不存在，在祖先节点里找为右孩子的节点
			while (NULL != Parent &&  _node == Parent->_right)
			{
				_node = Parent;
				Parent = Parent->_parent;
			}
			if (_node->_right != Parent)
				_node = Parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node->_left != NULL)//左子树存在，找左子树的最右节点
		{
			_node = _node->_left;
			while (_node->_right)
				_node = _node->_right;
		}
		else
		{
			Node* Parent = _node->_parent;
			while (NULL != Parent && _node == Parent->_left)
			{
				_node = Parent;
				Parent = Parent->_parent;
			}
			if (_node->_left != Parent)
				_node = Parent;
		}
		s
		return *this;
	}
	Node* _node;
};

template<class K>
struct __KeyOfValue
{
	const K operator()(const K& value)
	{
		return value;
	}
};

template <class K,class T>
struct __PairOfValue
{
	const K operator()(const T& value)
	{
		return value.first;
	}
};

template <class K,class T, class _KeyOfValue = __KeyOfValue<K>>
class RBTree
{
	typedef RBTreeNode<T> Node;//这里的T已经不是原始意义上的value
public:
	typedef __RBTreeIterator<T> Iterator;
	RBTree()
	: _root(NULL)
	{}

	Iterator Begin()//最左节点
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return Iterator(left);
	}

	Iterator End()
	{
		return Iterator(NULL);
	}

	//最右节点
	Iterator RBegin()
	{
		Node* right = _root;
		while (right&&right->_right)
		{
			right = right->_right;
		}
		return Iterator(right);
	}

	Iterator REnd()
	{
		return Iterator(NULL);
	}

	pair<Iterator,bool> Insert(const T& kv)
	{
		if (_root == NULL)
		{
			_root = new Node(kv);
			_root->_colour = BLACK;
			return make_pair(Iterator(_root),true);
		}
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (_KeyOfValue()(kv) <_KeyOfValue() (cur->_valueField))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (_KeyOfValue()(kv) > _KeyOfValue()(cur->_valueField))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				assert(false);
			}
		}
		//走到这里，找到待插入点
		cur = new Node(kv);
		if (_KeyOfValue()(kv) < _KeyOfValue()(parent->_valueField))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else if (_KeyOfValue()(kv) > _KeyOfValue()(parent->_valueField))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//动态调整节点
		while (parent && parent->_colour == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_colour == RED)
				{
					parent->_colour = uncle->_colour = BLACK;
					grandfather->_colour = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						//BUG  第一次旋转后改变了parent和cur的位置，导致第二次旋转后颜色设置错误
						std::swap(parent, cur);
						RotateL(parent);
					}
					RotateR(grandfather);
					grandfather->_colour = RED;
					parent->_colour = BLACK;
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_colour == RED)
				{
					parent->_colour = uncle->_colour = BLACK;
					grandfather->_colour = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						std::swap(parent, cur);
						RotateR(parent);
					}
					RotateL(grandfather);
					grandfather->_colour = RED;
					parent->_colour = BLACK;
					break;
				}
			}
		}
		_root->_colour = BLACK;
		return make_pair(Iterator(cur), true);
	}
	bool CheckBalance()
	{
		size_t k = 0;
		if (NULL == _root)
			return true;		
		
		if (RED == _root->_colour)
		{	
			std::cout << "根节点为红" << " ";
			return false;
		}

		size_t BlankCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (BLACK == cur->_colour)
			{
				BlankCount++;
				cur = cur->_left;
			}
		}


		_CheckBalance(_root,BlankCount,k);
	}
	
	
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		if (NULL == pparent)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else if (parent == pparent->_right)
				pparent->_right = subR;

			subR->_parent = pparent;

			parent = subR;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;
		if (NULL == pparent)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (parent == pparent->_left)
				parent->_left = subL;
			else if (parent == pparent->_right)
				parent->_right = subL;

			subL->_parent = pparent;
			parent = subL;
		}
	}
	bool _CheckBalance(Node* root, size_t BlankCount, size_t k)
	{
		if (NULL == root)
			return true;
		if (BLACK == root->_colour)
			k++;
		Node* parent = root->_parent;
		if (root->_colour == RED && parent->_colour == RED)
		{
			std::cout << "相邻的红节点" << " ";
			return false;
		}

		if (root->_left == NULL && root->_right == NULL)
		{
			if (k != BlankCount)
			{
				std::cout << "黑色数量不相等" << " ";
				return false;
			}

			return true;
		}

		return (_CheckBalance(root->_left, BlankCount, k) && _CheckBalance(root->_right, BlankCount, k));
	}
private:
	Node* _root;
};

void TestRBTree()
{
	//int arr[] = { 5, 6, 234, 8, 82, 3, 8, 23, 9, 32, 48 };
	//RBTree<int,string> s;
	///*for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	s.Insert(arr[i], i);
	//	std::cout << "Insert" << ":" << arr[i] << "  ";
	//	std::cout << s.CheckBalance() << " ";
	//	std::cout << std::endl;
	//}*/
	//s.Insert("sort");
	//s.Insert("value");
	//s.Insert("heap");
	//s.Insert("tree");

	//RBTree<int, string>::Iterator it = s.Begin();
	//while (it != s.End())
	//{
	//	std::cout << *it << " ";
	//	++it;
	//}

	//RBTree<int, string>::Iterator it2 = s.End();
	//while (it2 != s.Begin())
	//{
	//	std::cout << *(--it2) << " ";
	//}

	RBTree<int, int> ht;
	ht.Insert(1);
	ht.Insert(2);
	ht.Insert(3);
	ht.Insert(4);
	ht.Insert(5);
	ht.Insert(6);
	
	RBTree<int,int>::Iterator it = ht.Begin();
	while (it != ht.End())
	{
		cout << *it << " ";
		++it;
	}
}
