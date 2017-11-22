#include<iostream>
using namespace std;

enum PointerTag{THREAD,LINK};

template <class T>
struct BinaryTreeNodeThd
{
	T _data;
	BinaryTreeNodeThd<T>* _left;
	BinaryTreeNodeThd<T>* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	BinaryTreeNodeThd(const T& x)
		:_left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
		, _data(x)
	{}
};


template<class T>
struct _BinaryTreeIterator
{
	typedef BinaryTreeNodeThd<T> Node;
	typedef _BinaryTreeIterator<T> Self;
	Node* _node;

	_BinaryTreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self operator++()
	{
		if (_node->_rightTag == THREAD)
		{
			_node = _node->_right;
		}
		else
		{
			Node* sub = _node->_right;
			while (sub && sub->_leftTag == LINK)
			{
				sub = sub->_left;
			}
			_node = sub;
		}
		return *this;
	}
};

template <class T>
class BinaryTreeThd
{
	typedef BinaryTreeNodeThd<T> Node;
public:
	typedef _BinaryTreeIterator<T> Iterator;
	BinaryTreeThd(T* arr, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _Create(arr, size, index, invalid);
	}


	Iterator Begin()
	{
		Node* sub = _root;
		while (sub->_left && sub->_leftTag == LINK)
		{
			sub = sub->_left;
		}

		return sub;
	}

	Iterator End()
	{
		return NULL;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrderThreading()
	{
		Node* prev = NULL;
		_InOrderThreading(_root,prev);
		cout << endl;
	}

	void PreOrderThreading()
	{
		Node* prev = NULL;
		_PreOrderThreading(_root, prev);
		cout << endl;
	}

	void InOrderThread()
	{
		Node* cur = _root;

		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}

			cout << cur->_data << " ";

			//1、子树重新开始 2、为空已经线索化了
			if (cur->_rightTag == LINK)
			{
				cur = cur->_right;
			}
			
			else
			{
				while (cur->_rightTag == THREAD)
				{
					cur = cur->_right;
					cout << cur->_data << " ";
				}
				//子问题
				cur = cur->_right;
			}
			//while (cur->_rightTag == THREAD)
			//{
			//	//跳到后继节点-直接访问后继
			//	cur = cur->_right;
			//	cout << cur->_data << " ";
			//}
			////子问题
			//cur = cur->_right;
		}

	}

protected:
	Node* _Create(T* arr, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if (index < size && arr[index] != invalid)
		{
			root = new Node(arr[index]);
			root->_left = _Create(arr, size, ++index, invalid);
			root->_right = _Create(arr, size, ++index, invalid);
		}

		return root;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PreOrder(Node* _root)
	{
		if (_root == NULL)
			return;

		cout << _root->_data << " ";
		if (_root->_leftTag == LINK)
		{
			_PreOrder(_root->_left);
		}
		if (_root->_rightTag == LINK)
		{
			_PreOrder(_root->_right);
		}
	}
	
	void _InOrderThreading(Node* cur,Node*& prev)
	{
		if (cur == NULL)
			return;

		_InOrderThreading(cur->_left,prev);
		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;
		
		_InOrderThreading(cur->_right,prev);
	}

	void _PreOrderThreading(Node* cur, Node*& prev)
	{
		if (cur == NULL)
			return;

		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;

		if (cur->_leftTag == LINK)
		{
			_PreOrderThreading(cur->_left, prev);
		}

		if (cur->_rightTag == LINK)
		{
			_PreOrderThreading(cur->_right, prev);
		}
	}
protected:
	Node* _root;
};

int main()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> t1(arr,sizeof(arr)/sizeof(arr[0]),'#');
	t1.InOrderThreading();
	BinaryTreeThd<int>::Iterator it = t1.Begin();
	while ((it) != t1.End())
	{
		cout << *it << " ";
		it++;
	}
	/*t1.InOrder();
	t1.PreOrder();
	t1.PreOrderThreading();
	t1.InOrderThread();*/
	system("pause");
	return 0;
}