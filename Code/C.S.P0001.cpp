#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void ReverseString(char str[])
{
	char str_new[1000]="";
	for(int i = strlen(str) - 1; i >= 0; i--)
		if(str[i] == '_')
		{
			strcat(str_new,&str[i+1]);
			strcat(str_new, "_");
			str[i] = '\0';
		}
		strcat(str_new,str);
		printf("%s\n", str_new);
}
int main(int argc, char** argv){
	char *str;
	str=(char*)malloc(1000 * sizeof( char));
	do{
	printf("\nPlease enter string: ");
	gets(str);
	printf("The old string: ");
	puts(str);
	printf("The reversed string: ");
	ReverseString(str);
	printf("Press enter to continue another reverse, ESC to exit.\n");
	do
    {
        char ch;
        fflush(stdin);
        ch=getch();
        if (ch == 13 ) break;
        else if (ch == 27)  exit(1);
    } while (1);
 }while(1);
 return 0;
}
