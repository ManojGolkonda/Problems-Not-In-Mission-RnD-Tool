struct testCases
{
	int array[20];
	int length;
	int element;
	int expected_array[20];
} test[4] = {
	{ { 2, 3, 6, 7 }, 4, 5, { 2, 3, 5, 6, 7 } },
	{ { 1, 3, 8, 9, 12 }, 5, 9, { 1, 3, 8, 9, 9, 12 } },
	{ { -13, -4, 0, 4, 5, 10 }, 6, 4, { -13, -4, 0, 4, 4, 5, 10 } },
	{ { -21, -9, -2, 0, 10 }, 5, -2, { -21, -9, -2, -2, 0, 10 } }
};
void insertElement(int*, int*, int);
void checkResult(int*,int, int*);
int main()
{
	for (int i = 0; i < 4; i++)
	{
		insertElement(test[i].array, test[i].length, test[i].element);
		checkResult(test[i].expected_array, test[i].length, test[i].array);
	}
}
void insertElement(int* arr, int* n, int key) //this insert the given integer element into a sorted integer array assuming that the repetitions are allowed
{
	int i=0;
	while (i < n)
	{
		if (arr[i] < key)
			i++;
		else
			break;
	}
	if (i < n)
	{
		int temp = n;
		while (temp>i)
		{
			arr[temp] = arr[temp - 1];
			temp--;
		}
	}
	arr[i] = key;
	n=n+1;
	return arr;
}
void checkResult(int* arr, int length, int* result) //this check the result after insertion
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (arr[i] != result[i])
			break;
	}
	if (i == length)
		printf("PASS\n");
	else
		printf("FAIL\n");
}