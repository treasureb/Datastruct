#include"TopK.h"

void Test()
{
	vector<int> v;
	v.resize(100, 1);

	v[4] = 2;
	v[5] = 3;
	v[6] = 4;
	v[7] = 5;
	
	v[40] = 6;
	v[50] = 7;
	v[60] = 8;
	v[70] = 9;
	TopK(v, 5);
}

int main()
{
	Test();
	system("pause");
	return 0;
}