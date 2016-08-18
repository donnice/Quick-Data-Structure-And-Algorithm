// page 261
#include <iostream>
using namespace std;

void doTowers(int topN,char src,char inter,char dest)
{
	if(topN == 1)
		cout << "Disk 1 from " << src << " to " << dest << endl;
	else
	{
		doTowers(topN-1,src,dest,inter);		// src to inter

		cout << "Disk " << topN
			<< " from " << src << " to " << dest << endl;

		doTowers(topN - 1, inter, src, dest);	// inter to dest
	}
}

int main()
{
	int nDisks = 5;
	doTowers(nDisks, 'A','B','C');

	return 0;
}

