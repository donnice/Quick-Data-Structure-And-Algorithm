// page 220
// demostrated doubly-linked list
#include <iostream>
using namespace std;

class Link
{
public:
	double dData;
	Link* pNext;
	Link* pPrevious;

	Link(double dd):dData(dd),pNext(NULL),pPrevious(NULL){}

	void displayLink()
	{ cout << dData << " ";}
};

class DoublyLinkedList
{
private:
	Link* pFirst;
	Link* pLast;

public:
	DoublyLinkedList():pFirst(NULL),pLast(NULL)
	{}

	~DoublyLinkedList()
	{
		Link* pCurrent = pFirst;	// start at the begin of list;
		while(pCurrent != NULL)
		{
			Link* pOldCur = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pOldCur;
		}
	}

	bool isEmpty()
	{
		return pFirst == NULL;
	}

	void insertFirst(double dd)
	{
		Link* pNewLink = new Link(dd);

		if(isEmpty())
			pLast = pNewLink;
		else 
			pFirst->pPrevious = pNewLink;
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}
};
