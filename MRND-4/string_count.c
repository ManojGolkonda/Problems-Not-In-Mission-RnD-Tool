#include<stdio.h>
#include<string.h>
struct testcases
{
	char in[200];
	char out[40];
}cases[] =
{
	{ "aabbccEEDDDDCC", "a2b2c2E2D4C2" },
	{ "aabbnnWWWKKHHHHeeell", "a2b2n2W3K2H4e3l2" },
	{ "aabbbcdeeefghh", "a2b3cde3fgh2" },
	{ "nnnnnnnnnnnnnnGGGhhhKKK", "n14G3h3k3" },//fails because of small k instead of K
	{ "mmmmmmmmmmmmmmmmmmmmmnnnnnooooooo", "m21n5o7" },
	{ "aaaabccccccccccccdddddddddddddddddd", "a4bc12d18" }
};
int digitExtract(int num, int *a)
{
	int i = 0, j;
	while (num)
	{
		j = num % 10;
		a[i++] = j;
		num = num / 10;
	}
	return i;
}
void charCount(char *in)
{
	int i = 0, k, j = 0;
	char ch;
	while (in[i] != '\0')
	{
		ch = in[i];
		int count = 0;
		k = i;
		while (ch == in[k])
		{
			count++;
			k++;
		}
		if (count == 1)
			in[j++] = in[i];
		if (count > 1 && count < 10)
		{
			in[j++] = in[i];
			in[j++] = (char)(count + 48);
		}
		else if (count > 9)
		{
			int a[10], m, n, var = 0;
			in[j++] = in[i];
			m = count;
			var = digitExtract(count, a);
			for (m = var - 1; m >= 0; m--)
				in[j++] = (char)(a[m] + 48);
		}
		i += count;
	}
	in[j] = '\0';
}
void check_result(char *a, char *b)
{
	/*int i = 0;
	while (a[i] != '\0')
	{
	if (a[i] != b[i])
	return 0;
	i++;
	}
	if (a[i] == b[i])
	return 1;
	else 0;
	*/
	printf("%s\t%s\t", a, b);
	if (strcmp(a, b))
		printf("FAIL\n");
	else
		printf("PASS\n");
}
int main()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		charCount(cases[i].in);
		check_result(cases[i].in, cases[i].out);
		/*if (check_result(cases[i].in, cases[i].out))
		printf("PASS\n");
		else
		printf("FAIL\n"); */
	}
	getchar();
	return 0;
}