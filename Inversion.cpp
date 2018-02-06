// Author: Damien Sudol
// Program: Homework 3
// Version: 1.0

// Description: Algorithm utilizes the divide and conquer paradigm to order
// an array of integers while tracking all inversions found in the original
// array. Algorithm's efficiency is O(nlogn).
//
// Assumptions: While maintaining O(nlogn) it is preferable to sort the array
// as well as count inversions. If ONLY counting inversions without altering
// the order of the array is the desired functionality a copy of the array
// should be passed to the CountInversions(int[], int) method.

#include <iostream>
using namespace std;

int Divide(int A[], int tempArr[], int low, int high);
int Conquer(int A[], int tempArr[], int low, int mid, int high);
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
	int tempArr[n];
return Divide(A, tempArr, 0, (n-1));
}

int Divide(int A[], int tempArr[], int low, int high)
{
	int mid = 0;
	int inversionCount = 0;
		if(low <  high)
		{
			mid = (low+high)/2;
			inversionCount =  Divide(A, tempArr, low, mid);
			inversionCount += Divide(A, tempArr, mid+1, high);
			inversionCount += Conquer(A, tempArr, low, mid+1, high);
		}
return inversionCount;
}

int Conquer(int A[], int tempArr[], int low, int mid, int high)
{
	int i, j, k;
	int inversionCount = 0;

	i = low;
	j = mid;
	k = low;
	
	while((i<= mid -1) && (j<= high))
	{
		if(A[i] <= A[j])
			tempArr[k++] = A[i++];
		else
		{
			tempArr[k++] = A[j++];
			inversionCount+=  (mid-i);
		}
	}
	while(i < mid)
		tempArr[k++] = A[i++];
	
	while(j <= high)
		tempArr[k++] = A[j++];

	for(i=low; i<= high; i++)
		A[i] = tempArr[i];
return inversionCount;
}
