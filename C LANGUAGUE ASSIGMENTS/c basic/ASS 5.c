#include <stdio.h>
#include <stdlib.h>

int main()
{
char x;
printf("enter the character\t");
scanf("%c",&x);
if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
    printf("%c is alphapet",x);
else
    printf("%c is not alphapet",x);



    return 0;

}
