#include<stdio.h>
struct testcases
{
	int number;
	int expected_result;

}test[5] = {
	
	{25,7},
	{123,6},
	{8976,30},
	{0,0},
	{-123,4}
};
int getSum(int);
int getSum1(int);
int main()
{
	int i,result;
	for (i = 0; i < 5; i++)
	{
		result = getSum1(test[i].number);
		if (result == test[i].expected_result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
//	getchar();
return 0;
}
int getSum(int n) //it considers both the positive and negative numbers as positive
{
	int sum = 0,temp;
	if(n>0)
		temp = n;
	else
		temp=-n;
	while (temp > 0)
	{
		sum += temp % 10;
		temp = temp / 10;
	}
	return sum;
}
int getSum1(int n) //it differentiate both positive and negative numbers
{
	int sum = 0,temp;
	if(n<0)
	{
		temp=-n;
		while(temp/10 > 0)
		{
			sum+=temp%10;
			temp = temp/10;
		}
		sum-=temp;
		return sum;
	}
	else{
		temp = n;
		while (temp > 0)
	{
		sum += temp % 10;
		temp = temp / 10;
	}
	return sum;
	}
}