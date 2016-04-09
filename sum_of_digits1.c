#include<stdio.h>
struct testcases
{
	int number;
	int expected_result;

	{25,7},
	{123,6},
	{8976,30}.
	{0,0}
};
int getSum(int);
int main()
{
	int i,result;
	for (i = 0; i < 4; i++)
	{
		result = getSum(test[i].number);
		if (result == expected_result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
}
int getSum(int n)
{
	int sum = 0;
	unsigned int temp = n;
	while (temp > 0)
	{
		sum += temp % 10;
		temp = temp / 10;
	}
	return sum;
}