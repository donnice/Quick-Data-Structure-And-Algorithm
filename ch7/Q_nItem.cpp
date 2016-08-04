class Queue
{
private:
	int maxSize;
	vector<int> queVect;
	int front;
	int rear;

public:
	Queue(int s):maxSize(s+1),front(0),rear(-1)
	{
		queVect.resize(maxSize);
	}

	void insert(int j)
	{
		if(rear == maxSize - 1)
			rear = -1;
		queVect[++rear] = j;
	}

	int remove()
	{
		int temp = queVect[front++];
		if(front == maxSize)
			front = 0;
		return temp;
	}

	int peek()
	{
		return queVect[front];
	}

	bool isEmpty()
	{
		return(rear+1 == front || (front+maxSize-1 == rear));
		// front-------------------------rear
	}
	
	bool isFull()
	{
		return(rear+2 == front || (front+maxSize-2 == rear));
		// ---rear|front-------------- | must be sth
		// because when it's empty, ----rearfront-------
	}

	int size()
	{
		if(rear>=front)
			return rear-front+1;
		else
			return (maxSize-front)+(rear+1);
	}
	
};
