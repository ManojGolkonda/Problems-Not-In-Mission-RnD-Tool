
/*
This program will find and return the index of the 1st occurance of a given key element in the given array
Assuming that the array is sorted and duplicates may allowed.
*/


#include<stdio.h>
struct TestCases
{
	int input_array[100];
	int array_length;
	int key_element;
	int expected_output;
}test[3] = {
	{ { 2, 3, 4, 6, 7 }, 5, 4, 2 },
	{ { 0, 2, 6, 6, 12, 13, 17 }, 7, 6, 2 },
	{ { 1, 4, 6, 8, }, 4, 5, -1 }
};
int find1(int *, int, int);
int main(void)
{
	int i, result;
	for (i = 0; i < 3; i++)
	{

		result = find1(test[i].input_array, test[i].array_length, test[i].key_element);
		if (test[i].expected_output == result)
			printf("pass\n");
		else
			printf("fail\n");
	}
	return 0;
}
int find1(int a[], int length, int key)
{
	int first, last, mid;
	first = 0;
	last = length - 1;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (a[mid]<key)
			first = mid + 1;
		else if (a[mid]>key)
			last = mid - 1;
		else        //finds the occurance of key element
		{
			while (a[mid - 1] == a[mid])     //finds the 1st occurance of key element
				mid--;
			return mid;
		}
	}
	return -1;
}