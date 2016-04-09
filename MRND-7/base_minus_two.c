#include<stdio.h>
int div(int n)
{
	if (n > 0)
		return -(n / 2);
	if (n < 0)
		return (n / 2) + 1;
	return 0;
}
void baseMinusTwo( int n)
{
	//n =div(n);
	//printf("%d", n);
	//return;
	int a[10], i = 0, d;
	while (n != 1)
	{
		if (n == -1)
		{
			a[i++] = 1;
			a[i++] = 1;
			break;
		}
		d = div(n);
		a[i++] = n - (d*-2);
		n = d;
	}
	for (i=i-1; i >= 0; i--)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	baseMinusTwo(4);
	getchar();
	return 0;
}