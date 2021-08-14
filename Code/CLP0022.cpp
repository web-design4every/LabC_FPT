#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Date{
	int day;
	char month[3];
	int year;
};
struct Student{
	char* id;
	char* name;
	struct Date date;
	float point;
};

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
float checkInputFloat(char* msg, int MIN, int MAX){
    float num;
	int check;
    char ch;
    do{
        printf("%s",msg);
        fflush(stdin);
        check = scanf("%f%c",&num,&ch);
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
int checkDate(int dd,char* mm,int yy){
	int check = 0,checkYear = 0;
		if (yy < 0){
			printf("Please enter the year that more than 0 and less than 2020!");
			check = 0;
			return check;
		}
		if (yy%400 == 0 || (yy%4==0 && yy%100!=0)){
			checkYear = 1;
		}
		if ((strcmp(strlwr(mm),"jan") == 0) || (strcmp(strlwr(mm),"mar") == 0) || (strcmp(strlwr(mm),"may") == 0) || (strcmp(strlwr(mm),"jul") == 0) || (strcmp(strlwr(mm),"aug") == 0) || (strcmp(strlwr(mm),"oct") == 0) || (strcmp(strlwr(mm),"dec") == 0)){
			if (dd >= 1 && dd <= 31){
				check = 1;
			}
			else 	printf("The day out of invalid!\tPlease again\n");
		}
		else if (strcmp(strlwr(mm),"feb") == 0) {
			if (checkYear == 1){
				if (dd >=1 && dd <= 29){
					check = 1;
				}
				else 	printf("The day out of invalid!\tPlease again\n");
			}else {
				if (dd >=1 && dd <= 28){
					check = 1;
				}
				else 	printf("The day out of invalid!\tPlease again\n");
			}
		}else if((strcmp(strlwr(mm),"apr") == 0) || (strcmp(strlwr(mm),"jun") == 0) || (strcmp(strlwr(mm),"sep") == 0) || (strcmp(strlwr(mm),"nov") == 0)) {
			if (dd >= 1 && dd <= 30){
				check = 1;
			}
			else 	printf("The day out of invalid!\tPlease again\n");
		}
		else {
			printf("Please enter again and only enter the first 3 letters of the month.\n");
		}
	return check;
}
Student* enter(struct Student* HS,int &size){
	int check;
	do{	
		check = 1;
		printf("Student code: ");
		fflush(stdin);
		scanf("%s",&HS[size].id);
		for (int i = 0; i < size; i++){
			if (strcmp(HS[size].id,HS[i].id) == 0){
				check = 0;
				printf("This code was exited.Please enter other student code! \n");
				break;
			}
		}	
	}while(check == 0);
	printf("Student name: ");
	fflush(stdin);
	scanf("%s",&HS[size].name);
	printf("Date of birth: ");
	fflush(stdin);
	do{
		scanf("%d - %s - %d",&HS[size].date.day,&HS[size].date.month,&HS[size].date.year);
	}while(checkDate(HS[size].date.day,HS[size].date.month,HS[size].date.year) == 0);
	HS[size].point = checkInputFloat((char*)"Learning point: ",0,10);
	size++;
	HS = (struct Student*)realloc(HS,size*sizeof(struct Student));
	return HS;
}
int main(int argc, char** argv) {  
	int n,size = 0;
	char c;
	struct Student* HS = (struct Student*)calloc(size,sizeof(struct Student));
	do{
		printf("\t1.Enter student list\n\t2.Look up student\n\t3.Display student list\n\t4.Exit");
    	n = checkInputInt((char *)"\nPlease choose menu(1-4) ",1,4);
    	switch (n){
    		case 1:
    		do{	
    			HS = enter(HS,size);
				printf("Press enter to continue,ESC to return the main menu\n");
				fflush(stdin);
				scanf("%c",&c);
				if(c == 27){
					break;
				}else if(c == '\n'){
					continue;
				}
				else{
					printf("Please press Enter or ESC!\n");
				}
			} while(1);
    			break;
    		case 2: 
    			break;
    		case 3: 
    			break;
    		case 4: 
    			break;	
	}
	}while(1);
    return 0;
}
