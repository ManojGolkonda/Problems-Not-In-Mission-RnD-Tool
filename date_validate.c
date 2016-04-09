#include<stdio.h>
struct date
{
	int d, m, y;
};
struct testcases
{
	struct date dt;
	int expected_result; //0 or 1 only. 1 if valid else invalid
}tests[] = {
	{ { 41, 10, 1996 }, 0 }, //invalid date
	{ { 14, 10, 1996 }, 1 }, //valid
	{ { 29, 2, 2021 }, 0 }, //feb 29 in a non leap year is invaid
	{ { 28, 2, 2015 }, 1 }, //valid
	{ { 29, 2, 2004 }, 1 }, //feb 29 valid in leap year
	{ { 29, 2, 2100 }, 0 }, //invalid
	{ { 0, 0, 2000 }, 0 } //invalid date
};
int validDate(struct date);
int isLeap(int);
int main()
{
	int i,result;
	for (i = 0; i < 7; i++)
	{
		result = validDate(tests[i].dt);
		if (result == tests[i].expected_result)
			printf("PASS\n");
		else
			printf("FAIL\n");
	}
	getchar();
	return 0;
}
int validDate(struct date dt)
{
	if (dt.m < 1 || dt.m > 12 || dt.y < 1) //if month or year is invalid
		return 0;
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //if month and year are valid the initialize max days in a month
	if (isLeap(dt.y)) //checks is a leap year or not
		maxDays[1] ++;  //if leap then increases max days of feb
	if (dt.d < 1 || dt.d > maxDays[dt.m - 1])  //validates the date
		return 0;
	return 1;
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
