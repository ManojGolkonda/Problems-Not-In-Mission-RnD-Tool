#include<stdio.h>
struct testcases
{
	int n, minrank;
} tests[] = 
{
	{ 1234, 0 }
};
int numsLessThan(int a[10], int key, int len)
{
	int i, less = 0;
	for (i = 0; i<len; i++)
	if (a[i]<key)
		less++;
	return less;
}
int fact(int n)
{
	int fact = 1;
	while (n)
		fact *= n--;
	return fact;
}
int findMinRank(int a[10], int len)
{
	int rank = 0, i = len - 1;
	if (len == 1)
		return 0;
	rank += (numsLessThan(a, a[i], len)*fact(len - 1)) + findMinRank(a, len - 1);
	return rank;
}
int find(int n)
{
	int a[10], temp = n, i = 0, len;
	while (temp)
	{
		a[i++] = temp % 10;
		temp /= 10;
	}
	len = i;
	return findMinRank(a, len);
}
void checkResult(int a, int b)
{
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int min_rank,i;
	for (i = 0; i < 1; i++)
	{
		min_rank = find(tests[i].n);
		checkResult(min_rank, tests[i].minrank);
	}
	return 0;
	getchar();
	getchar();
}