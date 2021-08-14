#include<stdio.h>
#include <string.h>
int main(int argc, char** argv){
	int dd,mm,yy;
	int i;
	char a,b;
	char choice[10];
	do{
	printf("\nMENU\n");
	printf("---------------------\n\n");
	printf("1- Processing date data\n");
	printf("2- Character data\n");
	printf("3- Quit\n");
	printf("Enter your choice:\n");
	scanf("%s",&choice);
	fflush(stdin);
    if(strcmp(choice,"1")==0){
			printf("Enter date (DD/MM/YYYY format): ");
            scanf("%d/%d/%d",&dd,&mm,&yy);
            
            if(yy>=0001 && yy<=9999){
            if(mm>=1 && mm<=12){
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=28) && (mm==2))
                printf("Date is valid.\n");
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                printf("Date is valid.\n");
            else
                printf("Day is invalid.\n");
        }else{
            printf("Month is not valid.\n");
        }
        }else{
            printf("Year is not valid.\n");
        }
    } 
    else if(strcmp(choice,"2")==0){
        	printf("Input 2 characters:");
        	fflush(stdin);
        	scanf("%c%c",&a,&b);
            if((int)a>(int)b){
            	for(i=(int)a;i>=(int)b;i--){
            		char c=i;
            		printf("%c:%d\n",c,i);
				}
			}else{
				for(i=(int)b;i>=(int)a;i--){
            		char c=i;
            		printf("%c:%d\n",c,i);
				}
			}
    }
    else if(strcmp(choice,"3")==0){
        	printf("Exit the program.");
    }
    else{
		    printf("Re-enter your choice.\n");	
	}
}while(strcmp(choice,"3")!=0);
    return 0;
}
