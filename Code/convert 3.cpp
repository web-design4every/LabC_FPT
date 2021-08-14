#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <conio.h>
  
void convert_to_words(char *num) 
{ 
    int i,n;
    int len = strlen(num); 
    if (len == 0) { 
        printf("empty string\n"); 
        return; 
    } 
    char *single_digits[] = { "zero", "one", "two","three", "four","five","six", "seven", "eight", "nine"}; 
  
    char *two_digits[] = {"","ten", "eleven", "twelve","thirteen", "fourteen","fifteen", "sixteen","seventeen", "eighteen", "nineteen"}; 

    char *tens_multiple[] = {"","","twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety"}; 
  
    char *tens_power[] = {"hundred","thousand","million","billion"}; 
    if (len == 1) { 
        printf("%s\n", single_digits[*num - '0']); 
        return; 
    }
    for(i=2;i<n;i+3){
    	if(len==i){
    		if (*num == '1') { 
                int sum = *num - '0' + *(num + 1)- '0'; 
                printf("%s\n", two_digits[sum]); 
                return; 
            } ++num;
		}
	}
}
int main(int argc, char** argv) { 
    char a[10];
    do{
    printf("Plese enter string in numberic format 1:");
    scanf("%s",a);
    printf("The converted string: ");
    convert_to_words(a);
    fflush(stdin);
	printf("\nPress enter to continue another reverse, ESC to exit.\n");
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
