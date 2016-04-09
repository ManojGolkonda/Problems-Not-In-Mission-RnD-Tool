#include<stdio.h>
struct TestCases
{
	unsigned int arr[1000],result;
} tests[] =
{
	{ { 2, 4, 5, 6, 7, 8, 5, 0, 0, 0, 0, 0 }, 5 }
};
int findLength(unsigned int *a)
{
	int i = 1, j = 1;
	while (1)
	{
		if (a[i] < a[i + 1])
			i *= 2;
		else
		{
			if (a[i]>a[i + 1] && a[i + 2] == 0)
				return i;
			if (a[i] == 0)
			{
				i /= 2;
				while (!(a[i]<a[i + 1] && a[i]>a[i - 1]))
				{
					j *= 2;
					i += (i / j);
				}
				return i;
			}
		}
	}
}
int main()
{
	int n;
	n = findLength(tests[0].arr);
	printf("%d", n);
	getchar();
	return 0;
}