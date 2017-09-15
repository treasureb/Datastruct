#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& data)
	:_data(data)
	,_left(NULL)
	, _right(NULL)
	{}

};

template <class T>
class BinaryTree
{
public:
	typedef BinaryTreeNode<T> Node;

	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(const T array[], size_t size , const T& invalid)
	{
		assert(array);
		size_t index = 0;
		_CreateNode(_root,array, size, index, invalid);
	}

	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	void Size()
	{
		cout<< _Size(_root)<<endl;	
	}

	void Size2()
	{
		size_t count = 0;
		cout << _Size2(_root, count) << endl;;
	}

	void LeafSize()
	{
		size_t count = 0;
		cout << _LeafSize(_root,count) <<endl;
	}

	void Height()
	{
		cout << _Height(_root)<<endl;
	}

	void KofNumber(size_t k)
	{
		size_t level = k;
		cout << _KofNumber(_root,level)<<endl;
	}


private:
	void _CreateNode(Node* &root, const T array[], size_t size, size_t& index, const T& invalid)
	{
		if (size > 0 && array[index] != invalid)
		{
			root = new Node(array[index]);
			_CreateNode(root->_left, array, size, ++index, invalid);
			_CreateNode(root->_right, array, size, ++index, invalid);
		}
	}

	void _PreOrder(Node* root)
	{
		if (root == NULL)
			return;

		cout << root->_data << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data <<" " ;
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;
		else
		return (_Size(root->_left) + _Size(root->_right) + 1);
	}

	size_t _Size2(Node* root,size_t& count)
	{
		if (root == NULL)
			return 0;
		
		count++;
		_Size2(root->_left,count);
		_Size2(root->_right,count);

		return count;
	}

	size_t _LeafSize(Node* root,size_t& count)
	{
		if (root == NULL)
			return 0;
		
		if (root->_left == NULL && root->_right == NULL)
			count++;

		_LeafSize(root->_left,count);
		_LeafSize(root->_right, count);

		return count;
	}
	
	size_t _Height(Node* root)
	{
		if (root == NULL)
			return 0;
	
		int left = _Height(root->_left);
		int right = _Height(root->_right);

		return left > right ? left + 1 : right + 1;
	}

	size_t _KofNumber(Node* root,size_t level)
	{
		if (root == NULL || level <= 0)
			return 0;

		if (root != NULL && level == 1)
			return 1;

		return _KofNumber(root->_left, level - 1) + _KofNumber(root->_right, level - 1);
	}
private:
	Node* _root;
};

int main()
{
	int array[] = { 1, 2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8,'#','#'};
	BinaryTree<int> bt(array, sizeof(array), '#');
	bt.PreOrder();
	bt.InOrder();
	bt.PostOrder();
	bt.Size();
	bt.Size2();
	bt.LeafSize();
	bt.Height();
	bt.KofNumber(3);
	system("pause");
	return 0;
}