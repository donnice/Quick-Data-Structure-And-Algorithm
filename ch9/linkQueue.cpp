// use link to implement a Queue
// double ended list
// page 198
#include <iostream>
using namespace std;

class Link
{
public:
	double dData;
	Link* pNext;

	Link(double d):dData(d), pNext(NULL)	// constructor
	{ }

	void displayLink()
	{ cout << dData << " ";}
};	// end class Link

class FirstLastList
{
private:
	Link* pFirst;							// ptr to first
	Link* pLast;							// ptr to last
	// a variable or an object can be modified in a called function

public:
	FirstLastList():pFirst(NULL),pLast(NULL)
	{}

	~FirstLastList()
	{
		Link* pCurrent = pFirst;			// start from beginning
		while(pCurrent != NULL)
		{
			Link* pTemp = pCurrent;
			pCurrent = pCurrent->pNext;
			delete pTemp;
		}
	}

	bool isEmpty()
	{ return pFirst == NULL;}

	void insertFirst(double dd)
	{
		Link* pNewLink = new Link(dd);
		if(isEmpty())
			pLast = pNewLink;
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	void insertLast(double dd)
	{
		Link* pNewLink = new Link(dd);
		if(isEmpty())
			pFirst = pNewLink;
		else
			pLast->pNext = pNewLink;
		pLast = pNewLink;
	}

	double removeFirst()
	{
		Link* pTemp = pFirst;
		double temp = pFirst->dData;
		if(pFirst->pNext == NULL)
			pLast = NULL;
		pFirst = pFirst->pNext;
		delete pTemp;
		return temp;
	}

	void displayList()
	{
		cout << "List (first-->last): ";
		Link* pCurrent = pFirst;
		while(pCurrent != NULL)
		{
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
};

class LinkQueue
{
private:
	FirstLastList theList;

public:
	bool isEmpty()
	{ return theList.isEmpty();}

	void insert(double j)
	{ theList.insertLast(j);}

	double remove()
	{ return theList.removeFirst(); }

	void displayQueue()
	{
		cout << "Queue (front-->rear):";
		theList.displayList();
	}
};

int main()
{
	return 0;
}
