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
		Node* pCurrent = pRoot;
		while(pCurrent->iData !=key)
		{
			if(key < pCurrent->iData)
				pCurrent = pCurrent->pLeftChild;
			else
				pCurrent = pCurrent->pRightChild;
			if(pCurrent == NULL)
				return NULL;
		}
		return pCurrent;
	}

	void insert(int id, double dd)
	{
		Node* pNewNode = new Node();
		pNewNode->iData = id;
		pNewNode->dData = dd;
		if(pRoot == NULL)
			pRoot = pNewNode;
		else
		{
			Node* pCurrent = pRoot;
			Node* pParent;
			while(true)
			{
				pParent = pCurrent;
				if(id < pCurrent -> iData)
				{
					pCurrent = pCurrent->pLeftChild;
					if(pCurrent == NULL)
					{
						pParent->pLeftChild = pNewNode;
						return;
					}
				}
				else
				{
					pCurrent = pCurrent->pRightChild;
					if(pCurrent == NULL)
					{
						pParent->pRightChild = pNewNode;
						return;
					}
				}
			}
		}
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