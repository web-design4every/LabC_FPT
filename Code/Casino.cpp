#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <conio.h>
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
void checkInputChar(char* msg){
    int check;
    char roll,ch;
    do{
        printf("%s",msg);
        fflush(stdin);
        check = scanf("%c%c",&roll,&ch);
        if(check == 2 && ch == '\n'){
            if(roll=='r'||roll=='R')
                break;
            else{
                printf("Invalid input, please enter 'r' or 'R' to roll\n"); 
            }
        } else {
            printf("Invalid input, please enter 'r' or 'R' to roll\n");
        }
    }while(1);
}
int main(int argc, char** argv){
	int point=0,chip=0,chipsell,chipbet,cash,money=1000;
	char check;
	int n,n1,n2,n3;
	srand(time(NULL));
	do{
	printf("\nWelcome to the Casino. Here are your choices:");
	printf("\n1) Buy chips");
	printf("\n2) Sell chips");
	printf("\n3) Play Craps");
	printf("\n4) Play Arup's Game of Dice");
	printf("\n5) Status Report");
	printf("\n6) Quit\n");
	n = checkInputInt((char *)"Please enter your choice: ",1,6);
	if(n==1){
		cash = checkInputInt((char *)"How much cash do you want to spend for chips? ",11,money);
		chip=cash/11;
		money-=chip*11;
	}
	else if(n==2){
		chipsell = checkInputInt((char *)"How many chips do you want to sell? ",1,chip);
		money+=chipsell*10;
		chip-=chipsell;
	}
	else if(n==3){
		chipbet = checkInputInt((char *)"How many chips would you like to bet? ",1,chip);
		checkInputChar((char*)"Press r and hit enter for your first roll\n");
		    n1=1+rand()%6;
		    n2=1+rand()%6;
			point=n1+n2;
			printf("You rolled a %d\n",point);
		if(point==7||point==11){
			printf("You win!\n");
			chip+=chipbet;
		}else if(point==2||point==3||point==12){
			printf("Sorry, you have lost.\n");
			chip-=chipbet;
		}else{
			while(1){
			n1=1+rand()%6;
		    n2=1+rand()%6;
		    n3=n1+n2;
			checkInputChar((char*)"Press r and hit enter for your first roll\n");
				printf("You rolled a %d\n",n3);
				if(n3==point){
					printf("You win!\n");
				    chip+=chipbet;
				    break;
				}else if(n3==7){
					printf("Sorry, you have lost.\n");
				    chip-=chipbet;
					break;}
			}
			}
		}
    else if(n==4){
        chipbet = checkInputInt((char *)"How many chips would you like to bet? ",1,chip);
	    checkInputChar((char*)"Press r and hit enter for your first roll\n");
			n1=1+rand()%6;
		    n2=1+rand()%6;
			point=n1+n2;
			printf("You rolled a %d\n",point);
		if(point==12||point==11){
			printf("You win!\n");
			chip+=chipbet;
		}else if(point==2){
			printf("Sorry, you have lost.\n");
			chip-=chipbet;	
		}else{
			n1=1+rand()%6;
		    n2=1+rand()%6;
		    n3=n1+n2;
		   	checkInputChar((char*)"Press r and hit enter for your first roll\n");
				printf("You rolled a %d\n",n3);
				if(n3>point){
			    	printf("You win!\n");
			        chip+=chipbet;}
			    else{
				    printf("Sorry, you have lost.\n");
				    chip-=chipbet;}
			}       	
        }
    else if(n==5){
        	printf("You currently have $ %d left and %d chips\n",money,chip);
        }
    else if(n==6){
        	money+=chip*10;
        	printf("After selling your chips, you have $ %d. Thanks for playing!\n",money);
    }
    else{
        	printf("Re-enter your choice.\n");
        	
}
    if((money<11)&&(chip==0)){
    	  printf("You do not have enought money to play! \n");
    	  break;
	}
}while(n!=6);
return 0;
}
