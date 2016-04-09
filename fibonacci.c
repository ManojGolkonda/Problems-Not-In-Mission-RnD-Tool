#include<stdio.h>
struct testcases{
	int number;
	int expected_result;
}tests[6] = {{5,3},{2,1},{12,89},{18,1597},{0,-1},{-25,-1}};
int fibonacci(int);
//int fibonacci(float); handles if the given number is float
int main()
{
	int result,i;
	for(i=0;i<6;i++)
	{
		result = fibonacci(tests[i].number);
		if(result == tests[i].expected_result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	return 0;
}
int fibonacci(int n)
{
	int i,j,k,result; //i and j are used to store previous two numbers of fibonacci series
	if(n>0)
	{
		if(n<3)
			return n-1;
		else
		{
			for(i=0,j=1,result=0,k=0;k<n-2;k++)
			{
				result=i+j;
				i=j;
				j=result;
			}
			return result;
		}
	}
	return -1;
}
//handles if the given number is a float
/*
int fibonacci(float n)
{
    return -1;
}
*/
