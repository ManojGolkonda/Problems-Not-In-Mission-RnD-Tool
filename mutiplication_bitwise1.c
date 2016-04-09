#include<stdio.h>
struct testcases
{
	int x, y, mul;
} tests[] =
{
	{ 13, 13, 169 },
	{ 9, 11, 99 },
	{ -5, -15, 75 },
	{ 0, 0, 0 },
	{ 0, 5, 0 },
	{ -5, 15, -75 },
	{ 5, -15, -75 }
};
int mul1(int x, int y) //here we are only using the y to calculate the multiplication value by iterating x times
{
	int m, n, a, b, i;
	if (x == 0 || y == 0)
		return 0;
	if (x<0 && y<0) //if both are negative then making both positive
	{
		x *= -1;
		y *= -1;
	}
	if (x<0 && y>0) //swapping x and y values to iterate y times
	{
		i = x;
		x = y;
		y = i;
	}
	m = y;
	n = y;
	for (i = 0; i < x - 1; i++) //x times multiplying y indirectly
	{
		do {        //
			a = y & m;
			b = y ^ m;
			y = a << 1;
			m = b;
		} while (a);
		y = b;
		m = n;
	}
	return b;
}
int mul2(int x, int y) //here we use x value to calculate and extra variable to store sign when one of the two numbers is negative
{
	int mul = 0, i = 1;
	if (x == 0 || y == 0)
		return 0;
	if (x<0 && y<0) //if both are negative then making both positive
	{
		x *= -1;
		y *= -1;
	}
	if (x<0 && y>0) //making both positive when x is negative and y is positive
	{
		i = -1;
		x *= -1;
	}
	if (x>0 && y<0) //making both positive when x is positive and y is negative
	{
		i = -1;
		y *= -1;
	}
	while (y != 0)               // Iterate the loop till y==0
	{
		if (y & 01)               // Logical ANDing of the value of y with 01
			mul += x; 				// Update the mul with the new value of x.
		x <<= 1;              // Left shifting the value contained in x by 1.
		y >>= 1;             // Right shifting the value contained in y by 1.
	}
	mul *= i;
	return mul;
}
void checkResult(int a, int b)
{
	printf("a: %d b: %d  ", a, b);
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i, mul;
	for (i = 0; i<7; i++)
	{
		mul = mul2(tests[i].x, tests[i].y);
		checkResult(mul, tests[i].mul);
	}
	return 0;
	//	 getchar();
}