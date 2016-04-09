#include <stdio.h>
struct TestCases
{
	unsigned int a[10];
	int length_a;
	unsigned int b[5];
	int length_b;
	unsigned int result[15];
	int length_result;
} tests[]=
{
	{ {5}, 1, {5}, 1, {25}, 1 },
	{ { 10, 15 }, 2, { 25 }, 1, {226,254}, 2 },
	{ { 87676576, 756576, 3455 }, 3,{ 56556798, 21453 } , 2, { 4276562688, 4294966447, 4294967295, 67108863}, 4 },
	{ { 87676576, 756576, 3455, 7866, 564566, 233423 }, 7, { 56556798,21453,24234,89867 }, 4, { 4276562688, 4294966447, 4294964181, 4294959605, 4294967295, 4294967295, 4294967295, 4294965247, 4294961919, 3 }, 10 },
	{ { 87676576, 756576, 3455, 7866, 564566, 233423, 56577, 756787, 23345, 64567 } ,10, { 56556798, 21453, 24234, 89867, 664656 }, 5, { 4276562688, 4294966447, 4294964181, 4294959605, 4294441903, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294967295, 4294965247, 4294932159, 4293911951, 9 }, 15 }
};
void add(char *result, char *a, int i, int len_a)
{
	int j, k, carry = 0;
	for (j = i, k = 0; j < i + len_a, k<len_a; j++, k++)
	{
		if (result[j] == '1' && a[i] == '1')
		{
			if (!carry)
			{
				result[j] = '0';
				carry = 1;
			}
		}
		else if ((result[j] == '0'&&a[k] == '1'))
		{
			if (!carry)
				result[j] = '1';
		}
		else if ((result[j] == '1'&&a[k] == '0'))
		{
			if (carry)
				result[j] = '0';
		}
		else
		{
			if (carry)
			{
				result[j] = '1';
				carry = 0;
			}
		}
	}
	if (carry)
		result[j] = '1';
}
char* binMultiply(char *a, int len_a, char *b, int len_b)
{
	static char bin_mul[481];
	int i, len_mul = len_a + len_b;
	for (i = 0; i < len_mul; i++)
		bin_mul[i] = '0';
	bin_mul[i] = '\0';
	i = 0;
	while (i<len_b)
	{
		if (b[i] == '1')
			add(bin_mul, a, i, len_a);
		i++;
	}
	//printf("%s\n", bin_mul);
	return bin_mul;
}
unsigned int* multiply(unsigned int *a, unsigned int *b, int alen, int blen) {
	char bin_a[321], bin_b[161], *bin_mul;
	static unsigned int result[15];
	int i = 0, j = 0, n,result_len=alen+blen;
	while (i < alen)
	{
		n = a[i];
		/*if (n == 0)
		{
			int temp = 0;
			while (temp<32)
				a[j++] = '0';
		}*/
		while (n)
		{
			bin_a[j] = '0' + (n % 2);
			n /= 2;
			j++;
		}
		while (j % 32)
		{
			bin_a[j++] = '0';
		}
		i++;
	}
	/*while (j < 320)
	{
	bin_a[j++] = '0';
	}*/
	bin_a[j] = '\0';
	i = 0;
	j = 0;
	while (i < blen)
	{
		n = b[i];
		/*if (n == 0)
		{
			int temp = 32;
			while (temp--)
				b[j++] = '0';
		}*/
		while (n)
		{
			bin_b[j] = '0' + (n % 2);
			n /= 2;
			j++;
		}
		while (j % 32)
		{
			bin_b[j++] = '0';
		}
		i++;
	}
	/*while (j < 160)
	{
	bin_b[j++] = '0';
	}*/
	bin_b[j] = '\0';
	//printf("%s\n%s\n", bin_a, bin_b);
	bin_mul = binMultiply(bin_a, alen * 32, bin_b, blen * 32);
	//printf("%s\n", bin_mul);
	for (i = 0,j=0; i < alen + blen; i++)
	{
		int temp = 1;
		result[i] = 0;
		do
		{
		if (bin_mul[j] == '1')
			result[i] += temp;
		temp *= 2;
		j++;
		} while (j%32);
	}
	/*
	for (i = 0; i < alen + blen; i++)
		printf("%d  ", result[i]);
	printf("\n");*/
	return result;
}
void checkResult(unsigned int *a, unsigned int *b,int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] != b[i])
			break;
	if (i == n)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main() 
{
	int i;
	unsigned int *result;
	for (i = 0; i < 4; i++)
	{
		result = multiply(tests[i].a, tests[i].b,tests[i].length_a,tests[i].length_b);
		checkResult(result, tests[i].result, tests[i].length_result);
	}
	getchar();
	return 0;
}