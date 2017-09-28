#pragma once
#include<iostream>


struct BinaryTreeNode
{
	BinaryTreeNode *_Left;
	BinaryTreeNode *_Right;
	int _value;
};


BinaryTreeNode* ConstructCore(int *StartPreorder, int *EndPreorder, int *StartInorder, int *EndInorder);

BinaryTreeNode* Construct(int *PreOrder, int *InOrder, size_t length)
{
	if (PreOrder == NULL || InOrder == NULL || length <= 0)
		return NULL;

	return ConstructCore(PreOrder, PreOrder + length - 1, InOrder, InOrder + length - 1);
}

BinaryTreeNode* ConstructCore(int *StartPreOrder, int *EndPreOrder, int *StartInOrder, int *EndInOrder)
{
	int RootValue = StartPreOrder[0];//前序的第一个节点即为根结点
	BinaryTreeNode* Root = new BinaryTreeNode();
	Root->_value = RootValue;
	Root->_Left = Root->_Right = NULL;

	if (StartPreOrder == EndPreOrder)
	{
		if (StartInOrder == EndInOrder && *StartPreOrder == *StartInOrder)//只有一个结点
			return Root;
		else
			throw std::exception("Invalid Input");
	}

	int *RootInOrder = StartInOrder;
	while (RootInOrder <= EndInOrder && *RootInOrder != RootValue)//在中序遍历的结果中找根结点
		++RootInOrder;

	if (RootInOrder == EndInOrder && *RootInOrder != RootValue)//遍历完中序都没有找到根结点
		throw std::exception("Invalid Input");

	//走到这里说明在中序中找到了根结点

	int LeftLength = RootInOrder - StartInOrder;
	int *LeftPreOrderEnd = StartPreOrder + LeftLength;//前序遍历后的LeftLength个为左子树

	if (LeftLength > 0)
	{
		//构建左子树
		Root->_Left = ConstructCore(StartPreOrder + 1, LeftPreOrderEnd, StartInOrder, RootInOrder - 1);
	}

	if (LeftLength < EndPreOrder - StartPreOrder)
	{
		//构建右子树
		Root->_Right = ConstructCore(LeftPreOrderEnd + 1, EndPreOrder, RootInOrder + 1, EndInOrder);
	}
	return Root;
}



void PrintBinaryTree(BinaryTreeNode* Root)
{	
	if (Root == NULL)
		return;

	PrintBinaryTree(Root->_Left);		
	PrintBinaryTree(Root->_Right);
	std::cout << Root->_value << " ";
}

void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintBinaryTree(root);
		std::cout << std::endl;
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
}
