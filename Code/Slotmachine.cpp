#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
    srand(time(NULL));//tao sinh so ngau nhien
    int n,n1,n2,n3 ;
    float cash=10.00;
    FILE *fptr;
    fptr = fopen("cash.txt","a");
	fclose(fptr);
    fptr = fopen("cash.txt","r");
    fscanf(fptr,"%f",&cash);
    if(cash<=0)
    {
		char choice;
		do{
    	printf("\nYou have $%f cash",cash);
    	printf("\nYou have no money to play!");
    	printf("\nDo you want to recharge money?(Y/N)\n");
    	scanf("%c",&choice);
    	fflush(stdin);
    	if((choice=='y')||(choice=='Y')){
            cash=10.00; 
            printf("You can play again with cash = $10.00\n");
		}
		else if((choice=='n')||(choice=='N')){
			printf("You have no money to play! Goodbye.");
			exit(0);
		}else{
			printf("Invalid input\n");
		}
	    }while(!(choice=='y')||(choice=='Y')||(choice=='n')||(choice=='N'));
	}
    fclose(fptr);
    
    do{
    printf("\nYou have $%.2f.\n",cash);
    printf("Choose one of the following menu options:\n");
    printf("1) Play the slot machine.\n");
    printf("2) Save game.\n");
    printf("3) Cash out.\n");
    printf("4) Exit.\n");
    n = checkInputInt((char *)"Please choose menu(1-4) ",1,4);
    if(n==1){
        	n1=rand()%10;
        	n2=rand()%10;
        	n3=rand()%10;
        	printf("%d%d%d\n",n1,n2,n3);
            if((n1==n2)&&(n2==n3)&&(n1==n3)){
            	cash+=9.75;
            	printf("You win the big prize, $10.00\n");
			}            
			else if((n1!=n2)&&(n2!=n3)&&(n3!=n1)){
				cash-=0.25;
				printf("Sorry, you dont win anything\n");
			}
			else if(((n1==n2)&&(n2!=n3))||((n2==n3)&&(n1!=n3))||((n1==n3)&&(n2!=n3))){
				cash+=0.25;
				printf("You win 50 cent\n");
			}
			}
	    else if(n==2){
	            fptr = fopen("cash.txt","w");
	            if(fptr == NULL){
                   printf("Error!");   
                    exit(1);             
               } 
			fprintf(fptr,"%f",cash); 
			fclose(fptr);
			printf("Your money had saved!\n");
			}
	    else if(n==3){
	    	fptr = fopen("cash.txt","w+");
	            if(fptr == NULL){
                   printf("Error!");   
                    exit(1);             
               } 
            printf("Thank you for playing! You end with $%.2f\n",cash);
            cash=0;
			fprintf(fptr,"%f",cash); 
			fclose(fptr);
	        } 
		else if(n==4){
	    	fptr = fopen("cash.txt","w");
	    	fprintf(fptr,"%f",cash); 
			fclose(fptr);
	        } 
		else{
		    printf("Re-enter your choice.\n");	
    }
    if(cash<=0){
    	    printf("You have no money to play! Goodbye.");
    	    fptr = fopen("cash.txt","w");
	    	fprintf(fptr,"%f",cash); 
			fclose(fptr);
		    exit(0);
	}
}while(n!=4);
    return 0;
}
