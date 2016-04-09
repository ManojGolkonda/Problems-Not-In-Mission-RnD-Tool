#include<stdio.h>
struct TestCases
{
	char a[1000];
	char b[1000];
	int expected_result;
} tests[] = {
	{ "AwBzCc", "YaZdAg", 1 },	//isomorphic string having the combination of both sets and repeating pattern in a circular fashion
	{ "mmm", "nnn", 1 },		//for isomorphic strings of same length
	{ "aBcDfFj", "xPzRcTg", 1 },//for isomorphism with unequal spacing i.e lowercase series difference is increasing by 1 in each step (1,2,3,..), uppercase series having same constant difference (1,1,1,..) :)
	{ "acb", "mno", 0 },		//for all lower case non-isomorphic strings
	{ "dCbA", "zYxW", 1 },		//for isomorphic with decreasing fashion
	{ "aBDcF", "kCEmG", 1 },	//for isomorphic strings having the combination of both lower and uppercase letters
	{ "acbd", "wyx", 0 },		//for strings of non-equal 
	{ "X", "m", 0 },			//for single element non-isomorphic strings of same length
	{ "-hjg", "6546", 0 },		//for invalid input
	{ "$0)(", "%234", 0 },		//for special characters
	{ "", "", 1 },				//for both null strings
	{ "a B", "c D",0 }			//for strings having spaces
};
int strLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int areIsoMorphic(char *a, char *b)		//it checks for the isomorphism of two given strings by assuming a-z is one set and A-Z is another set only
{
	printf("%s  %s  ", a, b);
	int i = 0;
	int len1 = strLength(a);		//length of 1st string
	int len2 = strLength(b);		//length of 2nd string
	char before1_a = 0;				//using to store the 1st string's previous elements of set-1
	char before1_b = 0;				//using to store the 2nd string's previous elements of set-1
	char before2_a = 0;				//using to store the 1st string's previous elements of set-2
	char before2_b = 0;				//using to store the 2nd string's previous elements of set-2
	if (len1 != len2)
		return 0;
	else
	{
		while (a[i] != '\0' && ((a[i] <= 'Z' && b[i] <= 'Z' && a[i] >= 'A' && b[i] >= 'A') || (a[i] >= 'a' && b[i] >= 'a' && a[i] <= 'z' && b[i] <= 'z')))
		{					//if letters at the corresponding indices of two strings belongs to same set
			if ((a[i] <= 'Z' && b[i] <= 'Z'))	//for uppercase series
			{
				if (before1_a)			//if having any previous value then checking for pattern
				{
					if (!((before1_a - a[i] + 26) % 26 == (before1_b - b[i] + 26) % 26))
						break;
					i++;
				}
				else					//if not having any previous element then storing the current element
				{
					before1_a = a[i];
					before1_b = b[i];
					i++;
				}
			}
			else					//for lowercase series
			{
				if (before2_a)
				{
					if (!((before2_a - a[i] + 26) % 26 == (before2_b - b[i] + 26) % 26))
						break;
					i++;
				}
				else
				{
					before2_a = a[i];
					before2_b = b[i];
					i++;
				}
			}
		}
		if (i == len1)	//means all the elements in the array are following the pattern
			return 1;
		else
			return 0;
	}
}
void checkResult(int i, int j)
{
	if (i == j)
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i, result;
	for (i = 0; i < 12; i++)
	{
		result = areIsoMorphic(tests[i].a, tests[i].b);
		checkResult(result, tests[i].expected_result);
	}
	getchar();
	return 0;
}