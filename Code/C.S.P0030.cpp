#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int checkInputInt(char* msg, int MIN, int MAX){
    int num,check;
    char ch;
    do{
        printf("%s",msg);
        fflush(stdin);
        check = scanf("%d%c",&num,&ch);
        if(check == 2 && ch == '\n'){
            if (num >= MIN && num <= MAX)
                break;
            else{
                printf("Out of range, please enter in %d - %d\n",MIN,MAX);  
            }
        } else {
            printf("Invalid input, please enter a integer number!\n");
        }
    }while(1);
    return num;
}
int main()
{
	int i,n,*a;
	int even=0,odd=0;
	printf("Sum Even Odd program\n\n");
    n = checkInputInt((char *)"Enter a number of elements n = ",1,INT_MAX);
	a=(int*)malloc(n*sizeof(int));
	printf("\nInput elements:\n");
	for(i=0;i<n;i++){
		printf("\n    Element %d = ",i);
        a[i] = checkInputInt((char *)"",0,INT_MAX);
	}
	for(i=0;i<n;i++){
		if(a[i]%2==0){
			even+=a[i];
		}else{
			odd+=a[i];
		}
	}
	printf("\nSum of Even = %d\n",even);
	printf("\nSum of Odd = %d\n",odd);
}
