// listInsertionSort.cpp
// page 213
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Link
{
public:
	double dData;
	Link* pNext;

	Link(double dd):dData(dd),pNext(NULL)
	{}
};

class SortedList
{
private:
	Link* pFirst;

public:
	SortedList():pFirst(NULL){}

	SortedList(Link** linkArr, int length):pFirst(NULL)
	{
		for(int j = 0; j<length; j++)
			insert(linkArr[j]);
	}

	void insert(Link* pArg)
	{
		Link* pPrevious = NULL;
		Link* pCurrent = pFirst;

		while(pCurrent != NULL && pArg->dData > pCurrent->dData)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		if(pPrevious == NULL)
			pFirst = pArg;
		else
			pPrevious->pNext = pArg;
		pArg->pNext = pCurrent;
	}

	Link* remove()
	{
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		return pTemp;
	}
};

int main()
{
	return 0;
}
