#include<stdio.h>
struct testcases
{
	int array[30];
	int length;
	int expected_sum;
}tests[]=
{
	{ { 6, 2, 3, 6, 6, 4, 4, 2, 9 }, 9, 24 },
	{ { 12 }, 1, 12 },
	{ { -43, 43, 43, -43, 7, -43, 7, -7 }, 8, 0 },
	{{ 0, 23, 15, 22, 23, -100 }, 6, -40}
};
int isCompleted(int key, int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == key)
			return 1;
	}
	return 0;
}
int find_sum(int* a, int len)
{
	int sum = 0, i, temp[30], j = 0;
	for (i = 0; i < len; i++)
	{
		if (!(isCompleted(a[i], temp, j)))
		{
			sum += a[i];
			temp[j++] = a[i];
		}
	}
	return sum;
}
int find_sum1(int* a, int len)
{
	int sum = 0, i, j, count = 0;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < i; j++)
		if (a[j] == a[i])
		{
			count++;
			break;
		}
		if (count == 0)
			sum += a[i];
		count = 0;
	}
	return sum;
}
void sort(int* a, int len)
{
	int i, j,temp;
	for (i = 0; i < len;i++)
	for (j = 0; j < len;j++)
	if (a[i]>a[j])
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
int find_sum3(int* a, int len)
{
	int i, sum = 0, count = 0;
	sort(a, len);
	for (i = 0; i < len; i++)
	{
		if (count == 0)
			sum += a[i];
		else if (a[i]==)

		//printf("%d\t", a[i]);
	}
	//printf("\n");
}
void check_result(int a, int b)
{
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i,result;
	for (i = 0; i < 4; i++)
	{
		result = find_sum2(tests[i].array, tests[i].length);
		check_result(result, tests[i].expected_sum);
	}
	getchar();
	return 0;
}