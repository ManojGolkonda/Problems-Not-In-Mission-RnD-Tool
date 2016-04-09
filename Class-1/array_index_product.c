#include<stdio.h>
int* indexProduct1(int *a,int n)
{
  int i,j,mul=1;
  static int b[100];
  for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     if(i!=j)
      mul*=a[i];
    b[i]=mul;
   }
   return b;
}
int* indexProduct(int *a,int n)
{
  static int b[100];
  int m=1,i,count=0;
  for(i=0;i<n;i++)
   if(a[i]!=0)
    m*=a[i];
   else
    count++;
  if(count==0)
  {
     for(i=0;i<n;i++)
      b[i]=m/a[i];
     return b;
   }
  else if(count == 1)
  {
   for(i=0;i<n;i++)
    if(a[i] == 0)
     b[i]=m/a[i];
    else
     b[i] == 0;
   return b;
  }
  else
    {
     for(i=0;i<n;i++)
       b[i]=0;
     return b;
  }
}
int main()
{
int a[100],n,i,*b;
printf("enter length of array: ");
scanf("%d",&n);
printf("enter array: ");
for(i=0;i<n;i++)
  scanf("%d",&a[i]);
b = indexProduct1(a,n);
printf("the output array  is: ");
for(i=0;i<n;i++)
  printf(" %d ",b[i]); 
return 0;
}