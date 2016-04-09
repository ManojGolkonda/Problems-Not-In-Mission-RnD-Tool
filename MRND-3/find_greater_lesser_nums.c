#include<stdio.h>
struct testcases{
	int a[20];
	int length;
	int number;
	int expected_less;
	int expected_great;
}tests[4] = {
	{ { 4, 8, 2, 9, 12, 0, 13, 7 }, 8, 5, 3, 5 },
	{ { -24, 76, 45, 32, -21, 0, 13 }, 7, 13, 3, 3 },
	{ { 0, 4, 5, -89, 67, 96, 32, 45 }, 8, 50, 6, 2 },
	{ { 5, 5, 5, 5, 5 }, 5, 5, 0, 0 }
};
void find(int*, int, int, int);
int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		find(tests[i].a, tests[i].length, tests[i].number, i);
	}
	getchar();
	return 0;
}
void find(int* arr, int n,int key,int j)
{
	int i, less = 0, great = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] < key)
			less++;
		else if (arr[i] >key)
			great++;
		else
			continue;
	}
	if ((less == tests[j].expected_less) && (great == tests[j].expected_great))
		printf("PASS\n");
	else
		printf("FAIL\n");
}