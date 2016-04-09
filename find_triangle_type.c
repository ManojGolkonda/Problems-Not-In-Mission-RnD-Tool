#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct testcases
{
	double vertex[3][2];
//	char expected_result[];
	char res[20];
} tests[5] = {
	{ { 0.0, 0.0, 0.0, 1.0, 1.0, 0.0 }, "Isoscles" },
	{ { 1.0, 1.0, 1.0, 2.0, 2.0, 1.0 }, "Isoscles" },
	{ { 0.0, 0.0, 1.0, 1.0, 2.0, 2.0 }, "Not Possible" },
	{ { 0.0, 0.0, 4.0, 0.0, 2.0, 3.0 }, "Equilateral" },//this test will fail because the given is not an equilateral
	{ { 0.0, 1.0, 1.0, 2.0, 1.0, 3.0 }, "Scalene" }
};
char* find_triangle(double*);
void check_result(char*, char*);
int main()
{
	int i;
	int result;
	for (i = 0; i < 5; i++)
	{
		result = find_triangle(tests[i].vertex);
		check_result(result, tests[i].res);
	}
	getchar;
	return 0;
}
char* find_triangle(double *a)
{
	double s1, s2, s3, temp[3];
	char *result;
	result = (char *)malloc(20 * sizeof(char));
	s1 = sqrt(pow(a[0] - a[2], 2) + pow(a[1] - a[3], 2));
	s2 = sqrt(pow(a[2] - a[4], 2) + pow(a[3] - a[5], 2));
	s3 = sqrt(pow(a[0] - a[4], 2) + pow(a[1] - a[5], 2));
	//printf("%f %f %f", s1, s2, s3);
	if (s1 < s2){
		temp[0] = s1 < s3 ? s1 : s3;
		temp[1] = s2 < s3 ? s2 : s3;
		temp[2] = s2 > s3 ? s2 : s3;
	}
	else{
		temp[0] = s2 < s3 ? s2 : s3;
		temp[1] = s1 < s3 ? s1 : s3;
		temp[2] = s1 > s3 ? s1 : s3;
	}
	if (temp[0] + temp[1] <= temp[2])
		result = "Not Possible";
	else{
		if (temp[0] == temp[1] && temp[1] == temp[2])
			result = "Equilateral";
		else if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
			result = "Isoscles";
		else
			result = "Scalene";
	}
	return result;
}
void check_result(char* a, char* b)
{
	if (a[0] == b[0])
		printf("PASS\n");
	else
		printf("FAIL\n");
}