// page 117

template<typename T)
void insertionSort(T arr[], int len)
{
	int i,j;
	T temp;
	for(i = 1; i < len; i++)
	{
		temp = arr[i];
		for(j = i-1; j>=0 && arr[j]>temp;j--)
			arr[j+1] = arr[j];
		a[j+1] = temp;
	}
}
