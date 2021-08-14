#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int checkprime(int num){
	int i;
	if(num==0||num==1){
		return 0;
	}
	for(i=2;i<=num/2;i++){
		if(num%i==0){
			return 0;
		}
	}return 1;
}
int Sumdigits(int n) 
{  
   int sum = 0; 
   while (n > 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
} 

int main(int argc, char** argv){
    char choice[10];
    int n;
	do{
    	printf("\n\n===================Welcome===================");
    	printf("\n1-Output primes of the putted numbers");
    	printf("\n2-Check a Fibonancy number");
    	printf("\n3-Sum of digits in a positive natural number");
    	printf("\n4-Exit");
    	printf("\n=====================End=======================");
    	printf("\nEnter your choice:");
    	scanf("%s",&choice);
    	fflush(stdin);
        if(strcmp(choice,"1")==0){
    		printf("Enter n (0 < n <= 50)\n");
    		do{
    			printf("n = ");
    			scanf("%d",&n);
    			if(n <= 0 || n>50)
    			printf("Re-enter n.\n");
    		}while(n <= 0 || n>50);
			for(int i=0;i<=n;i++){
				if(checkprime(i)==1)
				  printf("%d ",i);
			}}
		else if(strcmp(choice,"2")==0){
			int i=1,j=1,sum=0;
			printf("Enter n:\n");
			do{
				printf("n=");
    			scanf("%d",&n);
    			if(n <= 0 || n > 1000)
    			printf("Re-enter n.\n");
			}while(n <= 0 || n > 1000);
	        do{
	        	sum = i+j;
	        	i = j;
	        	j = sum;
			}while(j <= n);
			if( i == n){
				printf("check Fibonancy: 1");
			}else{
				printf("check Fibonancy: 0");
			}}
		else if(strcmp(choice,"3")==0){
			do{
				printf("n=");
    			scanf("%d",&n);
    			if(n <= 0)
    			printf("Re-enter n.\n");
	        }while( n <= 0);
			printf("Sum = ");
			printf("%d",Sumdigits(n));
		}
		else if(strcmp(choice,"4")==0){
			printf("Exit the program.");
	}
		else{
		    printf("Reenter your choice");	
		}
	}while(strcmp(choice,"4")!=0);	
	return 0;
}
