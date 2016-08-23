// page 306
// quickSort2.cpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class ArrayIns
{
private:
	vector<double> theVect;
	int nElems;

public:
	ArrayIns(int max):nElems(0)
	{
		theVect.resize(max);
	}

	void insert(double value)
	{
		theVect[nElems] = value;
		nElems++;
	}

	void display()
	{
		cout << "A=";
		for(int j = 0; j<nElems; j++)
			cout << theVect[j] << " ";
		cout << endl;
	}

	void quickSort()
	{
		recQuickSort(0,nElems-1);
	}

	void recQuickSort(int left, int right)
	{
		int size = right-left+1;
		if(size<=3)
			manualSort(left,right);
		else
		{
			double median = medianOf3(left,right);
			int partition = partitionIt(left,right,median);
			recQuickSort(left,partition-1);
			recQuickSort(partition+1,right);
		}
	}

	double medianOf3(int left,int right)
	{
		int center = (left+right)/2;

		if(theVect[left] > theVect[center])
			swap(left,center);

		if(theVect[left] > theVect[right])
			swap(left,right);
		
		if(theVect[center] > theVect[right])
			swap(center,right);

		swap(center,right-1);			// put pivot
		return theVect[right-1];
	}

	void swap(int dex1, int dex2)
	{
		double temp = theVect[dex1];
		theVect[dex1] = theVect[dex2];
		theVect[dex2] = temp;
	}

	int partitionIt(int left, int right, double pivot)
	{
		int leftMark = left;
		int rightMark = right-1;

		while(true)
		{	
			while(theVect[++leftMark] < pivot);		// find bigger
			while(theVect[--rightMark] > pivot);	// find smaller
			if(leftMark >= rightMark)
				break;
			else
				swap(leftMark, rightMark);
		}
		swap(leftMark,right-1);
		return leftMark;
	}

	void manualSort(int left, int right)
	{
		int size = right-left+1;
		if(size <= 1)
			return;
		if(size == 2)
		{
			if(theVect[left] > theVect[right])
				swap(left,right);
			return;
		}
		else // size == 3
		{
			if(theVect[left] > theVect[right-1])
				swap(left,right-1);	// left,center
			if(theVect[left] > theVect[right])
				swap(left,right);	// left,right
			if(theVect[right-1] > theVect[right])
				swap(right-1,right);
		}
	}
};

int main()
{
	return 0;
}
