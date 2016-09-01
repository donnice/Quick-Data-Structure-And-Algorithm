// #include <iostream>
// page 456
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class DataItem
{
public:
	int iData;
	
	DataItem(int ii):iData(ii){}	// constructor
};

class HashTable
{
private:
	vector<DataItem*> hashArray;
	int arraySize;
	DataItem* pNonItem;				// deleted items

public:
	HashTable(int size):arraySize(size)
	{
		hashArray.resize(arraySize);	// size vector
		for(int j = 0; j < arraySize; j++)
			hashArray[j] = NULL;
		pNonItem = new DataItem(-1);	// deleted item key is -1
	}

	void displayTable()
	{
		cout << "Table: ";
		for(int j = 0; j < arraySize; j++)
		{
			if(hashArray[j]!=NULL)
				cout << hashArray[j]->iData << " ";
			else
				cout << "** ";
		}
		cout << endl;
	}

	int hashFunc(int key)
	{
		return key%arraySize;		// hash function
	}
};
