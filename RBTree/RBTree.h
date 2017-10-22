#pragma once

#include<iostream>
#include<assert.h>
enum COLOUR{RED,BLACK};

template <class K,class V>
struct RBTreeNode
{
	RBTreeNode(const K& key, const V& value)
	: _left(NULL)
	, _right(NULL)
	, _parent(NULL)
	, _key(key)
	, _value(value)
	, _colour(RED)
	{}

	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	K _key;
	V _value;
	COLOUR _colour;
};

template <class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
	: _root(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			Node* _root = new Node(key, value);
			_root->_colour = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur->_parent;
				cur = cur->_left;
			}
			else if (key > cur->_key)
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
		cur = new Node(key, value);
		if (key < cur->_key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else if (key > cur->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		
		//动态调整节点
		while (parent && parent->_colour == RED )
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
		return true;
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
		Node* subRL = subR->_right;
		Node* pparent = parent->_parent;

		parent->_right = subR->_left;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		while (NULL == pparent)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		if (parent == pparent->_left)
			pparent->_left = subR;
		else if (parent == pparent->_right)
			pparent->_right = subR;

		subR->_parent = pparent;

		parent = subR;
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
		while (NULL == pparent)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		if (parent == pparent->_left)
			parent->_left = subL;
		else if (parent == pparent->_right)
			parent->_right = subL;

		subL->_parent = pparent;
		parent = subL;
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
	int arr[] = { 5, 6, 234, 8, 82, 3, 8, 23, 9, 32, 48 };
	RBTree<int, int> s;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		s.Insert(arr[i], i);
		std::cout << "Insert" << ":" << arr[i] << "  ";
		std::cout << s.CheckBalance() << " ";
		std::cout << std::endl;
	}
}
