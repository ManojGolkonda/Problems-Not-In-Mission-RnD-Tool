#include<stdio.h>
struct testcases
{
	int a[30];
	int length;
	int expected_result[2];
}tests[] =
{
	{ { 5, 2, -26, 7, 8, 9, -32, 1, 2 }, 9, { 3, 5 } },
	{ { -1, -4, -6, -7 }, 4, { 0, 0 } },
	{ { 2, 4, 5, 6, 7, 9, 2, 5 }, 8, { 0, 7 } },
	{ { 1, -2, -3, 5, 6, 7, 8, -20, -50 }, 9, { 3, 6 } },
	{ { -9, -44, 5, 12, 98, -23, 100 }, 7, { 2, 6 } },
	{ { 123, -45, 8, 23, -99 }, 5, { 0, 0 } }
};
/**
int findSum(int* a, int i, int j)
{
printf("i:%d j:%d  ", i, j);
int sum = 0, k;
while (i <= j)
sum += a[i++];
printf("sum:%d\n", sum);
return sum;
for (k=i; k <= j; k++)
sum += a[k];
return sum;

}
int* maxSeqSum(int* a, int len)
{
int max = 0, i = 0, j = 0, max1;
static int index[2] = { -1, -1 };
while (i < len)
{
if (a[j]>0)
j++;
else
{
max1 = findSum(a, i, j);
if (max1> max)
{
index[0] = i;
index[1] = j;
max = max1;
}
}
}

for (i = 0; i < len; i++)
{
for (j = i; j < len; j++)
{
max1 = findSum(a, i, j);
if (max>max1)
{
index[0] = i;
index[1] = j;
max = max1;
}
}
}
if ((index[0] == -1) && (index[1] == -1))
{
index[0] = 0;
index[1] = 0;
}
return index;
}*/
int* maxSubseq(int* input, int len) {
	int maxSum = 0, curentSum = 0, i = 0, start = 0, end = -1, j;
	static int index[2];
	for (j = 0; j < len; j++) {
		curentSum += input[j];
		if (curentSum < 0) {
			i = j + 1;
			curentSum = 0;
		}
		else if (curentSum > maxSum) {
			maxSum = curentSum;
			start = i;
			end = j;
		}
	}
	if (start <= end && start >= 0 && end >= 0) {
		index[0] = start;
		index[1] = end;
	}
	else
	{
		index[0] = 0;
		index[1] = 0;
	}
	return index;
}
void check_result(int* a, int* b)
{
	printf("%d\t%d\t%d\t%d\t", a[0], a[1], b[0], b[1]);
	if ((a[0] == b[0]) && (a[1] == b[1]))
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i;
	int* result;
	for (i = 0; i < 6; i++)
	{
		result = maxSubseq(tests[i].a, tests[i].length);
		check_result(result, tests[i].expected_result);
	}
	getchar();
	return 0;
}