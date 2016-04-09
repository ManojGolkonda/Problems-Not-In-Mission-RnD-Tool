#include<stdio.h>
struct testcases
{
	int number;
	int expected_result;
} test[5] = {
	{ 121, 1 },
	{ 120, 0 },
	{ 1331, 1 },
	{ -121, 1 },
	{ 0, 1 }
};
int isDivisible(int);
int main()
{
	int result,i;
	for(i=0;i<5;i++)
	{
		result = isDivisible(test[i].number);
		if(result == test[i].expected_result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	return 0;
}
int isDivisible(int n) //it checks whether the number is divisible by 11 or not
{
	int temp,temp1,i=0,j=0;
	if(n>0)
		temp = n;
	else
		temp = -n;
while(temp>0)
	{
		temp1=temp/10;
		temp1=(temp-temp1*10);
		temp=temp/10;
		i+=temp1;
		temp1=temp/10;
		temp1=(temp-temp1*10);
		temp=temp/10;
		j+=temp1;
	}
	if(i-j)
		return 0;
	else
		return 1;
}