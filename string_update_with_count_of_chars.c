#include<stdio.h>
#include<string.h>
struct testcases
{
	char input[30];
	char expected_op[30];
}tests[] =
{
	{ "aabbccEEDDDDCC", "a2b2c2E2D4C2" },
	{ "aabbnnWWWKKHHHHeeell", "a2b2n2W3K2H4e3l2" },
	{ "aabbbcdeeefghh", "a2b3cde3fgh2" },
	{"nnnnnnnnnnnnnnGGGhhhKKK","n14G3h3k3"}
};
void char_count(char*);
void check_result(char*, char*);
void get_first(char*,int*,int);
int main()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		char_count(tests[i].input);
		check_result(tests[i].input, tests[i].expected_op);
	}
	getchar();
	return 0;
}
void char_count(char* in)
{
	int i = 0, j = 0, count = 1, a[10], n, x, k;
	while (in[i + 1] != '\0')
	{
		if (((in[i] >= 'A') && (in[i] <= 'Z')) || ((in[i] >= 'a') && (in[i] <= 'z')))
		{
			if (in[i] == in[i + 1])
			{
				count++;
			}
			else if (count>1 && count<10)
			{
				in[j] = in[i];
				in[j + 1] = count + '0';
				j = j + 2;
				count = 1;
			}
			else if (count==1)
			{
			in[j] = in[i];
			j++;
			count = 1;
			}
			else
			{
				printf("%d\n", count);
				in[j] = in[i];
				j++;
				//int a[10];
				x = 0, n = count;
				while (n  > 0)
				{
					n = n / 10;
					x++;
				}
				//return i;
				k = x;
				n = count;
				while (x > 0)
				{
					a[x-1] == n % 10;
					n = n / 10;
					x--;
				}
				for (x = 0; x < k; x++)
				{
					in[j++] == a[x] + '0';
					printf("%d ", a[x]);
				}
				count = 1;
			}
		}
		i++;
	}
	in[j] = in[i];
	in[j + 1] = count + '0';
	j = j + 2;
	in[j] = '\0';
}
void check_result(char* a, char* b)
{
	printf("%s\t%s\t", a, b);
	if (strcmp(a, b))
		printf("FAIL\n");
	else
		printf("PASS\n");
}
/*
void get_first(char* c, int* j, int n1)
{
	int a[10];
	int i = 0, n = n1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	//return i;
	int k = i;
	while (i >= 0)
	{
		a[i] == n1 % 10;
		n1 = n1 / 10;
		i--;
	}
	for (i = 0; i <= k; i++)
		c[j] == a[i] + '0';
}
*/