#pragma once 
#include<iostream>
using namespace std;

template <class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key, const V& value)
	:_key(key)
	, _value(value)
	, _pLeft(NULL)
	, _pRight(NULL)
	, _pParent(NULL)
	, _bf(0)
	{};
	AVLTreeNode<K,V> *_pLeft;
	AVLTreeNode<K,V> *_pRight;
	AVLTreeNode<K,V> *_pParent;
	K _key;
	V _value;
	int _bf;
};


template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public: 
	AVLTree()
		:_pRoot(NULL)
	{}

	AVLTree(const AVLTree<K, V>& t)
	{
		_Copy(_pRoot);
	}

	~AVLTree()
	{
		_Destory(_pRoot);
	}

	bool Insert(const K& key, const V& value)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}
		Node* pCur = _pRoot;
		Node* pParent = NULL;

		while (pCur)
		{
			if (key < pCur->_key)
			{
				pParent = pCur;//更新双亲
				pCur = pCur->_pLeft;
			}
			else if (key>pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
			{
				return false;
			}
		}

		//找到了插入的位置，然后创建待插入的结点
		pCur = new Node(key, value);
		if (key < pParent->_key)
		{
			pParent->_pLeft = pCur;
		}

		else if (key>pParent->_key)
		{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;

		while (pParent)
		{
			if (pParent->_pLeft == pCur)
				pParent->_bf--;
			else if (pParent->_pRight == pCur)
				pParent->_bf++;
			
			if (0 == pParent->_bf)
				return true;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else// 进行旋转
			{
				if (2 == pParent->_bf)
				{
					if (1 == pCur->_bf)
						_RotateLeft(pParent);
					else
						_RotateRL(pParent);
				}
				else
				{
					if (-1 == pCur->_bf)
						_RotateRight(pParent);
					else
						_RotateLR(pParent);
				}
			}
		}
	}


	void _RotateLeft(Node* pParent)
	{
		Node *pSubR = pParent->_pRight;
		Node *pSubRL = pSubR->_pLeft;
		Node *pPParent = pParent->_pParent;
		
		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;
		
		if (NULL == pPParent)
		{
			_pRoot = pSubR;
			pSubR->_pParent = NULL;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
			
			pSubR->_pParent = pPParent;
		}
		pParent->_bf = pSubR->_bf = 0;
		pParent = pSubR;
	};

	bool IsBalanceTree()
	{
		int height = 0;
		return _IsbalanceTree(_pRoot, height);
	}

	void MidOrder()
	{
		cout << "MidOrder:" << " ";
		_MidOrder(_pRoot);
		cout << endl;
	}

	size_t Height(Node* pRoot)
	{
		if (NULL == pRoot)
			return 0;
		if (NULL == pRoot->_pLeft&&NULL == pRoot->_pRight)
			return 1;
		size_t LeftHeight = Height(pRoot->_pLeft);
		size_t RightHeight = Height(pRoot->_pRight);
		return LeftHeight > RightHeight ? LeftHeight + 1, RightHeight + 1;
	}

	Node* Find(const K& key)
	{
		if (_pRoot == NULL)
			return NULL;

		Node* cur = _pRoot;
		if (key < cur->_key)
			_pRoot = cur->_pLeft;
		else if (key > cur->_pRight)
			_pRoot = cur->_pRight;
		else
			return cur;
	}
protected:

	void _RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		Node* pPParent = pParent->_pParent;
		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;
		
		if (NULL == pPParent)
		{
			_pRoot = pSubL;
			pSubL->_pParent = NULL;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;

			pSubL->_pParent = pPParent;
		}
		pParent->_bf = pSubL->_bf = 0;
		pParent = pSubL;
	}
	

	void _RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubL->_bf;
		
		_RotateLeft(pParent->_pLeft);
		_RotateRight(pParent);

		if (-1 == bf)
			pParent->_bf = 1;
		else if(1 == bf)
			pSubL->_bf = -1;

	}

	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		_RotateRight( pParent->_pRight);
		_RotateLeft( pParent);

		if (1 == bf)
			pParent->_bf = -1;
		else if(-1 == bf)
			pSubR->_bf = 1;

	}

	bool _IsbalanceTree(Node* pRoot)
	{
		if (NULL == pRoot)
			return true;
		
		int LeftHeight = Height(pRoot->_pLeft);
		int RightHeight = Height(pRoot->_pRight);
		//因为可能当前层高度相同，而子树不满足AVL树的性质，所以要递归判断子树
		return _IsbalanceTree(pRoot->_pLeft) && _IsbalanceTree(pRoot->_pRight) && abs(pRoot->_bf) < 2;

	}

	bool _IsbalanceTree(Node* pRoot, int& height)
	{
		if (NULL == pRoot)
		{
			height = 0;
			return true;
		}
		
		int leftHeight = 0;
		int rightHeight = 0;
		if (_IsbalanceTree(pRoot->_pLeft, leftHeight) == 0)
			return false;

		if (_IsbalanceTree(pRoot->_pRight, rightHeight) == 0)
			return false;

		height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return (abs(leftHeight - rightHeight) < 2);
	}

	void _MidOrder(Node* pRoot)
		{
			if (NULL == pRoot)
				return;
			_MidOrder(pRoot->_pLeft);
			cout << pRoot->_key << " ";
			_MidOrder(pRoot->_pRight);
		}

	void _Copy(Node* root)
	{
		Node* newroot = NULL;

		if (root)
		{
			newroot = root;
			newroot->_pLeft = _Copy(root->_pLeft);
			newroot->_pRight = Copy(root->_pRight);
		}
	}

	void _Destory(Node* root)
	{
		if (root == NULL)
			return;

		_Destory(root->_pLeft);
		_Destory(root->_pRight);
		delete root;
	}
protected:
	Node* _pRoot;
};