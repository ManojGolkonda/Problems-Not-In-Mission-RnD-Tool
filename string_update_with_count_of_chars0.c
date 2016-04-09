#include<stdio.h>
#include<string.h>
struct testcases
{
	char input[30];
	char expected_op[30];
}tests[]=
{
	{ "aabbccEEDDDDCC", "a2b2c2E2D4C2" },
	{ "aabbnnWWWKKHHHHeeell", "a2b2n2W3K2H4e3l2" }
};
void char_count(char*);
void check_result(char*, char*);
int main()
{
	int i;
	for (i = 0; i < 2; i++)
	{
		char_count(tests[i].input);
		/*if (check_result(tests[i].input, tests[i].expected_op))
			printf("PASS\n");
		else
			printf("FAIL\n");
			*/
		check_result(tests[i].input, tests[i].expected_op);
	}
	getchar();
	return 0;
}
void char_count(char* in)
{
	int i = 0, j = 0, count = 1;
	//char c;
	while (in[i+1] != '\0')
	{
		if (((in[i] >= 'A') && (in[i] <= 'Z')) || ((in[i] >= 'a') && (in[i] <= 'z')))
		{
			if (in[i] == in[i + 1])
			{
				count++;
			}
			else/* if (count>1)*/
			{
				in[j] = in[i];
				in[j + 1] =count+'0';
				j = j+2;
				count = 1;
			}
			/*
			else
			{
				c = in[i + 1];
				in[j] = in[i];
				in[j + 1] = count + '0';
				j = j + 2;
				count = 1;
			}
			*/
		}
		i++;
	}
	in[j] = in[i];
	//count++;
	in[j + 1] = count + '0';
	j = j + 2;
	in[j] = '\0';
	printf("%s\t%s", in,tests[0].expected_op);
}
void check_result(char* a, char* b)
{
	/*
	int i = 0;
	while (b[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			return 0;
	}
	return 1;
	*/
	if (strcmp(a, b))
		printf("FAIL\n");
	else
		printf("PASS\n");
}