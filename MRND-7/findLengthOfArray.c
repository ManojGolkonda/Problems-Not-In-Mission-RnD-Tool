#include <stdio.h>
struct testcases
{
	int arr[10000];
	int expected_length;
} cases[] =
{
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 90, 100, 199, 226, 235, 16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },14 },
	{ { 3, 5, 7, 4, 0, 0 },2 },
	{ { 4, 5, 2, 0 },1 }
};
int findLength1(int *arr)			//linear way of doing with time complexity of O(n) 
{
	int i;
	for (i = 0;; i++)
		if (arr[i + 1] < arr[i])
			return i;
}
int findLength2(int *arr)			//exponentially incrementing to get length 
{
	int len = 1;
	while (1) {
		if (arr[len] > arr[len + 1])
			return (len);
		else if (!arr[len]) {
			len -= len / 4;
		}
		else
			len *= 2;
	}
}
void checkResult(int a, int b)
{
	printf("%d %d ", a, b);
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main() 
{
	int i,result;
	for (i = 0; i < 3; i++)
	{
		result = findLength2(cases[i].arr);
		checkResult(result, cases[i].expected_length);
	}
	getchar();
	return 0;
}