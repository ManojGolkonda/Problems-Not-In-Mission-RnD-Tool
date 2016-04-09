#include<stdio.h>
struct testcases
{
	unsigned int x, y, a, result;
} tests[] = 
{
	{ 3, 7, 5, 2 },
	{ 23, 5, 7, 4 }
};
unsigned int pow_mod(int a, int b, int k)
{
	unsigned int p = 1;
	while (b)
	{
		p *= a;
		p %= k;
		b--;
	}
	return p;
}
void checkResult(unsigned int a, unsigned int b)
{
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	unsigned int p, i;
	for (i = 0; i < 2; i++)
	{
		p = pow_mod(tests[i].x, tests[i].x, tests[i].a);
		checkResult(p, tests[i].result);
	}
	return 0;
	getchar();
}