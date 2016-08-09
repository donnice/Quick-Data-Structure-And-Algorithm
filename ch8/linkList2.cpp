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

	}
}
