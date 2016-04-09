#include<stdio.h>
struct testcases
{
	unsigned int x, y, a;
	int result;
} tests[] =
{
	{ 3, 7, 5, 2 },
	{ 23, 5, 7, 4 },
	{ 7, 31, 6, 1 },
	{ 321, 345, 71, 20 }, 
	{ 12345, 8765, 567, 324 },  //higher values of input
	{ 0, 23, 6, 0 },			//if x is zero 
	{ 23, 0, 6, 1 },			//if y is zero
	{ 6547, 876, 456, 1 },
	{ 23456, 2647, 0 ,-1}		//if a value is zero 
};
unsigned int pow_mod1(int a, int b, int k) //It will not work if the product value exceeds the limit of long long int
{											//worst case logic and will not work for bigger values
	long long int p=1;
	if (k <= 0 || a < 0 || b < 0)
		return -1;
	unsigned int i, result;
	if (a != 0)
	{
		for (i = 0; i < b; i++)
			p *= a;
		result = p % k ;
		return result;
	}
	return 0;
}
unsigned int pow_mod2(int a, int b, int k)  //somewhat better logic with time complexity of O(b)
{											//works fine for all cases
	unsigned int p = 1;
	if (k <= 0 || a < 0 || b < 0)
		return -1;
	if (b == 0)
		return 1 % k; //if power is zero
	if (a == 0)
		return 0;
	while (b)		//iterating b times
	{
		p *= a;		//multiplying with a 
		p %= k;		//decreasing value by performing mod with k in every step 
		b--;
	}
	return p;
}
unsigned int pow_mod3(int a, int b, int k) //here we are using an extra array to store the pattern in modulo values
{											//when we found pattern we stop doing the process and return value from array directly based on b value
	int arr[100], i = 1, p = 1;  //this may fail if pattern of modulus contain 100 or more values
	if (k <= 0 || a < 0 || b < 0)
		return -1;
	if (b == 0)
		return 1 % k;  //if power is zero
	if (a == 0)
		return 0;
	p *= a;
	p %= k;
	arr[0] = p;
	while (arr[0] != ((p*a) % k) && i<k )
	{
		p *= a;
		p %= k;
		arr[i] = p;
		i++;
	}
	if (i < k)
		return arr[(b%i) - 1];
	else
		return p;
}
unsigned int pow_mod4(int a, int b, int k) //best caes logic with time complexity of O(log b)
{						//here we are using the binary weighted computation i.e based on binary number at an index we are multiplying
	int p = 1, s;
	if (k <= 0 || a < 0 || b < 0)
		return -1;
	if (a == 0)
		return 0;
	if (b == 0)
		return 1 % k;
	s = a;				//initializing s with a and then using to store square of number for next iteration 
	while (b)
	{
		if (b % 2)		//checking whether the value can be multiplied or not if 0 we skip the value else multiply the product with previous sqaure value
			p = (p*s) % k;
		s = (s*s) % k;
		b /= 2;			 //decrementing b by half
	}
	return p;
}
void checkResult(unsigned int a, unsigned int b)
{
	//printf("a: %d  b: %d  ", a, b);
	if (a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
void main()
{
	unsigned int p, i;
	for (i = 0; i < 9; i++)
	{
		p = pow_mod4(tests[i].x, tests[i].y, tests[i].a);
		checkResult(p, tests[i].result);
	}
	//return 0;
	getchar();
}