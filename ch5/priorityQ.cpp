#include <iostream>
#include <vector>
// page 164
using namespace std;

class PriorityQ
{
private:
	int maxSize;
	vector<double> queVect;
	int nItems;

public:
	PriorityQ(int s):maxSize(s),nItems(0)
	{
		queVect.resize(maxSize);
	}

	void insert(double item)
	{
		int j;

		if(nItems == 0)
			queVect[nItems++] = item;
		else
		{
			for(j=nItems-1; j>=0;j--)
			{
				if(item > queVect[j])
					queVect[j+1] = queVect[j];
				else
					break;
			}
			queVect[j+1] = item;
			nItems++;
		}
	}

	// actually 50,40,30,20,10

	double remove()
	{
		return queVect[--nItems];
	}

	double peekMin()
	{
		return queVect[nItems-1];
	}

	bool isEmpty()
	{
		return (nItems == 0);
	}

	bool isFull()
	{
		return (nItems == maxSize);
	}
};

int main()
{
	PriorityQ thePQ(5);

	thePQ.insert(30);
	thePQ.insert(50);
	thePQ.insert(10);
	thePQ.insert(40);
	thePQ.insert(20);

	while(!thePQ.isEmpty())
	{
		double item = thePQ.remove();
		cout << item << " ";
	} // end while
	cout << endl;

	return 0;
}
