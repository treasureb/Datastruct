#pragma once

#include<iostream>
#include<assert.h>

template <class K>
struct SearchBinaryTreeNode
{
	SearchBinaryTreeNode<K>* _left;
	SearchBinaryTreeNode<K>* _right;
	K _key;

	SearchBinaryTreeNode(const K& key)
		:_key(key)
		, _left(NULL)
		, _right(NULL)
	{}
};

template <class K>
class SearchBinaryTree
{
	typedef SearchBinaryTreeNode<K> Node;
public:
	SearchBinaryTree()
		:_root(NULL)
	{}

	SearchBinaryTree(const SearchBinaryTree<K>& t)
	{
		_Copy(t._root);
	}

	~SearchBinaryTree()
	{
		_Destory(_root);
	}

	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
		}

		//要插入一个结点，则要保存它的父节点
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//不允许插入相同的值
			{
				return false;
			}
		}

		//走到这里已经找到位置
		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else if (key < parent->_key)
		{
			parent->_left = cur;
		}
		
		//走到这说明没有插入
		return false;
	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;

		//开始找位置
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				break;
		}


		//走到这就说明找到待删除节点
		/*if (cur->_left == NULL && cur->_right == NULL)
		{
			如果左右节点都为空则可以直接删除
			delete cur;
			cur = NULL;
			return true;
		}*/

		if (cur->_left == NULL)
		{
			if (_root->_key == key)//判断是否为根节点 
			{
				_root = cur->_right;
				delete cur;
				cur = NULL;
				return true;
			}

			if (parent->_left == cur)//如果为parent的左子树
			{
				parent->_left = cur->_right;
				delete cur;
				cur = NULL;
				return true;
			}

			else if (parent->_right == cur)
			{
				parent->_right = cur->_right;
				delete cur;
				cur = NULL;
				return true;
			}
		}
		else if (cur->_right == NULL)
		{
			if (_root->_key == key)
			{
				_root = cur->_left;
				delete cur;
				cur = NULL;
				return true;
			}

			if (parent->_left == cur)
			{
				parent->_left = cur->_left;
				delete cur;
				cur = NULL;
				return true;
			}
			else if (parent->_right == cur)
			{
				parent->_right = cur->_left;
				delete cur;
				cur = NULL;
				return true;
			}
		}
		else//走到这里说明左右都不为空
		{
			Node* sub = cur;
			Node* First = cur->_right;//用待删除节点的右子树的最左节点和待删除节点交换，防止破坏树的结构

			if (First->_left == NULL)
			{
				std::swap(First->_key, cur->_key);
				cur->_right = First->_right;
				delete First;
				First = NULL;
				return true;
			}
			while (First->_left)
			{
				sub = First;
				First = First->_left;
			}
			std::swap(First->_key, cur->_key);
			sub->_left = First->_right;
			delete First;
			First = NULL;
			return true;
		}
	
		return false;
	}

	void MidOrder()
	{
		_MidOrder(_root);
		std::cout << std::endl;
	}

	const Node* Find(const K& key)//不允许随便改动，因为要满足查找树的性质
	{
		if(_root == NULL);
		return NULL;

		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
		}

		return cur;
	}


	void _Destory(Node*& root)
	{
		if (_root != NULL)
		{
			_Destory(_root->_left);
			_Destory(_root->_right);
			delete root;

			//记得将根节点置为NULL，如果要在这里，则需要传引用
			root = NULL;
		}
	}

	Node* _Copy(Node* root)
	{
		Node* newNode = NULL;

		if (root)
		{
			newNode = root;
			newNode->_left = _Copy(root->_left);
			newNode->_right = _Copy(root->_right);
		}
	}

	void Insert_R(const K& key)
	{
		_Insert_R(_root, key);
		std::cout << std::endl;
	}


	void Remove_R(const K& key)
	{
		_Remove_R(_root, key);
	}
protected:
	void _MidOrder(Node* root)
	{
		if (root == NULL)
			return;
		
		_MidOrder(root->_left);
		std::cout << root->_key << " ";
		_MidOrder(root->_right);
	}
	
	bool _Insert_R(Node*& root, const K& key)
	{
		if (root == NULL)
		{
			root = new Node(key);
			return true;
		}
		if (key > root->_key)
			_Insert_R(root->_right, key);
		else if (key < root->_key)
			_Insert_R(root->_left, key);
		else
			return false;
	}

	bool _Remove_R(Node*& root, const K& key)
	{
		if (root == NULL)
			return false;

		if (key > root->_key)
			_Remove_R(root->_right, key);
		else if (key < root->_key)
			_Remove_R(root->_left,key);
		else
		{
			Node* cur = root;
			if (root->_left == NULL)
			{
				root = root->_right;
			}
			else if (root->_right == NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* First = root->_right;
				while (First->_left)
				{
					First = First->_left;
				}
				std::swap(First->_key, cur->_key);
				return _Remove_R(root->_right, key);
			}
			delete cur;
			cur = NULL;
			return true;
		}
	}
private:
	Node* _root;
};

void Test()
{
	SearchBinaryTree<int> s;
	int arr[] = { 4, 2, 7, 8, 0, 1, 3, 5, 6, 9 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		s.Insert(arr[i]);
	}
	s.MidOrder();
	s.Remove(1);
	s.Remove(0);
	s.Remove(7);
	s.MidOrder();
	s.Remove(3);
	s.Remove(2);
	s.Remove(8);
	s.Remove(9);
	s.Remove(5);
	s.Remove(6);
	s.Remove(4);

	s.MidOrder();

	s.Insert_R(4);
	s.Insert_R(2);
	s.Insert_R(7);
	s.Insert_R(8);
	s.Insert_R(0);
	s.Insert_R(1);
	s.Insert_R(3);
	s.Insert_R(5);
	s.Insert_R(6);
	s.Insert_R(9);
	s.MidOrder();

	s.Remove_R(0);
	s.MidOrder();
	s.Remove_R(2);
	s.MidOrder();
	s.Remove_R(7);
	s.Remove_R(3);
	s.Remove_R(4);
	s.Remove_R(5);
	s.Remove_R(6);
	s.Remove_R(8);
	s.Remove_R(9);
	s.MidOrder();

}
