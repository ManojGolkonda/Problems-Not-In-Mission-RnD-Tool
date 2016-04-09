#include<stdio.h>
struct TestCases
{
	int a[1000];
	int length_a;
	int b[1000];
	int length_b;
	int c[1000];
	int length_c;
	int k;
} tests[] = {
	{ { 1, 2, 3, 4, 5 }, 5, { 2, 3, 4, 5, 6 }, 5, { 3, 4, 5, 6, 7 }, 5, 11 },			//for multiple combinations found
	{ { 8, -32, 67, 13 }, 4, { 19, -13, -7, 12, 78 }, 5, { -14, -31, 90, 45 }, 4, 40 },	//for negative numbers also
	{ { -10, 25, 25, 33, -10, 123, 32, 33 }, 8, { 35, 35, 44, 43, 21, 53, 35 }, 7, { 13, 14, 14, 13, 14 },5,73 },	//for repetition of numbers i.e. for duplicates
	{ { 10, 10, 20, 30 }, 4, { 20, 20, 30, 40 }, 4, { 30, 30, 40, 50 }, 4, 130 }		//no output combination found
};

void findSubsets1(int *a, int len_a, int *b, int len_b, int *c, int len_c,int target_sum)	 //it will be of time complexity O(len_a*len_b*len_c)
{
	int i, j, k;
	for (i = 0; i < len_a;i++)
		for (j = 0; j < len_b;j++)
			for (k = 0; k < len_c;k++)
				if (a[i] + b[j] + c[k] == target_sum)
					printf("a[%d] + b[%d] + c[%d] =(%d)+(%d)+(%d)= %d\n", i, j, k, a[i], b[j], c[k], target_sum);
	printf("\n");
}

void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L, *R;
	/* create temp arrays */
	L = (int*)calloc(n1, sizeof(int));
	R = (int*)calloc(n2, sizeof(int));
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the sub-array
of arr to be sorted */
void mergeSort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

void findSubsets2(int *a, int len_a, int *b, int len_b, int *c, int len_c, int target_sum)	//it will be of timcomplexity O(len_a*len_b*(log len_c))
{
	int i,j,k;
	mergeSort(c, 0, len_c - 1);		//sorting the 3rd array
	for (i = 0; i < len_a;i++)
		for (j = 0; j < len_b; j++)
		{
			k = binarySearch(c, 0, len_c - 1, target_sum - a[i] - b[j]);	//for every combination of i,j we get one k value which makes the desired sum
			if (k + 1)														//if any possible value found i.e k is other than 0
				printf("a[%d] + b[%d] + c[%d] =(%d)+(%d)+(%d)= %d\n", i, j, k, a[i], b[j], c[k], target_sum);
		}
		printf("\n");
}
int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("For TestCase-%d:\n", i + 1);
//		findSubsets1(tests[i].a, tests[i].length_a, tests[i].b, tests[i].length_b, tests[i].c, tests[i].length_c, tests[i].k);
		findSubsets2(tests[i].a, tests[i].length_a, tests[i].b, tests[i].length_b, tests[i].c, tests[i].length_c, tests[i].k);
	}
	getchar();
	return 0;
}