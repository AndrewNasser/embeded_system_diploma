#include <stdio.h>
#include <stdlib.h>

int main()
{


	char c;
	printf("enter character ");
	scanf("%c",&c);
	if(c=='a'||c=='A'||c=='E'||c=='e'||c=='o'||c=='O'||c=='i'||c=='I'||c=='u'||c=='U')
        printf("the character is vowles");
    else
        printf("character is consonants");




    return 0;
}
