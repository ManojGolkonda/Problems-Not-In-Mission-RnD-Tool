#include<stdio.h>
struct TestCases
{
	char binary[3000];
	char octal[1000];
} tests[]=
{
	{ "10011010101010", "23252" },
	{ "100111100110", "4746" },
	{ "0", "0" },
	{ "1","1" },
	{ "111", "7" },
	{ "1000", "10" },
	{ "1111001100010000001111001011100011110100010001101010100000000000000000000", "1714201713436421524000000" },
	{ "11110011101101001101011011001111011101010101100110010", "363551533173525462" },
	{ "1110000110001001100100110000101000101001", "16061144605051" }
};
int stringLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int stringCompare(char *a, char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	if (b[i] != '\0')
		return 0;
	return 1;
}
char* toOctal(char *binary)
{
	//printf("%s  ", binary);
	int len = stringLength(binary), i = len -1, j;
	static char octal[1000];
	if (len % 3)
		j = (len / 3) + 1;
	else
		j = len / 3;
	octal[j] = '\0';
	j--;
	while (i - 1 > 0 && j >= 0)			//i is index of binary number and j is index of octal number
	{									//here we are processing input only when having atleast 3 bits remaining in the input
		octal[j] = '0' + ((1 * binary[i] - '0') + (2 * (binary[i - 1] - '0')) + (4 * (binary[i - 2] - '0')));
		j--;
		i -= 3;
	}
	if (i)						//means we have two elements in input to process
		octal[j] = '0' + (1 * (binary[i] - '0')) + (2 * (binary[i - 1] - '0'));
	else						//only one element in input 
		if (i==0)
			octal[j] = '0' + (1 * (binary[i] - '0'));
	return octal;
}
void checkResult(char *a, char *b)
{
	//printf("%s  %s  ", a, b);
	if (stringCompare(a, b))
		printf("PASS\n");
	else
		printf("FAIL\n");
}
int main()
{
	int i;
	char *result;
	for (i = 0; i < 9; i++)
	{
		result = toOctal(tests[i].binary);
		checkResult(result, tests[i].octal);
	}
	getchar();
	return 0;
}