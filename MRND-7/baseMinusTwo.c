#include<stdio.h>
struct TestCases
{
	int number;
	char result[50];
	int number_of_bits;
} tests[]=
{
	{ 9, "11001", 5 },
	{ 100, "110100100", 9 },
	{ 123, "110001111", 9 },
	{ 43, "1111111", 7 },
	{ 999, "10000111011", 11 },
	{ 9876, "111101110010100", 15 },
	{ -69, "11001111", 8 },
	{ 32767, "11000000000000011",17 },		//for max int value 
	{ -32768, "1000000000000000",16 },		//for min int value
	{ 0, 0, 1 },
	{ 1, 1, 1 }
};
char* toBaseMinus2(int n)
{
	//printf("%d  ", n);
	int i = 0, r, j;
	char temp;
	static char a[50];
	if (n == 0 )
	{
		a[0] = '0' + n;
		a[1] = '\0';
		return a;
	}
	while (n != 0)
	{
		r = n % 2;		//equvalent to dividing with -2 when remainder is not -1;
		n = -(n / 2);	//dividing with -2
		if (r < 0)
		{
			r += 2;		//if remainder is -1 then making it as 1
			n += 1;		//because of we increased the remainder by 2 means we are multiplying one more time by 2 so increasing the resulting num by 1
		}
		a[i++] = '0'+r;	//storing result in a char array
	}
	a[i] = '\0';
	for (j = 0, i = i - 1; j < i; j++, i--)		//reversing to get original input
	{
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
	return a;
}
void checkResult(char *a, char *b, int len)
{
	//printf("%s  %s  ", a, b);
	int i = 0;
	while (b[i] != '\0' && a[i]!='\0')
	{
		if (a[i] != b[i])
			break;
		i++;
	}
	if (i == len)			//cross checking the length of output with expected length of output
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i;
	char *result;
	for (i = 0; i < 11; i++)
	{
		result = toBaseMinus2(tests[i].number);
		checkResult(tests[i].result, result, tests[i].number_of_bits);
	}
	getchar();
	return 0;
}