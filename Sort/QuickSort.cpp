//方法1

void  quickSort(int A[],int len)
{
	if(len<2)
		return;
	int j=0;
	int pivot = A[len-1];
	for(int i=0;i<len;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[j]);
			j++;
		}
	}

	quickSort(A,j-1);
	quickSort(A+j,len-j);
}

//方法2

void quickSort(int A[],int low,int high)
{
	if(low<high)
	{
		int pivotPos = Partition(A,low,high);
		quickSort(A,low,pivotpos-1);
		quickSort(A,pivotpos+1,high);
	}
}

//不用swap的方法
int Partition(int A[],int low ,int high)
{
	int pivot = A[low];
	while(low<high)
	{
		while(low<high && A[high]>= A[low]) high--;
		A[low] =A[high];
		while(low<high && A[low]<=A[high]) low++;
		A[high] = A[low];
	}

	A[low] = pivot;
	return low;
}
