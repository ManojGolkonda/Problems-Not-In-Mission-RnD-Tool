#include<stdio.h>

struct testcases
{
	int a[100];
	int length;
	int b[100];
} tests[] = 
{
	{ { 1, 2, 3, 4, 5 }, 5, { 120, 60, 40, 30, 24 } },
	{ { 6, 3, 0, 8, 9, 3, 4 }, 7, { 0, 0, 15552, 0, 0, 0, 0 } },				//having exactly one 0
	{ { 123, 67, 0, 78, 56, 0, 45, 86, 93 }, 9, { 0, 0, 0, 0, 0, 0, 0, 0, 0 } },	//having more than one 0's
	{ { 15, 14, 13, 12, 11 }, 5, { 24024, 25740, 27720, 30030, 32760 } },
	{ { 1, 2, 3, -4, 5 }, 5, { -120, -60, -40, 30, -24 } },				//when having odd number of negative values
	{ { 1, -2, 3, -4, 5 }, 5, { 120, -60, 40, -30, 24 } },				//having even number of negative values
	{ { 12, -11, 15, 0, 14, 13 }, 6, { 0, 0, 0, -360360, 0, 0 } }		//having more than one 0's and odd number of negative values
};
int* mulOthers1(int *a, int n)		//worst case logic with time complexity of O(n)
{
	static int b[100];
	int mul = 1, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n;j++)
		if (i != j)
			mul *= a[j];
		b[i] = mul;
		mul = 1;
	}
	return b;
}

int* mulOthers2(int *a, int n)		//better logic,handles all cases with time complexity of O(n)
{
	static int b[100];
	int m = 1, i, count = 0;
	for (i = 0; i<n; i++)
	if (a[i] != 0)
		m *= a[i];
	else
		count++;		//counts number of 0's in input array
	if (count == 0)		//no 0's then divide the product with the value at index
	{
		for (i = 0; i<n; i++)
			b[i] = m / a[i];
		return b;
	}
	else if (count == 1)	//if one zero then except zero value index, make all values as 0
	{
		for (i = 0; i<n; i++)
		if (a[i] == 0)
			b[i] = m;		//update with the product at 0 value's index
		else
			b[i] = 0;
		return b;
	}
	else					//if more than one 0's are there,then update all values with zero's and return result
	{
		for (i = 0; i<n; i++)
			b[i] = 0;
		return b;
	}
}

int* mulOthers3(int *a, int n)		//best case logic with time complexity of O(n)
{
	static int b[100];
	int mul = 1, i;
	b[n - 1] = 1;
	for (i = n - 2; i >= 0; i--)	//calculating the product of right side array
		b[i] = b[i + 1] * a[i + 1];
	for (i = 1; i < n; i++)			
	{
		mul *= a[i-1];				//calculating the product of left side array
		b[i] *= mul;				//updating the array with product of both left and right arrays
	}
	return b;
}

void checkResult(int *a, int *b, int n)
{
	int i, count = 0;
	//for (i = 0; i < n;i++)
		//printf("a: %d  b: %d\n", a[i], b[i]);
	for (i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			count++;
			break;
		}
	}
		if (count)
			printf("FAIL\n");
		else
			printf("PASS\n");
}

void main()
{
	int i,*b;
	for (i = 0; i < 7; i++)
	{
		b = mulOthers3(tests[i].a, tests[i].length);
		checkResult(b, tests[i].b, tests[i].length);
	}
	getchar();
}