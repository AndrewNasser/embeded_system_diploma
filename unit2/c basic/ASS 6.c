#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,y,sum=0;
printf("enter the number :");
scanf("%d",&x);
for(y=1;y<=x;y++)
{
    sum+=y;
}
printf("sum= %d",sum);
    return 0;
}
