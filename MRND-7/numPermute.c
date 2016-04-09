#include<stdio.h>
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void sort(int *a, int n)
{
	int i, j, temp;
	for (i = 0; i<n;i++)
	for (j = 0; j<n - i - 1; j++)
	if (a[j]>a[j + 1])
		swap(&a[j], &a[j + 1]);
}
void permute(int *a, int i, int j)
{
	int k = 0;;
	if (i == j)
	{
		for (k = 0; k < j + 1; k++)
			printf("%d", a[k]);
		printf("\n");
	}
	else
	{
		for (k = i; k <= j; k++)
		{
			swap(&a[i], &a[k]);
			permute(a, i + 1, j);
			swap(&a[i], &a[k]);
		}
	}  
}
void numPermute(unsigned int n)
{                             
	unsigned int a[8], i = 0;
	while (n > 0)
	{
		a[i++] = n % 10;
		n /= 10;
	}
	sort(a, i);
	permute(a, 0, i - 1);
}
int main()
{
	numPermute(23564198);
	getchar();
	return 0;
}