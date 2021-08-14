#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int quadraticequation(int choice){
    int a,b,c,d;
    double root1, root2;
    printf("enter quadratic equation:\n");
    scanf("%d%d%d",&a,&b,&c);
    d=b*b-4*a*c;
    if(d<0){
        printf("root1 = %.2lf + i%.2lf\n", b/(double)(2*a), sqrt(-d)/(2*a));
        printf("root2 = %.2lf - i%.2lf\n", -b/(double)(2*a), sqrt(-d)/(2*a));
  }
  else { 
    root1 = (-b + sqrt(d))/(2*a);
    root2 = (-b - sqrt(d))/(2*a);
    printf("root1 = %.2lf\n", root1);
    printf("root2 = %.2lf\n", root2);
        }
}

int bankdeposit(int choice){
	int deposit,months;
	double received,interest;
	do{
	printf("\nEnter deposit( > 0):");
	scanf("%d",&deposit);
	printf("\nEnter interest rate( <= 0.1):");
	scanf("%lf",&interest);
	printf("\nEnter months( > 0):");
	scanf("%d",&months);
    if(deposit<0||interest>0.1||months<0)
       printf("Re-enter bank deposit\n");
	}while(deposit<0||interest>0.1||months<0);
		received=deposit+deposit*interest*months;
		printf("Total amount received = %lf\n",received);
	return received;
}

int main(int argc, char** argv) {
    char choice[10];
    do{
    printf("\nMenu\n");
    printf("1-Quadratic equation\n");
    printf("2-Bank deposit problem\n");
    printf("3-Quit\n");
    printf("Enter your choice:");
    scanf("%s",&choice);
    fflush(stdin);
    if(strcmp(choice,"1")==0){
    	quadraticequation(choice[10]);
    }
    else if(strcmp(choice,"2")==0){
    	bankdeposit(choice[10]);
    } 
    else if(strcmp(choice,"3")==0){
	
    	printf("Exit program\n");
}
    else{
    	printf("Re-enter your choice\n");
  	}
	}while(strcmp(choice,"3")!=0);
    return 0;
} 
