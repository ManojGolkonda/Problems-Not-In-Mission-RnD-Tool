#include <stdio.h>

struct testcases {
	int arr[10000];
} cases[] = {
	{
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 90,100,199,226,235,16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0}
	}
};

int findN1(int * arr) {
	int i;
	for (i = 0;; i++)
		if (arr[i + 1] < arr[i])
			return i;
}

int findN2(int * a) {
	int n = 1;
	while (1) {
		if (a[n] > a[n + 1])
			return (n);
		else if (!a[n]) {
			n -= n / 4;
		}
		else
			n *= 2;
	}
}

void tester(int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d", findN2(cases[i].arr));
}

int main(void) {
	tester(1);
	getchar();
}