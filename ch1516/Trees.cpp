// page 330
#include <iostream>
#include <stack>
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
		switch(traverseType)
		{
		case 1: 
			cout << "\nPreorder traversal: ";
			preOrder(pRoot);
			break;
		case 2:
			cout << "\nInorder traversal: ";
			break;
		case 3:
			cout << "\nPostorder traversal: ";
			postOrder(pRoot);
			break;
		}
		cout << endl;
	}

	void preOrder(Node* pLocalRoot)
	{
		if(pLocalRoot !=NULL)
		{
			cout << pLocalRoot ->iData << " ";	// displayNode
			preOrder(pLocalRoot->pLeftChild);	// left
			preOrder(pLocalRoot->pRightChild);	// right
		}
	}

	void inOrder(Node* pLocalRoot)
	{
		if(pLocalRoot != NULL)
		{
			inOrder(pLocalRoot->pLeftChild);	// left child
			cout << pLocalRoot->iData << " ";	// displayNode
			inOrder(pLocalRoot->pRightChild);	// right child
		}
	}

	void postOrder(Node* pLocalRoot)
	{
		if(pLocalRoot != NULL)
		{
			postOrder(pLocalRoot->pLeftChild);	// left child
			postOrder(pLocalRoot->pRightChild);	// right child
			cout << pLocalRoot->iData << " ";	// display node
		}
	}

	void displayTree()
	{
		stack<Node*> globalStack;
		globalStack.push(pRoot);
		int nBlanks = 32;
		bool isRowEmpty = false;

		cout <<
		"......................................";
		cout << endl;
		while(isRowEmpty == false)
		{
			stack<Node*> localStack;
			isRowEmpty = true;
		}
	}

	void destroy()
	{ destroyRec(pRoot); }

	void destroyRec(Node* pLocalRoot)
	{
		if(pLocalRoot != NULL)
		{
			destroyRec(pLocalRoot->pLeftChild);		// left subtree
			destroyRec(pLocalRoot->pRightChild);	// right subtree
			delete pLocalRoot;
		}
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
