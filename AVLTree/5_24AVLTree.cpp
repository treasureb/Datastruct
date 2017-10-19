#include"5_14AVLTree.h"

int main()
{
	int a[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	AVLTree<int, int> s;
	for (int idx = 0; idx < 10; idx++)
	{
		s.Insert(a[idx], idx);
		//s.IsBalanceTree();
		s.MidOrder();
		std::cout << std::endl;
	}
	s.MidOrder();
	s.IsBalanceTree();
	return 0;
}