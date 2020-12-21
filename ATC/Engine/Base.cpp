#include "DXUT.h"
#include "Base.h"

USING(Engine)

ULONG Base::AddReference(void)
{
	cout << refCount << endl;
	return refCount++;
}

ULONG Base::Release(void)
{
	if (refCount == 0)
	{
		Free();
		delete this;
		return 0;
	}
	return refCount--;
}
