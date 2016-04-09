#include <stdio.h>

void multiply(int * a, int * b, int alen, int blen) {
	char bin[321];
	int i =0, j=0 ,n;
	while (i < alen)
	{
		n = a[i];
		while (n)
		{
			bin[j] = '0'+(n % 2);
			n /= 2;
			j++;
		}
		while (j%32)
		{
			bin[j++] = '0';
		}
		i++;
	}
	bin[j] = 0;
	printf("%s", bin);
}

int main() {
	unsigned int a[] = { 1,3 }, b[] = { 898 };
	multiply(a, b, 2, 1);
	getchar();
}