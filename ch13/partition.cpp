// partition.cpp
// page 283
#include <iostream>
#include <vector>
#include <cstdlib>		// for random numbers
#include <ctime>		// for random numbers
using namespace std;

class ArrayPar
{
private:
	vector<double> theVect;
	int nElems;

public:
	ArrayPar(int max):nElems(0)
	{
		theVect.resize(max);
	}

	void insert(double value)
	{
		theVect[nElems] = value;
		nElems++;
	}

	int getSize()
	{ return nElems; }

	void display()
	{
		cout << "A=";
		for(int j = 0; j < nElems; j++)
			cout << theVect[j] << " ";
		cout << endl;
	}

	int partitionIt(int left, int right, double pivot)
	{
		int leftMark = left - 1;
		int rightMark = right + 1;
		while(true)
		{
			while(leftMark < right && theVect[++leftMark] < pivot) ;
			while(rightMark > left && theVect[--rightMark] > pivot) ;

			if(leftMark >= rightMark)
				break;
			else
				swap(leftMark,rightMark);

			return leftMark;
		}
	}

	void swap(int dex1, int dex2)
	{
		double temp;
		temp = theVect[dex1];
		theVect[dex1] = theVect[dex2];
		theVect[dex2] = temp;
	}
};

int main()
{
	time_t aTime;
	int maxSize = 16;
	ArrayPar arr(maxSize);

	for(int j = 0; j < maxSize; j++)
	{
		double n = rand()%199;
		arr.insert(n);
	}
	arr.display();

	double pivot = 99;
	int size = arr.getSize();

	int partDex = arr.partitionIt(0,size-1,pivot);
	cout << "PartDex is at:" << partDex << endl;
	arr.display();

	return 0;
}
