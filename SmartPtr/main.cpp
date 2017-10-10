#include"AutoPtr.h"
#include"ScopedPtr.h"
#include"ScopedArray.h"
#include"SharedPtr.h"

//template<class T>
//ScopedPtr<T>::ScopedPtr(ScopedPtr<T>& sp)
//:_ptr(sp._ptr)
//{}

int main()
{
	/*ScopedPtr<int> sp1(new int(10));
	ScopedPtr<int> sp2(sp1);
	*/
	//Test();
	//TestScopedPtr();
	//TestScopedArray();
	//TestSharedPtr();
	TestCycleRef();
	system("pause");
	return 0;
}