#include <iostream>
#include "Link.cpp"

// page 178

using namespace std;

class LinkedList
{
private:
	Link* pFirst;

public:
	LinkedList():pFirst(NULL){}

	bool isEmpty() { return pFirst == NULL; }

	void insertFirst(int id, double dd)
	{
		Link* pNewLink = new Link(id,dd);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	Link* getFirst()
	{
		return pFirst;
	}

	void removeFirst()
	{
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		delete pTemp;
	}

	void displayList()
	{
		cout << "List (first --> last):";
		Link* pCurrent = pFirst;			// start at beginning of list
		while(pCurrent != NULL)
		{
			pCurrent->displayLink();		// print data
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
};

int main()
{
	LinkedList theList;
	
	theList.insertFirst(22,2.99);
	theList.insertFirst(44,4.99);
	theList.insertFirst(66,6.99);
	theList.insertFirst(88,8.99);

	theList.displayList();

	return 0;
}

