#include<stdio.h>


typedef struct day
{
	char number[20];
}day;
day date[31] = { { "first" }, { "second" }, { "third" }, { "fourth" }, { "fifth" }, { "sixth" }, { "seventh" }, { "eigth" }, { "nineth" }, { "tenth" }, { "eleventh" }, { "twelveth" }, { "thirteenth" }, { "fourteenth" }, { "fifteenth" }, { "sixteenth" }, { "seventeenth" }, { "eighteenth" }, { "nineth" }, { "twenty" }, { "twentyfirst" }, { "twentysecond" }, { "twentythird" }, { "twentyfourth" }, { "twentyfifth" }, { "twentysixth" }, { "twentyseventh" }, { "twentyeighth" }, { "twentyninth" }, { "thirtyth" }, { "thirtyfirst" } };
day month[12] = { { "january" }, { "february" }, { "march" }, { "april" }, { "may" }, { "june" }, { "july" }, { "august" }, { "september" }, { "october" }, { "november" }, { "december" } };

day x[27] = { { "one" }, { "second" }, { "three" }, { "four" }, { "five" }, { "sixth" }, { "seven" }, { "eight" }, { "nine" }, { "ten" }, { "eleventh" }, { "twelveth" }, { "thirteenth" }, { "fourteenth" }, { "fifteenth" }, { "sixteenth" }, { "seventeenth" }, { "eighteenth" }, { "nineth" }, { "twenty" }, { "thirty" }, { "fourty" }, { "fifty" }, { "sixty" }, { "seventy" }, { "eighty" }, { "ninty" } };
int main()
{
	char s[10];
	scanf(" %s", s);
	int d1, d2, m1, m2, y1, y2, y3, y4;
	d1 = (s[0] - '0');
	d2 = (s[1] - '0');
	m1 = (s[3] - '0');
	m2 = (s[4] - '0');
	y1 = (s[6] - '0');
	y2 = (s[7] - '0');
	y3 = (s[8] - '0');
	y4 = (s[9] - '0');
	int no = (d1 * 10) + d2 - 1;
	printf(" %s\t", date[no].number);
	no = m1 * 10 + m2 - 1;
	printf(" %s\t", month[no].number);
	if (y1 != 0)
	{
		no = y1 - 1;
		printf(" %s ", x[no].number);
		printf("thousand ");
	}
	if (y2 != 0)
	{
		no = y2 - 1;
		printf(" %s ", x[no].number);
		printf("hundred and ");
	}

	if (y3 <= 1)
	{
		no = (y3 * 10) + y4 - 1;
		printf(" %s", x[no].number);

	}
	else
	{
		no = y3 + 17;
		printf(" %s", x[no].number);
		if (y4>0){ no = 4; printf(" %s", x[no].number); }
	}
	getchar();
	return 0;
}

