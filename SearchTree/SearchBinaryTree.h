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

		//Ҫ����һ����㣬��Ҫ�������ĸ��ڵ�
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
			else//�����������ͬ��ֵ
			{
				return false;
			}
		}

		//�ߵ������Ѿ��ҵ�λ��
		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else if (key < parent->_key)
		{
			parent->_left = cur;
		}
		
		//�ߵ���˵��û�в���
		return false;
	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;

		//��ʼ��λ��
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


		//�ߵ����˵���ҵ���ɾ���ڵ�
		/*if (cur->_left == NULL && cur->_right == NULL)
		{
			������ҽڵ㶼Ϊ�������ֱ��ɾ��
			delete cur;
			cur = NULL;
			return true;
		}*/

		if (cur->_left == NULL)
		{
			if (_root->_key == key)//�ж��Ƿ�Ϊ���ڵ� 
			{
				_root = cur->_right;
				delete cur;
				cur = NULL;
				return true;
			}

			if (parent->_left == cur)//���Ϊparent��������
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
		else//�ߵ�����˵�����Ҷ���Ϊ��
		{
			Node* sub = cur;
			Node* First = cur->_right;//�ô�ɾ���ڵ��������������ڵ�ʹ�ɾ���ڵ㽻������ֹ�ƻ����Ľṹ

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

	const Node* Find(const K& key)//���������Ķ�����ΪҪ���������������
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

			//�ǵý����ڵ���ΪNULL�����Ҫ���������Ҫ������
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
