#include<stdio.h>
#include<stdlib.h>
struct TestCases
{
	int a[1000];		//input array in sorted order
	int length;			//length of input array
	int key;			//key element that we need to search for
	int k;				//no. of times that we need to rotate
	int falg;			//the direction in which we have to rotate
	int expected_result;//index of the number after rotation
} tests[] = {
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, 11, 8, 6, 1, 2 },				//when rotating in clock-wise direction
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, 11, 8, 3, 0, 4 },				//when rotating in anti clock-wise direction
	{ { 1 }, 1, 1, 1, 1, 0 },												//only one element in input
	{ { 23, 45 }, 2, 45, 33, 1, 0 },										//only two elements
	{ { -43, -34, -12, 0, 12, 14, 18, 19 }, 8, 0, 5, 1, 0 },				//negative numbers in input
	{ { 7, 8, 9, 9, 10, 10, 10, 11, 11, 14, 19 }, 11, 10, 4, 0, 1 },		//duplicates in input array
	{ { 34, 46, 97, 123, 264, 335, 446,536 }, 8, 143, 6, 1, -1 },			//element not found situation
	{ { 71, 73, 79, 83 }, 4, 71, 25, 1, 1 },								//no. of elements greater than no. of elements :)
	{{ 9, 9, 9, 9, 9, 9, 9, 9, 9 }, 9, 5, 8, 1, -1}							//for all elements having same value
};
void rotate(int *a, int n, int k, int flag)			//rotates the given array by k positions based on the flag value.if flag is 1 clockwise direction else anti-clockwise direction
{
	k = k%n;			//if no.of rotations greater than or equal to the no.of elements :)
	if (!k)
		return;
	int *temp,i,j;
	temp = (int*)calloc(k, sizeof(int));
	if (flag)					//for clockwise direction
	{
		for (i = n - k, j = 0; i < n, j < k; i++, j++)	//storing the elements that are need to be place at the starting
			temp[j] = a[i];
		for (j = n - 1, i = j - k; i >= 0; i--, j--)	//moving the elements by k
			a[j] = a[i];
		for (i = 0; i < k; i++)							//placing the elements at the begining
			a[i] = temp[i];
	}
	else						//for anti-clockwise direction
	{
		for (i = 0; i < k; i++)						//storing the elements that need to be placed at the ending
			temp[i] = a[i];
		for (j = 0; i < n; i++, j++)				//moving elements by k
			a[j] = a[i];
		for (i = 0; j < n; i++, j++)				//placing the k elements at the end
			a[j] = temp[i];
	}
	free(temp);
//	for (i = 0; i < n; i++)
//		printf("%d  ", a[i]);
//	printf("\n");
}
int binarySearch(int *a, int n, int key)
{
	int i = 0, j = n - 1, m = (i + j) / 2;
	if (!(a[i] < a[j]))							//if the array is rotated, we are finding the two portions and also find in which part of array we have to search for the element
	{
		while (i != j)							//finding the index position seperating the two sorted arrays after rotation
		{
			m = (i + j) / 2;
			//	printf("bf: i:%d j:%d  m:%d\n", i, j, m);
			if (a[i] < a[m])						//means i to m is sorted
				i = m;
			else									//means m to j is sorted
				j = m;
			//	printf("af: i:%d j:%d  m:%d\n", i, j, m);
		}
		if (a[0] <= key && a[m] >= key)			//selecting the array range in which we have to search for the element
			i = 0;
		else
			j = n - 1;
	}
	while (i != j )								//searching for the element using binary search
	{
		m = (i + j) / 2;
	//		printf("bf: i:%d j:%d  m:%d\n", i, j, m);
		if (a[m] > key)
			j = m;
		else if (a[m] < key)
			i = m;
		else
			return m;
	//		printf("af: i:%d j:%d  m:%d\n", i, j, m);
			if (j - i == 1 && i==m)						//the element is not found but the loop is iterating e.g i=2,j=3 the loop will never end as m=2 :)
				break;									//stopping process at this time
	}
	if (n == 1)		//handles for length one
	{
		if (a[0] == key)
			return 0;
	}
	else
	if (n == 2)
	{
		if (a[0] == key)
			return 0;
		if (a[1] == key)
			return 1;
	}
	return -1;
}
void checkResult(int i, int j)
{
//	printf("%d  %d  ", i, j);
	if (i == j)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i, result;
	for (i = 0; i < 9; i++)
	{
		rotate(tests[i].a, tests[i].length, tests[i].k, tests[i].falg);
		result = binarySearch(tests[i].a, tests[i].length,tests[i].key);
		checkResult(result, tests[i].expected_result);
	}
	getchar();
	return 0;
}