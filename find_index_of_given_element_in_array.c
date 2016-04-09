
/*
This program will find the index if the given key in the given array.
It will return -1 if key element is not found in array.
*/
#include<stdio.h>
struct TestCases
{
	int input_array[100];
	int array_length;
	int key_element;
	int expected_output;
}test[5] = {
	{ { 2, 5, 4, 6, 7 }, 5, 4, 2 },
	{ { 5, 3, 0, 6, 12, 13, 9 }, 7, 13, 5 },
	{ { 9, 4, 2, 8, }, 4, 5, -1 },
	{ { 23, 56, 45, 76, 21, 0 }, 6, 0, 5 },
	{ { 78, 34, -45, -23, 67 }, 5, -45, 2 }
};
int find(int *[], int, int);
int main(void)
{
	int i, result;
	for (i = 0; i < 5; i++)
	{

		result = find(test[i].input_array, test[i].array_length, test[i].key_element);
		if (test[i].expected_output == result)
			printf("pass\n");
		else
			printf("fail\n");
	}
	return 0;
}
int find(int a[100], int length, int key)
{
	int i;
	for (i = 0; i < length; i++)
	if (a[i] == key)
		return i;
	return -1;
}