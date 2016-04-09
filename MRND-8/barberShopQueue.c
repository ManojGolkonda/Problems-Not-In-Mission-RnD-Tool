#include<stdio.h>
#include<stdlib.h>
struct TestCases
{
	int time[1000];				//array consisting of time required by n barbers to process one customer
	int no_of_barbers;			
	int custmer_num_in_queue;	//the position of the customer in the queue
	int expected_shop_number;	//the shop to which the customer will go
} tests[] = {
	{ { 10, 3, 15, 5 }, 4, 7, 2 },									//all barbers having different times
	{ { 123, 1242, 3234, 22, 34, 24, 543, 5432, 245 }, 9, 100, 6 },	//somewhat large service times
	{ { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }, 10, 123, 3 },		//if all barbers having same service time
	{ { 13 }, 1, 142, 1 },											//if only one barber is there
	{ { 6, 13, 9, 10, 15 }, 5, 1, 1 },								//if only one customer is there
	{ { 0 }, 0, 15, -1 },											//if no barber is available	
	{ { 10, 12, 9, 16 }, 4, 0, -1 }									//if no customer is available
};
int minTime(int a[], int n)		//returns index of minimum value in given array
{
	int min_index = 0, i;
	for (i = 0; i < n; i++)
	{
		if (a[i] < a[min_index])
			min_index = i;
	}
	return min_index;
}
int findShop(int *a, int n, int k)
{
	if (!n || !k)		//if no barber or no customer is there
		return -1;
	if (n == 1 || k == 1)	//if only one customer or one barber is there
		return 1;
	int *temp, i = 0, j;
	temp = (int*)calloc(n, sizeof(int));	//it used to store after how much time the shop will be empty
	while (i < k)							//iterates for every customer and finds which shop he will go
	{
		j = minTime(temp, n);				//finding the shop that is going to be empty next
		temp[j] += a[j];					//incrementing the value of temp by the time required to process one customer by that specific barber
		i++;
//printf("i:%d  j:%d temp[j]:%d\n", i, j, temp[j]);
	}
	free(temp);
	return j + 1;
}
void checkResult(int a, int b)
{
//	printf("%d  %d  ", a, b);
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i, result;
	for (i = 0; i < 7; i++)
	{
		result = findShop(tests[i].time, tests[i].no_of_barbers, tests[i].custmer_num_in_queue);
		checkResult(result, tests[i].expected_shop_number);
	}
	getchar();
	return 0;
}