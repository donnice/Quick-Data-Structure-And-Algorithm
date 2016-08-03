#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
	int maxSize;
	vector<int> queVect;
	int front;
	int rear;
	int nItems;

public:
	Queue(int s):maxSize(s),front(0),rear(-1),nItems(0)
	{
		queVect.resize(maxSize);
	}

	void insert(int j)
	{
		if(rear == maxSize -1)
			rear = -1;					// wrap around
		queVect[++rear] = j;
		nItems++;
	}

	int remove()
	{
		int temp = queVect[front++];
		if(front == maxSize)
			front = 0;
		nItems --;
		return temp;
	}

	int peekFront()
	{ return queVect[front];}

	bool isEmpty()
	{ return (nItems == 0);	}

	bool isFull()
	{ return (nItems == maxSize); }

	int size()
	{ return nItems; }
};

int main()
{
	Queue theQueue(6);

	theQueue.insert(10);
	theQueue.insert(20);
	theQueue.insert(30);
	theQueue.insert(40);
	theQueue.insert(50);
	
	theQueue.remove();
	theQueue.remove();
	theQueue.remove();

	while(!theQueue.isEmpty())
	{
		int n = theQueue.remove();
		cout << n << " ";
	}
	cout << endl;

	return 0;
}
