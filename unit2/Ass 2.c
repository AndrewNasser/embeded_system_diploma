#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a,b,c;
   printf("enter three number ");
   scanf ("%d %d %d",&a,&b,&c);

   if (a>b&&a>c)
	   printf("%d is a large number",a);
   else if (b>a&&b>c)
	   printf("%d is a large number",b);
   else
	   printf("%d is a large number",c);



    return 0;
}
