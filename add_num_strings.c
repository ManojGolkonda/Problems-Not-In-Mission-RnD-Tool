#include<stdio.h>
struct TestCases
{
	char num1[1000], num2[1000], result[1000];
} test[] =
{
	{ "1234", "2345", "3579" },
	{ "897643", "1234", "898877" },					//length-1 greater than length-2
	{ "1894692", "65946598821", "65948493513" },	//length-2 greater than length-1
	{ "99", "11", "110" },							//equal lengths with extra carry in output
	{ "97046", "86175", "183221" },					//equal lengths with extra carry in output
	{ "85004", "56636", "141640" },
	{ "65946598821", "1894692", "65948493513" },
	{ "-1234", "87768", "Invalid Input" },			//invalid input when 1st num is negative
	{ "1234", "-9865", "Invalid Input" },			//invalid input when 2nd num is negative
	{ "-987909", "-89768", "Invalid Input" }		//invalid input when both nums are negative
};
int stringLength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
void swap(char **a, char **b)
{
	char *temp = *a;
	*a = *b;
	*b = temp;
}
char* addNumStrings1(char *a, char *b)			//processing the input from backwards using the lengths of given numbers i.e integer strings :)
{
	if (a[0] < '0' || b[0] < '0')				//handling negative number cases
	{
		a = "Invalid Input";
		return a;
	}
	int len1, len2, i, j, carry = 0, sum = 0;
	len1 = stringLength(a);
	len2 = stringLength(b);
	if (len1 < len2)		//swapping len1,len2 and a,b
	{
		i = len1;
		len1 = len2;
		len2 = i;
		swap(&a, &b);
	}
	for (i = len1 - 1, j = len2 - 1; j >= 0; i--, j--)
	{
		sum = (a[i] - '0') + (b[j] - '0') + carry;	//calculating the sum of two digits at same place including carry
		a[i] = '0' + sum % 10;							//replacing value in a[i] with the units value of sum
		carry = sum / 10;							//updating carry with new value
	}
	while (carry >0 && i >= 0)
	{
		sum = a[i] - '0' + carry;
		a[i] = '0' + sum % 10;
		carry = sum / 10;
		i--;
	}
	if (carry > 0)		//means still there is a carry value but no place in array a
	{					//moving elements of a towards right and putting carry at starting position
		a[len1 + 1] = '\0';
		for (i = len1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = '0' + carry;
	}
	return a;
}
void reverse(char *str)
{
	int i = 0, j = stringLength(str) - 1;
	char temp;
	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}
char* addNumStrings2(char *a, char *b)		//using reverse of the given numbers and using one of the given numbers to store result
{
	if (a[0] < '0' || b[0] < '0')
	{
		a = "Invalid Input";
		return a;
	}
	int i = 0, carry = 0, sum = 0;
//	printf("%s %s ", a, b);
	reverse(a);
	reverse(b);
//	printf("%s %s ", a, b);
	while (a[i] != '\0' && b[i] != '\0')
	{
		sum = (a[i] - '0') + (b[i] - '0') + carry;	//calculating sum of two digits at same place including carry
		a[i++] = '0' + (sum % 10);					//updating the value in 1st number
		carry = sum / 10;							//updating carry
	}
	if (a[i] != '\0' )		//means 1st array is not completed 
	{
		while (a[i] != '\0' && carry > 0)	//repeating the above procedure only with 1st array till there is no carry
		{
			sum = a[i] + carry;
			a[i++] = '0' + (sum % 10);
			carry = sum / 10;
		}
		while (a[i] != '\0')		//if there is no carry then moving i to the end as we storing the result in the a only :)
			i++;
	}
	else	//means 1st array is completed
	{
		while (b[i] != '\0' && carry > 0)	//repeating with 2nd array only till there is no carry
		{
			sum = b[i] + carry;
			a[i++] = '0' + (sum % 10);
			carry = sum / 10;
		}
		while (b[i] != '\0')		//if there is no carry then dumping values as it is from b to output array i.e a
			a[i] = b[i++];
	}
	if (carry > 0)				//even after completing both arrays still there is some carry so, adding carry at the end
		a[i++] = '0' + carry;
	a[i] = '\0';				//adding null character 
//	printf("%s ", a);
	reverse(a);					//reversing the a to get original output
//	printf("%s ", a);
	return a;
}
void checkResult(char *a, char *b)
{
//	printf("%s %s ", a, b);
	int i = 0, count = 0;
	while (a[i] != '\0')
	{
		if (a[i] != b[i])
		{
			count++;
			break;
		}
		i++;
	}
	if (count)
		printf("FAIL\n");
	else
		printf("PASS\n");
}
int main()
{
	int i;
	char *result;
	for (i = 0; i < 10; i++)
	{
		result = addNumStrings2(test[i].num1, test[i].num2);
		checkResult(result, test[i].result);
	}
	getchar();
	return 0;
}