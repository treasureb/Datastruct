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
	typedef _BinaryTreeIterator<T> Seif;
	Node* _node;

	_BinaryTreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator!=(const Seif& s)
	{
		return _node != s._node;
	}

	Seif operator++()
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
		while (sub && sub->_leftTag == LINK)
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

	void InOrderThreading()
	{
		Node* prev = NULL;
		_InOrderThreading(_root,prev);
		cout << endl;
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
		prev = cur;

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		_InOrderThreading(cur->_right,prev);
	}
protected:
	Node* _root;
};

int main()
{
	int arr[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> t1(arr,sizeof(arr)/sizeof(arr[0]),'#');
	BinaryTreeThd<int>::Iterator it = t1.Begin();
	while (it != t1.End())
	{
		cout << *it << " ";
	}
	t1.InOrder();
	t1.InOrderThreading();
	system("pause");
	return 0;
}