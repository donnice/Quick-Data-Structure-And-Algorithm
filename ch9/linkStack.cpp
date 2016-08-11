// page 190
// linklist made stack
#include <iostream>
using namespace std;

class Link
{
public:
	double dData;
	Link* pNext;

	Link(double dd):dData(dd),pNext(NULL){}
	void displayLink()
	{
		cout << dData << " ";
	}
};

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
			Link* pOldCur = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pOldCur;
		}
	}

	bool isEmpty()
	{
		return (pFirst == NULL);
	}

	void insertFirst(double dd)
	{
		Link* pNewLink = new Link(dd);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}
	
	double deleteFirst()
	{
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		double key = pTemp->dData;
		delete pTemp;
		return key;
	}

	void displayList()
	{
		Link* pCurrent = pFirst;
		while(pCurrent != NULL)
		{
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
};

class LinkStack
{
private:
	LinkedList* pList;				// LinkedList itself is actually a node

public:
	LinkStack()
	{ pList = new LinkedList; }		// LinkedList() = is not overloaded

	~LinkStack()
	{ delete pList; }

	void push(double j)
	{
		pList->insertFirst(j);
	}

	double pop()
	{ return pList->deleteFirst(); }

	bool isEmpty()
	{
		return pList->isEmpty();
	}

	void displayStack()
	{
		cout << "Stack (top --> bottom):";
		pList->displayList();
	}
};

int main()
{
	LinkStack theStack;
	
	theStack.push(20);
	theStack.push(40);

	theStack.displayStack();

	return 0;
}
