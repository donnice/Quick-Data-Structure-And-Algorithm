// linkedlist2
// page 181
#include <iostream>
#include "Link.cpp"

using namespace std;

class LinkedList
{
private:
	Link* pFirst;

public:
	LinkedList():pFirst(NULL){}
	~LinkedList()
	{
		Link* pCurrent = pFirst;
		while(pCurrent != NULL)
		{
			Link* pOldCur = pCurrent;		// save the current link
			pCurrent = pCurrent->pNext;
			delete pOldCur;
		}
	}

	void insertFirst(int id, double dd)
	{
		Link* pNewLink = new Link(id,dd);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	Link* find(int key)
	{
		Link* pCurrent = pFirst;
		while(pCurrent->iData != key)
		{
			if(pCurrent->pNext == NULL)
				return NULL;
			else
				pCurrent = pCurrent->pNext;
		}
		return pCurrent;
	}

	bool remove(int key)
	{
		Link* pCurrent = pFirst;
		Link* pPrevious = pFirst;
		while(pCurrent->iData != key)
		{
			if(pCurrent->pNext == NULL)
				return false;
			else
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}
		}
		if(pCurrent == pFirst)
			pFirst = pFirst->pNext;
		else
			pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
		return true;
	}

	void displayList()
	{
		cout << "List (first --> last):";
		Link* pCurrent = pFirst;
		while(pCurrent != NULL)
		{
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
};

int main()
{
	return 0;
}
