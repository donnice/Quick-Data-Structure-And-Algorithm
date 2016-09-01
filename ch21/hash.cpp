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
	
	// assume table is not full
	void insert(DataItem* pItem)	// insert a data item
	{
		int key = pItem->iData;			// extract key
		int hashVal = hashFunc(key);	// hash the key

		while(hashArray[hashVal] != NULL
		  &&  hashArray[hashVal]->iData != -1)
		{
			++hashVal;				// go to next cell
			hashVal %= arraySize;	// wrapround is necessary
		}
		hashArray[hashVal] = pItem;	// insert 
	}

	DataItem* remove(int key)
	{
		int hashVal = hashFunc(key);	// hash the key

		while(hashArray[hashVal]!=NULL)
		{
			int hashVal = hashFunc(key);	// hash the key

			while(hashArray[hashVal]!=NULL)
			{
				if(hashArray[hashVal]->iData == key)
				{
					DataItem* pTemp = hashArray[hashVal];
					hashArray[hashVal] = pNonItem;
					return pTemp;
				}
				++hashVal;
				hashVal%=arraySize;
			}
			return NULL;
		}
	}

	DataItem* find(int key)
	{
		int hashVal = hashFunc(key);

		while(hashArray[hashVal] != NULL)
		{
			if(hashArray[hashVal]->iData == key)
				return hashArray[hashVal];
			++hashVal;
			hashVal%=arraySize;
		}
		return NULL;
	}
};

int main()
{
	return 0;
}
