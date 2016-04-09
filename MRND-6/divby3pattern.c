#include<stdio.h>
struct TestCases
{
	char p[100];
	int k;
	int result;
} tests[] =
{
	{ "1239876", 3, 1 },		//positive number divisible by 3
	{ "11111", 13, 0 },			//positive number not divisible by 3
	{ "9999", 5, 1 },
	{ "-123321", 5, 1 },		//negative number divisible by 3
	{ "-1221", 21, 1 },
	{ "-98976698", 10, 0 },		//negative number not divisible by 3
	{ "99875756", 0, 1 },		//positive number repeating zero number of times
	{ "-7687616", 0, 1 }		//negative number repeating zero number of times
};
int isDivBy3_1(char *p, int k)		//handles only when the sum is less than the max int value
{
	unsigned int i, sum = 0;
	while (k--)
	{
		i = 0;
		if (p[0] < '0')
			i = 1;
		while (p[i] != '\0')
			sum += p[i++] - '0';
	}
	if (sum % 3 == 0)
		return 1;
	return 0;
}
int isDivBy3_2(char *p,int k)		//handles number of any length repeating any number of times
{
	int i, sum = 0;
	while (k--)
	{
		i = 0;
		if (p[0] < '0')			//if number is negative then processing the number from next index value i.e 1
			i = 1;
		while (p[i] != '\0')
		{
			sum += p[i++] - '0';	//calculating sum of integers
			sum %= 3;				//decrementing the value of sum
		}
	}
	if (sum % 3)
		return 0;
	return 1;
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
	for (i = 0; i < 8; i++)
	{
		result = isDivBy3_2(tests[i].p, tests[i].k);
		checkResult(result, tests[i].result);
	}
	getchar();
	return 0;
}