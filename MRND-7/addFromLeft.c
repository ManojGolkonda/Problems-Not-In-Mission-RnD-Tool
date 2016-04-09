#include <stdio.h>
struct TestCases 
{
	char number1[101], number2[100], result[101];
} tests[] = 
{
	{"2456", "5668", "8124"},
	{"999", "997", "1996"},
	{"999", "111", "1110"},
	{"1410","1996","3406"}
};
char * addFromLeft(char * a, char * b) 
{
	printf("%s  %s  ", a, b);
	int i = 0, flag_9 = 0, j;
	char next, sum;
	next = b[0];
	b[0] = '0';
	while (next) 
	{
		sum = next + a[i] - '0';
		next = b[i + 1];
		if (sum > '9') 
		{
			b[i + 1] = sum - 10;
			for (j = i; j > flag_9; j--)		// making all 9s as 0s
				b[j] = '0';
			b[flag_9] += 1;						// incrementing value before 9s
			flag_9 = i + 1;
		}
		else if (sum < '9') 
		{
			b[i + 1] = sum;
			flag_9 = i + 1;
		}
		else
			b[i + 1] = '9';
		i++;
	}
	b[i + 1] = 0;
	if (b[0] == '0')
		return b + 1;
	return b;
}
int stringCompare(char *a, char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	if (b[i] != '\0')
		return 0;
	return 1;
}
void checkResult(char *a, char *b)
{
	printf("%s %s ", a, b);
	if (stringCompare(a, b))
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main() 
{
	int i;
	char *result;
	for (i = 0; i < 4; i++)
	{
		result = addFromLeft(tests[i].number1, tests[i].number2);
		checkResult(result, tests[i].result);
	}
	getchar();
	return 0;
}