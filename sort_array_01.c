#include<stdio.h>
struct testcases
{
	int input_array[100];
	int length;
	int expected_output[100];
} tests[] = {
	{ { 0, 1, 1, 0 }, 4, { 0, 0, 1, 1 } },
	{ { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 }, 10, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 } },
	{ { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 }, 10, { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 } },
	{ { 0, 1, 0, 1, 0, 1, 0, 1, 0 }, 9, { 0, 0, 0, 0, 0, 1, 1, 1, 1 } },
	{ { 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 }, 11, { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 } },
	{ { 0, 0, 0, 0, 0 }, 5, { 0, 0, 0, 0, 0 } },
	{ { 1, 1, 1, 1, 1, 1 }, 6, { 1, 1, 1, 1, 1, 1 } }
};
void sort1(int *a, int n) //worst case logic with time complexity of n square
{
	int i, j,temp;
	for (i = 0; i < n;i++)
	for (j = 0; j<n; j++)
	if (a[i]>a[j])
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
void sort2(int *a, int n) //counting number of zeros and then modifying the array based on that
{
	int i, count = 0;
	for (i = 0; i < n;i++)
	if (a[i] == 0)
		count++;
	for (i = 0; i < count; i++)
		a[i] = 0;
	for (i = count; i < n; i++)
		a[i] = 1;
}
void sort3(int *a, int n) //counting number of 1's by caluculating the sum of the array and then modifying the array based on that
{
	int i, count = 0;
	for (i = 0; i < n; i++)
		count += a[i];
	for (i = 0; i < n - count; i++)
		a[i] = 0;
	for (; i < n; i++)
		a[i] = 1;
}
void sort4(int *a, int n)
{
	int i = 0, j = n, temp;
	for (i = 0; i < n; i++)
	if (a[i] == 1)
		break;
	for (j = n - 1; j >= 0; j--)
	if (a[j] == 0)
		break;
	while (i < j)
	{
		if (a[i] == 0)
			i++;
		else if (a[j] == 1)
			j--;
		else
		{
			a[i] = 1;
			a[j] = 0;
		}
	}
}
void sort5(int *a, int n) //using bubble sort
{
	int i, j;
	for (i = 0; i < n - 1;i++)
	for (j = 0; j < n - i - 1;j++)
	if (a[j]>a[j + 1])
	{
		a[j] = 0;
		a[j + 1] = 1;
	}
}
void check_results(int *a, int *b, int n)
{
	while (n--)
	{
		printf("%d : %d ,",a[n], b[n]);
		if (a[n] != b[n])
		{
			printf("FAIL\n");
			break;
		}
	}
	printf("\n");
	if (n==0)
	printf("PASS\n");
}
int main()
{
	int i;
	for (i = 0; i < 7; i++)
	{
		sort4(tests[i].input_array, tests[i].length);
		check_results(tests[i].input_array, tests[i].input_array, tests[i].length);
	}
	getchar();
	return 0;
}