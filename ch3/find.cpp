int find(double searchKey)
{
	int lowerBound = 0;
	int upperBound = nElems-1;
	int curIn;

	while(true)
	{
		curIn = (lowerBound + upperBound)/2;
		if(v[vurIn] == searchKey)
			return curIn;
		else if(lowerBound > upperBound)
			return nElems;						// cannot find
		else
		{
			if(v[curIn] < searchKey)
				lowerBound = curIn+1;
			else
				upperBound = curIn - 1;
		}
	}
}
