struct testCases
{
	int array[20];
	int length;
	int element;
	int expected_array[20];
} test[2] = {
	{ { 2, 3, 6, 7 }, 4, 5, { 2, 3, 5, 6, 7 } },
	{ { 1, 3, 8, 9, 12 }, 5, 9, { 1, 3, 8, 9, 9, 12 } }
};
int* insertElement(int*, int, int);
void checkResult(int*,int, int*);
int main()
{
	int* a;
	for (int i = 0; i < 2; i++)
	{
		a = insertElement(test[i].array, test[i].length, test[i].element);
		checkResult(test[i].expected_array, test[i].length, a);
	}
	char ch = getChar();
}
int* insertElement(int* arr, int n, int key)
{
	int i=0;
	while (i < n)
	{
		if (arr[i] < key)
			continue;
		else
			break;
	}
	if (i < n)
	{
		int temp = n;
		while (i < temp)
		{
			arr[temp] = arr[temp - 1];
			temp--;
		}
	}
	arr[i] = key;
	return arr;
}
void checkResult(int* arr, int length, int* result)
{
	int i;
	for (i = 0; i <= length; i++)
	{
		if (arr[i] != result[i])
			break;
	}
	if (i == length)
		printf("PASS\n");
	else
		printf("FAIL\n");
}