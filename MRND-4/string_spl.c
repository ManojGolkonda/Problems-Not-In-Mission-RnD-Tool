#include<stdio.h>
struct testcases
{
	char input[30];
	char expected_op[30];
	int expected_length;
}tests[] =
{
	{ "abc$A~AB-$EC", "abcAABEC", 8 },
	{ "x(y)z@W9N*P", "xyzWNP", 6 },
	{ "", "", 0 },
	{ "a", "a", 1 },
	{ "7575775", "", 0 },
	{ "abc45ds54d554ssd", "abcdsdssd", 10 },
	{ "-=!*@&%^@", "", 0 },
	{ "knsc()nj", "AJHBHB", 6 },	//this testcase will fail
};
void delete_spl(char*);
int check_result(char*, char*);
int main()
{
	int i;
	for (i = 0; i < 8; i++)
	{
		delete_spl(tests[i].input);
		if (check_result(tests[i].input, tests[i].expected_op))
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
	return 0;
}
void delete_spl(char* s)
{
	int i = 0, j = 0;
	while (s[i] != '\0')
	{
		if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')))
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}
int check_result(char* a, char* b)
{
	int i = 0;
	while (b[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			return 0;
	}
	return 1;
}