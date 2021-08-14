#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int main(int argc, char** argv){
	srand(time(NULL));
	int n,a,b,*x;
	n = checkInputInt((char *)"Please enter size of array: ",1,INT_MAX);
	x=(int*)malloc(n*sizeof(int));
	printf("The original array:\n");
	for(int i=1;i<=n;i++){
		x[i]=rand();
		printf("%d  ",x[i]);
	}
	while(true){
	printf("\nSwap two elements: \n");
	a = checkInputInt((char *)"",1,n);
	b = checkInputInt((char *)"",1,n);
	if(a==b){
		printf("\nPlease re-enter again\n");
	}else break;
}
	x[a]=x[a]+x[b];
	x[b]=x[a]-x[b];
	x[a]=x[a]-x[b];
	printf("\nArray after swapping: \n");
	for(int i=1;i<=n;i++){
		printf("%d  ",x[i]);
	}
	return 0;
}
