#include<stdio.h>
struct testcases
{
	int a[20];
	int length;
	int expected_array1[20], expected_array2[20];
} tests[5] = {/*in this test cases some may result in both ascending and descending order those cases also handled*/
	{ { 2, 8, 6, 4, 10 }, 5, { 2, 4, 6, 8, 10 }, { 10, 8, 6, 4, 2 } }, //for both cases
	{ { 6, 9, 15, 42, 35 }, 5, { 6, 9, 15, 35, 42 } }, //only ascending
	{ { 3, 13, 9, 24 }, 4, { 3, 9, 13, 24 }, { 24, 13, 9, 3 } }, //for both
	{ { 1, 6, 3, 4, 5, 2, 7 }, 7, { 1, 2, 3, 4, 5, 6, 7 } }, //only ascending
	{ { 45, 33, 19, 29 }, 4, { 45, 33, 29, 19 } } //only descending
};
void sort_mis(int*, int,int);
void check_result(int *, int*, int);
int check_result1(int *, int*, int);
void sortForAscending(int *, int);
void sortForDescending(int *, int);
int main()
{
	int i;
	for (i = 0; i < 5; i++)
		sort_mis(tests[i].a, tests[i].length,i);
	getchar();
	return 0;
}
void sort_mis(int* arr, int n,int i)
{
	int asc_count = 0, desc_count = 0,j;
	int flag1 = 1, flag2 = 1;
	for (j = 0; j < n - 1; j++)
	{
		if (arr[j] < arr[j + 1])
			asc_count++;
		else
			desc_count++;
	}
	if (asc_count>desc_count)
	{
		sortForAscending(arr, n);
		check_result(arr, tests[i].expected_array1, n);
	}
	else if (asc_count < desc_count)
	{
		sortForDescending(arr, n);
		check_result(arr, tests[i].expected_array1, n);
	}
	else
	{
		int ar[20];
		for (j = 0; j < n; j++)
			ar[j] = arr[j];
		sortForAscending(arr, n);
		if (!check_result1(arr, tests[i].expected_array1, n))
			flag1 = 0;
		sortForDescending(ar, n);
		if (!check_result1(ar, tests[i].expected_array2, n))
			flag2 = 0;
		if (flag1 == 1 && flag2 == 1)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
}
void check_result(int* a, int* b, int n)
{
	int i;
	for (i = 0; i < n; i++)
	if (a[i] != b[i])
		break;
	if (i < n)
		printf("FAIL\n");
	else
		printf("PASS\n");
}
int check_result1(int* a, int* b, int n)
{
	int i;
	for (i = 0; i < n; i++)
	if (a[i] != b[i])
		return 0;
	return 1;
}
void sortForAscending(int *arr, int length)
{
	int i, mis1 = -1, mis2 = -1, temp;
	for (i = 0; i < length - 1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			if (mis1 == -1)
				mis1 = i;
			else
			{
				mis2 = i + 1;
				break;
			}
		}
	}
	if (mis2 == -1)
		mis2 = mis1 + 1;
	temp = arr[mis1];
	arr[mis1] = arr[mis2];
	arr[mis2] = temp;
}
void sortForDescending(int *arr, int length)
{
	int i, mis1 = -1, mis2 = -1, temp;
	for (i = 0; i < length - 1; i++)
	{
		if (arr[i]<arr[i + 1])
		{
			if (mis1 == -1)
				mis1 = i;
			else
			{
				mis2 = i + 1;
				break;
			}
		}
	}
	if (mis2 == -1)
		mis2 = mis1 + 1;
	temp = arr[mis1];
	arr[mis1] = arr[mis2];
	arr[mis2] = temp;
}