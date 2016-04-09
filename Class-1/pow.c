#include<stdio.h>
unsigned int pow_mod(int a,int b,int k)
{
 unsigned int p=1;
 while(b)
 {
   p*=a;
   p%=k;
   b--;
 }
return p;
}
int main()
{
unsigned int x,y,a,p;
printf("enter x, y, a : ");
scanf("%d%d%d",&x,&y,&a);
p=pow_mod(x,y,a);
//result=(p%a);
//printf("product is : %lld\n",p);
printf("result is: %d\n",p);
return 0;
}