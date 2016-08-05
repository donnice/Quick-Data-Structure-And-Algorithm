#include "Link.cpp"

class LinkedList
{
private:
	Link* pFirst;

public:
	LinkedList:pFirst(NULL){}

	bool isEmpty()
	{
		return pFirst == NULL;
	}
};
