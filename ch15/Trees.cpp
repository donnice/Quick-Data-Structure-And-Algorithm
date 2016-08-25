// page 330
#include <iostream>
#include "Node.cpp"

using namespace std;

class Tree
{
private:
	Node* pRoot;

public:						// constructor
	Tree():pRoot(NULL){}
	
	Node* find(int key)
	{
	
	}

	void insert(int id, double dd)
	{

	}

	void traverse(int traverseType)
	{

	}

	void displayTree()
	{

	}
};

int main()
{
	Tree theTree;
	
	theTree.insert(50,1.5);
	theTree.insert(25,1.7);
	theTree.insert(75,1.9);

	Node* found = theTree.find(25);		// find node with key 25
	if(found!=NULL)
		cout << "FOund the node with key 25" << endl;
	else
		cout << "Could not found!" << endl;
	return 0;
}
