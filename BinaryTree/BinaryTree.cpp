#include<iostream>
#include<string>
#include<queue>
#include<stack>
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

	void levelOrder()
	{
		 _leverOrder(_root);
		 cout << endl;
	}

	void IsCompleteTree()
	{
		bool fulltag = _IsCompleteTree(_root, fulltag);
		
		if (fulltag == true)
			cout << "The Tree Is CompleteTree!"<< endl;
		else
			cout << "The Tree Not CompleteTree!"<< endl;
	}

	void PreOrder_Not()
	{
		_PreOrder_Not(_root);
		cout << endl;
	}

	void InOrder_Not()
	{
		_InOrder_Not(_root);
		cout << endl;
	}

	void PostOrder_Not()
	{
		Node* prev = NULL;
		_PostOrder_Not(_root,prev);
		cout << endl;
	}

	Node* Find(const T& x)
	{
		Node* ret = _Find(_root, x);
		cout <<" Find it " << ret->_data << " ";
		cout << endl;
		return ret;
	}

    bool IsSymmetrical()
    {
        return  _IsSymmetrical(_root,_root);
    }

    void Print()
    {
        _Print(_root);
    }

    Node* FindParent(Node* x1,Node* x2)
    {
        stack<Node*> path1;
        stack<Node*> path2;
        if(!GetPath(_root,x1,path1) || !GetPath(_root,x2,path2))
            return NULL;
        while(!path1.empty())
        {
            if(path1.size() > path2.size())
            {
                int size = path1.size() - path2.size();
                while(size--)
                path1.pop();
            }
            if(path1.size() < path2.size())
            {
                int size = path2.size() - path1.size();
                while(size--)
                path2.pop();
            }
            else 
            {
                if(path1.top() == path2.top()) 
                return path1.top();
  
                path1.pop();
                path2.pop();
            }
        }
    }
    
    int FindParentInt(Node* x1,Node* x2)
    {
        Node* cur = FindParent(x1,x2);
        return cur->_data;
    }
    
private:
    bool GetPath(Node* root,Node* x,stack<Node*>& path)
    {
        if(root == NULL)
            return false;

        path.push(root);
        if(root == x)
        return true;
        
        if(GetPath(root->_left,x,path))
            return true;
        if(GetPath(root->_right,x,path))
            return true;

        path.pop();
        return false;
    }

    void _Print(Node* root)
    {
        if(_root == NULL)
            return;

        queue<Node*> node;
        node.push(_root);
        int nextLevel = 0;
        int toBePrint = 1;
        while(!node.empty())
        {
            Node* cur = node.front();
            cout<<cur->_data<<" ";

            if(cur->_left != NULL)
            {
                node.push(cur->_left);
                ++nextLevel;
            }
            if(cur->_right != NULL)
            {
                node.push(cur->_right);
                ++nextLevel;
            }

            node.pop();
            --toBePrint;
            if(toBePrint == 0)
            {
                cout<<endl;
                toBePrint = nextLevel;
                nextLevel = 0;
            }
        }
    }

    bool _IsSymmetrical(Node* root1,Node* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 == NULL || root2 == NULL)
            return false;

        if(root1->_data != root2->_data)
            return false;

        return _IsSymmetrical(root1->_left,root2->_right) && _IsSymmetrical(root1->_right,root2->_left);
    }

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

	void _leverOrder(Node* root)
	{
		if (root == NULL)
			return ;

		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* front = q.front();//根节点访问完，将自己的两个孩子带入队列
			cout << front->_data << " ";
			q.pop();

			if (front->_left)
			q.push(front->_left);

			if (front->_right)
			q.push(front->_right);
		}

	}

	bool _IsCompleteTree(Node* root,bool& fulltag)
	{
		if (root == NULL)
			return false;

		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* front = q.front();
			q.pop();
			if (front->_left)
			{
				q.push(front->_left);
				if (fulltag == false)//表示前面已经有节点没有孩子了
					return false;
			}
			else
			{
				fulltag = false;
			}

			if (front->_right)
			{
				q.push(front->_right);
				if (fulltag == false)
					return false;
			}
			else
			{
				fulltag = false;
			}
		}
		return true;
	}

	void _PreOrder_Not(Node* root)
	{
		stack<Node*> s;
		Node* cur = root;

		while (cur || !s.empty())
		{
			while (cur)//一直循环打印左边的节点
			{
				cout << cur->_data << " ";
				s.push(cur);
				cur = cur->_left;
			}

			//已经到了最左边的节点
			Node* top = s.top();
			s.pop();
			cur = top->_right;
		}
	}

	void _InOrder_Not(Node* root)
	{
		stack<Node*> s;
		Node* cur = root;

		while (cur || !s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			s.pop();
			cout << top->_data<< " ";
			cur = top->_right;
		}
	}


	void _PostOrder_Not(Node* root,Node*& prev)
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{				
				cout << top->_data << " ";
				prev = top;
				s.pop();
			}
			else
			{				
				cur = top->_right;
			}
		}
	}


	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
			return NULL;

		if (root->_data == x)
			return root;

		Node* ret = _Find(root->_left,x);
		if (ret)
		{
			return ret;
		}
		return _Find(root->_right,x);
	}
private:
	Node* _root;
};

int main()
{
	int array[] = { 1, 2,'#',4,'#','#',5,'#','#'};
	BinaryTree<int> bt(array, sizeof(array), '#');
//	bt.PreOrder();
//	bt.InOrder();
//	bt.PostOrder();
//	bt.Size();
//	bt.Size2();
//	bt.LeafSize();
//	bt.Height();
//	bt.KofNumber(3);
//	bt.levelOrder();
//	bt.PreOrder_Not();
//	bt.InOrder_Not();
//	bt.PostOrder_Not();
//	bt.IsCompleteTree();
//	bt.Find(5);
//    cout<< bt.IsSymmetrical()<<endl;
//    bt.levelOrder();
//    bt.Print();
    
   cout<< bt.FindParentInt(bt.Find(4),bt.Find(5))<<endl;
    return 0;
}

