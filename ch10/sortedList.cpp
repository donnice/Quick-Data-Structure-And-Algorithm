// sortedList.cpp
// demostrates sorted list
#include <iostream>
using namespace std;

class Link
{
public:
	double dData;
	Link* pNext;

	Link(double dd):dData(dd),pNext(NULL)
	{}

	void displayLink()
	{ cout << dData << " "; }
};

class SortedList
{
private:
	Link* pFirst;

public:
	SortedList():pFirst(NULL)
	{}

	~SortedList()
	{
		Link* pCurrent = pFirst;
		while(pCurrent != NULL)
		{
			Link* pOldCur = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pOldCur;
		}
	}

	bool isEmpty()
	{ return (pFirst == NULL); }

	void insert(double key)
	{
		Link* pNewLink = new Link(key);
		Link* pPrevious = NULL;
		Link* pCurrent = pFirst;

		while(pCurrent != NULL && key > pCurrent->dData)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		if(pPrevious == NULL)
			pFirst = pNewLink;
		else
			pPrevious->pNext = pNewLink;
		pNewLink->pNext = pCurrent;
	}

	void remove()
	{
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		delete pTemp;
	}
};

int main()
{
	return 0;
}
