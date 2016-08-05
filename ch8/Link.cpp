using namespace std;

class Link
{
public:
	int iData;				// data item
	double dData;			// data item
	Link* pNext;			// ptr to next link in list

	Link(int id, double dd):// constructor
		iData(id),dData(dd),pNext(NULL){}
	
	void displayLink()
	{
		cout << "{" << iData << "," << dData << "}";
	}
};
