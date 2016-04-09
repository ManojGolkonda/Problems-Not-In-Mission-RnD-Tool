#include<stdio.h>
int* sort1(int *a,int length)
{
int i,count=0;
for(i=0;i<length;i++)
   if(a[i] == 0)
     count++;
for(i=0;i<count;i++)
   a[i]=0;
for(i=count;i<length;i++)
   a[i]=1;
return a;
}
int* sort2(int *a,int length)
{
  int i,j=length,temp;
  for(i=0;i<length && i<j;i++)
  //while(i<length && i<j)
   {
  //  if(a[i] == 0)
    //  i++;
    //else
    if(a[i] == 1) 
     {
      temp = a[i];
      a[i] = a[--j];
      a[j] = temp;
     }
   }
  return a;
}
int main()
{
int a[100],i,length,count=0,*sa;
printf("enter the length of array\n");
scanf("%d",&length);
printf("enter the array\n");
for(i=0;i<length;i++)
{
  scanf("%d",&a[i]);
  if(a[i]!=0 && a[i]!=1)
    {
	printf("error in input\n");
	return 0;
    }
}
sa = sort2(a,length);
printf("sorted array is: ");
for(i=0;i<length;i++)
   printf(" %d ",sa[i]);
return 0;
}