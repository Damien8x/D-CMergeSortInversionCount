#include <iostream>
using namespace std;

int mergeSort(int A[], int temp[], int low, int high);
int merge(int A[], int temp[], int low, int mid, int high);
int CountInversions(int A[], int n);


int main()
{


	int A[]{1,3,5,2,4,6};

	int n = sizeof(A) / sizeof(int);

	cout << "Original Array: ";
		for(int i = 0; i < n; i++)
			cout << A[i] << " ";
		

	cout << "\nNumber of inversions: " << CountInversions(A, n) << endl;
	cout << "Sorted Array: ";

		for(int i = 0; i < n ; i++){
			cout << A[i] << " ";
			if(i == (n-1))
				cout <<  "\n";
		}

return 0;
}



int CountInversions(int A[], int n)
{
	int temp[n];
return mergeSort(A, temp, 0, (n-1));
}

int mergeSort(int A[], int temp[], int low, int high)
{
	int mid = 0;
	int invCount = 0;
		if(low <  high)
		{
			mid = (low+high)/2;
			invCount =  mergeSort(A, temp, low, mid);
			invCount += mergeSort(A, temp, mid+1, high);
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
			temp[k++] = A[i++];
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
