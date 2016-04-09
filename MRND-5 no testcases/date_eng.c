#include<stdio.h>
/*
typedef struct testcases
{
	char t_date[11];
	char e_form[100];
}testcases;
testcases testcase[] = {
	{ "06-10-1995", "Sixth October One Thousand Nine Hundred And Ninty Five " },
	{ "24-12-1993", "TwentyFourth December One Thousand Nine Hundred And Ninty Three " },
	{ "10-09-0456", "Tenth September Four Hundred And Fifty Six " },
	{ "41-10-1996", "Invalid Date" },
	{ "14-10-2015", "Fourteenth October Two Thousand Fifteen " },
	{ "23-09-2019", "TwentyThird September Two Thousand Nineteen " }
};
*/
typedef struct day
{
	char number[20];
}day;
day date[31] = { { "First " }, { "Second " }, { "Third " }, { "Fourth " }, { "Fifth " }, { "Sixth " }, { "Seventh " }, { "Eigth " }, { "Ninth " }, { "Tenth " }, { "Eleventh " }, { "Twelveth " }, { "Thirteenth " }, { "Fourteenth " }, { "Fifteenth " }, { "Sixteenth " }, { "Seventeenth " }, { "Eighteenth " }, { "Ninth " }, { "Twenty " }, { "TwentyFirst " }, { "TwentySecond " }, { "TwentyThird " }, { "TwentyFourth " }, { "TwentyFifth " }, { "TwentySixth " }, { "TwentySeventh " }, { "TwentyEighth " }, { "TwentyNinth " }, { "Thirtyth " }, { "ThirtyFirst " } };
day month[12] = { { "January " }, { "February " }, { "March " }, { "April " }, { "May " }, { "June " }, { "July " }, { "August " }, { "September " }, { "October " }, { "November " }, { "December " } };

day x[27] = { { "One " }, { "Two " }, { "Three " }, { "Four " }, { "Five " }, { "Six " }, { "Seven " }, { "Eight " }, { "Nine " }, { "Ten " }, { "Eleventh " }, { "Twelve " }, { "Thirteen " }, { "Fourteen " }, { "Fifteen " }, { "Sixteen " }, { "Seventeen " }, { "Eighteen " }, { "Nineteen " }, { "Twenty " }, { "Thirty " }, { "Fourty " }, { "Fifty " }, { "Sixty " }, { "Seventy " }, { "Eighty " }, { "Ninty " } };

void concat(char *a, char *b){
	int i = 0, j = 0;
	while (a[i] != '\0')
		i++;
	while (b[j] != 0){
		a[i] = b[j];
		i++;
		j++;
	}
	a[i] = '\0';
}

int compare(char *a, char *b){
	int i;
	for (i = 0; a[i] != '\0'; i++){
		if (a[i] != b[i])
			return 0;
	}
	if (b[i] != '\0')
		return 0;
	else return 1;
}

int isLeap(int y) {
	if (y % 400 == 0)
		return 1;
	else if (y % 100 == 0)
		return 0;
	else if (y % 4 == 0)
		return 1;
	else
		return 0;
}

int validDate(int d, int m, int y)
{
	if (m < 1 || m > 12 || y < 1 || d < 1)						//if month or year is invalid
		return 0;
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		//if month And year are valid the initialize max days in a month
	if (isLeap(y))															//checks is a leap year or not
		maxDays[1] ++;													//if leap then increases max days of feb
	if (d > maxDays[m - 1])												//validates the date
		return 0;
	return 1;
}
void checkResult(char *a, char *b)
{
	printf("%s\n%s\n", a, b);
	if (compare(a, b))
		printf("PASS\n");
	else
		printf("FAIL\n");

}

char* test(char *s)
{
	static char output[100] = { '\0' };
	int d1, d2, m1, m2, y1, y2, y3, y4;
	d1 = (s[0] - '0');
	d2 = (s[1] - '0');
	m1 = (s[3] - '0');
	m2 = (s[4] - '0');
	y1 = (s[6] - '0');
	y2 = (s[7] - '0');
	y3 = (s[8] - '0');
	y4 = (s[9] - '0');
	if (validDate(d1 * 10 + d2, m1 * 10 + m2, y1 * 1000 + y2 * 100 + y3 * 10 + y4))
	{
		int no = (d1 * 10) + d2 - 1;
		concat(output, date[no].number);
		no = m1 * 10 + m2 - 1;
		concat(output, month[no].number);
		if (y1 != 0)
		{
			no = y1 - 1;
			concat(output, x[no].number);
			concat(output, "Thousand ");
		}
		if (y2 != 0)
		{
			no = y2 - 1;
			concat(output, x[no].number);
			concat(output, "Hundred And ");
		}

		if (y3 <= 1)
		{
			no = (y3 * 10) + y4 - 1;
			concat(output, x[no].number);

		}
		else
		{
			no = y3 + 17;
			concat(output, x[no].number);
			if (y4 > 0)
			{ 
				no = y4 - 1; 
				concat(output, x[no].number); 
			}
		}

	}
	else
		concat(output, "Invalid Date");
	return output;
}

int main(void)
{
	char d[100];
	char *result;
	/*int i;
	for (i = 0; i<6; i++)
	{
		result=test(i);
		checkResult(result, testcase[i].e_form);
	}*/
	printf("enter Date in DD-MM-YYYY format: \n");
	scanf("%s", d);
	result = test(d);
	printf("Result is:%s\n", result);
	getchar();
	return 0;
}