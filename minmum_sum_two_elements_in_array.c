#include<stdio.h>
#include<limits.h>
struct testcases {
	int array[20];
	int length;
	int expected_result[2];
} test[7] = {
	{ { 8, 4, 9, 12, 0, -5, 25 }, 7, { -5, 0} },
	{ { 4, 2, 9, 45, 32, 22 }, 6, { 2, 4 } },
	{ { 43, 92, 125, 29, 13 }, 5, { 13, 29 } },
	{ { 99, 101, 98, -98 }, 4, { -98, 98 } },
	{ { 2 }, 1, { 0, 2} },
	{ { -5 }, 1, { -5, 0 } },
	{ { 8, 4 }, 2, { 4, 8} }
};
int* findMinSumElements(int* ,int);
void checkResult(int* ,int*);
int main()
{
	int *result,i;
	char ch;
	for(i=0; i<7; i++)
	{
		result = findMinSumElements(test[i].array,test[i].length);
		checkResult(test[i].expected_result,result);
	}
	ch = getChar();
	return 0;
}
int* findMinSumElements(int* arr ,int n)
{
	static int a[2];
	int *ptr_a, i = INT_MAX, j = INT_MAX, k, temp; //i is 1st min element and j is 2nd min element
	if(n>2)
	{
		for(k=0; k<n ;k++)
			if(	arr[k] < i)
			{
				j = i; //changing 1st minimun to 2nd
				i = arr[k]; //assigning new 1st minimum
			}
		a[0] = i;
		a[1] = j;
	}
	else if(n ==2 )
	{
		if( arr[0] < arr[1] )
		{
			a[0] = arr[0];
			a[1] = arr[1];
		}
		else
		{
			a[0] = arr[1];
			a[1] = arr[0];
		}
	}
	else
	{
		if(arr[0] >0)
		{
			a[0] = 0;
			a[1] = arr[0];
		}
		else
		{
			a[0] = arr[0];
			a[1] = 0;
		}
	}
	ptr_a = &a;
	return ptr_a;
}
void checkResult(int* a,int* b)
{
	if(a[0] == b[0] && a[1] == b[1])
		printf("PASS\n");
	else
		printf("FAIL\n");
}