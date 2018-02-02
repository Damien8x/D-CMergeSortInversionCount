#include <iostream>
using namespace std;

int _mergeSort(int A[], int temp[], int low, int high);
int merge(int A[], int temp[], int low, int mid, int high);
int mergeSort(int A[], int n);


int main()
{
int n = 5;

int A[]{1,3,5,2,7};

cout << mergeSort(A, n) << endl;


return 0;
}


int mergeSort(int A[], int n)
{
	int temp[n];
	//	int *temp = (int *)malloc(sizeof(int)*n);
	return _mergeSort(A, temp, 0, (n-1));
}

int _mergeSort(int A[], int temp[], int low, int high)
{
	int mid = 0;
	int invCount = 0;

	if(low > high)
	{
	mid = (low+high)/2;
	invCount = _mergeSort(A, temp, low, mid);
	invCount += _mergeSort(A, temp, mid+1, high);

	invCount += merge(A, temp, low, mid+1, high);

	
	}
	return invCount;
}

int merge(int A[], int temp[], int low, int mid, int high)
{
	int i, j, k;
	int invCount = 0;

	i = low;
	j = mid;
	k = low;
	
	while((i<= mid -1) && (j<= high))
	{
	if(A[i] <= A[j])
	{
		temp[k++] = A[i++];
	}
	else
	{
		temp[k++] = A[j++];

		invCount+=  (mid-i);
	}
	}
	while(i <= mid-1)
		temp[k++] = A[i++];
	
	while(j<= high)
		temp[k++] = A[j++];

	for(i=low; i<= high; i++)
		A[i] = temp[i];

	return invCount;
	
}
