// lowArray.cpp
// demostrates array class with low-level interface
// page 63
#include <iostream>
#include <vector>
using namespace std;

class LowArray
{
private:
	vector<double> v;			// vector holds doubles

public:
	LowArray(int max)
	{
		v.resize(max);
	}

	void setElem(int index, double value)
	{
		v[index] = value;
	}

	double getElem(int index)
	{
		return v[index];
	}

};

int main()
{
	LowArray arr(100);
	int nElems = 0;					// number of items
	int j;

	arr.setElem(0,77);
	arr.setElem(1,99);
	arr.setElem(2,44);
	arr.setElem(3,55);
	arr.setElem(4,22);
	arr.setElem(5,88);
	arr.setElem(6,11);
	arr.setElem(7,100);
	arr.setElem(8,66);
	arr.setElem(9,33);
	nElems = 10;

	for(j = 0; j < nElems; j++)
		cout << arr.getElem(j) << " ";
	cout << endl;

	int searchKey = 26;
	for(j=0;j<nElems;j++)
		if(arr.getElem(j) == searchKey)
			break;
	if(j == nElems)
		cout << "Cannot find "<<searchKey << endl;
	else
		cout << "Found!" << searchKey << endl;
	
	double deleteKey = 33;
	cout << "Deleting element " << deleteKey << endl;
	for(j = 0; j<nElems; j++)
		if(arr.getElem(j) == deleteKey)
			break;
	for(int k = j; k < nElems; k++)
		arr.setElem(k, arr.getElem(k+1));
	nElems--;

	for(j=0;j < nElems; j++)
		cout << arr.getElem(j) << " ";
	cout << endl;

	cout << arr.getElem(nElems) << " see anything?";
	
	return 0;
}
