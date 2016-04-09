#include<stdio.h>
struct testcases
{
	int a[20];
	int length;
	int expected_array[20];
} tests[4] = {
	{ { 1, 2, 0, 1, 2, 2, 0 }, 7, { 0, 0, 1, 1, 2, 2, 2 } },
	{ { 0, 2, 1, 0, 1, 0, 2, 0, 1 }, 9, { 0, 0, 0, 0, 1, 1, 1, 2, 2 } },
	{ { 0, 0, 0, 0, 0, 0, 0 }, 7, { 0, 0, 0, 0, 0, 0, 0 } },
	{ { 0, 2, 2, 2, 0, 1, 2, 1 }, 8, { 0, 0, 1, 1, 2, 2, 2, 2 } }
};
void sort(int*, int); //it sorts an integer array consisting of 0's,1's and 2's.If a number other than these is given in array it treat that as 2 only.
void sort1(int*, int);
void swap(int *, int *);

void check_result(int*, int*, int);
int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		sort1(tests[i].a, tests[i].length);
		check_result(tests[i].a, tests[i].expected_array, tests[i].length);
	}
	getchar();
	return 0;
}
void sort(int* arr, int n)//it sorts with a timecomplexity of 2n
{
	int i, c0=0,c1=0,c2=0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			c0++;
		else if (arr[i] == 1)
			c1++;
		else
			c2++;
	}
	for (i = 0; i < c0; i++)
		arr[i] = 0;
	for (; i < c0 + c1; i++)
		arr[i] = 1;
	for (; i < c0 + c1 + c2; i++)
		arr[i] = 2;
}
void sort1(int* a, int n)//it sorts with a timecomplexity if n
{
	int i, j, pos0 = 0, pos1 = 0, pos2 = n - 1;;
	for (int i = 0; i <= pos2;)
	{
		if (a[i] == 0){
			swap(a + i, a + pos1);
			i++;
			pos1++;
		}
		else if (a[i] == 2){
			if (a[pos2] == 2)
				pos2--;
			else
				swap(a + i, a + pos2);
		}
		else{
			i++;
		}
	}
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void check_result(int* a, int* b, int n)
{
	int i;
	for (i = 0; i < n;i++)
		if (a[i] != b[i])
			break;
		if (i < n)
			printf("FAIL\n");
		else
			printf("PASS\n");
}