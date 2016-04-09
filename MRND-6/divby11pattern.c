#include<stdio.h>
struct TestCases
{
	char p[100];
	int k;
	int result;
} tests[] = 
{
	{ "123", 3, 0 },
	{ "1234567895", 100, 1 },
	{ "111", 13, 0 },
	{ "111", 22, 1 },
	{ "9", 5, 0 },
	{ "9", 10, 1 },
	{ "-123", 5, 0 },
	{ "-1221",21,1 },
	{ "-9", 10, 1 },
	{ "-9", 5, 0 }
};
int isDivBy11_1(char *p, int k)
{
	/*
	if (p[0]<'0')
		return -1;
		*/
	int i, sum = 0, count = 1;
	while (k--)
	{
		i = 0;
		if (p[0] < '0')
			i = 1;
		while (p[i]!='\0')
		{
			if (count % 2)
			{
				sum += p[i++] - '0';
				count++;
			}
			else
			{
				sum -= p[i++] - '0';
				count++;
			}
		}
	}
	if (sum)
		return 0;
	return 1;
}
int isDivBy11_2(char *p, int k)
{
	/*
	if (p[0]<'0')
		return -1;
		*/
	unsigned int i, even_sum = 0, odd_sum = 0, count = 1;
	while (k--)
	{
		i = 0;
		if (p[0] < '0')
			i = 1;
		while ((p[i] != '\0') && (p[i + 1] != '\0'))
		{
			if (count % 2)
			{
				even_sum += p[i++] - '0';
				odd_sum += p[i++] - '0';
			}
			else
			{
				odd_sum += p[i++] - '0';
				even_sum += p[i++] - '0';
			}
		}
		if (p[i] != '\0')
		{
			if (count % 2)
				even_sum += p[i] - '0';
			else
				odd_sum += p[i++] - '0';
			count++;
		}
	}
	if (even_sum == odd_sum)
		return 1;
	return 0;
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
	int i = 0, result;
	for (i = 0; i < 10; i++)
	{
		result = isDivBy11_2(tests[i].p, tests[i].k);
		checkResult(result, tests[i].result);
	}
	getchar();
	return 0;
}