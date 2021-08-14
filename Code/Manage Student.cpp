#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
void xoakhoangtrang(char *s)
{
    char *p;
    while (s[0]==' ')
        strcpy(s,s+1);
    while (s[strlen(s)-1]==' ')
        s[strlen(s)-1]='\0';
    for (int i=0; i<strlen(s); i++)
    {
        p=strstr(s,"  ");
        if (p!=NULL) strcpy(p,p+1);
    }
}
void chuan_ten(char *s)
{
    xoakhoangtrang(s);
    strlwr(s);
    s[0]=toupper(s[0]);
    for (int i=1; i<strlen(s);i++)
        if (s[i-1]==' ') s[i]=toupper(s[i]);
}
void filewrite()
{
   char code[10];
   char mm[10];
   int dd,yy,count;
   float point;
   char name[100];
   char code2[100][10];
   char mm2[100][10];
   int dd2[100],yy2[100],i;
   float point2[100];
   char name2[100][100];
   FILE *fptr;
	            fptr = fopen("student.txt","a+");
	            if(fptr == NULL){
                   printf("Error!");   
                    exit(1);             
               }  
            do{
			printf("\nEnter new student:\n");
			printf("Student code: ");
			scanf("%s",&code);
			strupr(code);
			fflush(stdin);	
            printf("Student name: ");
			scanf("%[^\n]",name); 
			chuan_ten(name);
			fflush(stdin);
			printf("Date of birth: ");
			scanf("%d-%3s-%d",&dd,&mm,&yy);
			chuan_ten(mm);
			if(yy>=0001 && yy<=9999){
            if(strcmp(mm,"Jan")==0||strcmp(mm,"Feb")==0||strcmp(mm,"Jan")==0 || strcmp(mm,"Mar")==0 || strcmp(mm,"May")==0 || strcmp(mm,"Jul")==0 || strcmp(mm,"Aug")==0|| strcmp(mm,"Oct")==0|| strcmp(mm,"Dec")==0||strcmp(mm,"Apr")==0 || strcmp(mm,"Jun")==0 || strcmp(mm,"Sep")==0 || strcmp(mm,"Nov")==0){
            if((dd>=1 && dd<=31) && (strcmp(mm,"Jan")==0 || strcmp(mm,"Mar")==0 || strcmp(mm,"May")==0 || strcmp(mm,"Jul")==0 || strcmp(mm,"Aug")==0|| strcmp(mm,"Oct")==0|| strcmp(mm,"Dec")==0))
                count=0;
            else if((dd>=1 && dd<=30) && (strcmp(mm,"Apr")==0 || strcmp(mm,"Jun")==0 || strcmp(mm,"Sep")==0 || strcmp(mm,"Nov")==0))
                count=0;
            else if((dd>=1 && dd<=28) && (strcmp(mm,"Feb")==0))
                count=0;
            else if(dd==29 && strcmp(mm,"Feb")==0 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                count=0;
            else
               count=1;
        }else{
            count=1;
        }
        }else{
            count=1;
        }
			fflush(stdin);
			printf("Learning point: ");
			scanf("%f",&point);
			i=0;
			while(!feof(fptr)){
				fscanf(fptr,"%s\n%[^\n]\n%d-%3s-%d\n%f\n#\n",&code2[i],&name2[i],&dd2[i],&mm2[i],&yy2[i],&point2[i]);
			    if(strcmp(code,code2[i])==0) {
				printf("\nStudents have only unique student code\n");
			    break;
			}
			    else{
				i=i+1;
			}
			}
			if(count==1||point<0||point>10) printf("\nReenter again.\n");
		   }while(count==1||point<0||point>10||strcmp(code,code2[i])==0);
			fprintf(fptr,"%s\n%s\n%d-%3s-%d\n%.1f\n#\n",code,name,dd,mm,yy,point);
			fclose(fptr);
}
void fileprint(){
   char code[100][10];
   char mm[100][10];
   int dd[100],yy[100],i;
   float point[100];
   char name[100][100]; 
   FILE *fptr;
	fptr = fopen("student.txt","r");
	    if(fptr == NULL){
            printf("Error!");   
                exit(1);             
        }
    i=0;
    printf("\nStudent list:\n\n");
    printf("---------------------------------\n\n");
    while(!feof(fptr))
  {
     fscanf(fptr,"%s\n%[^\n]\n%d-%3s-%d\n%f\n#\n",&code[i],&name[i],&dd[i],&mm[i],&yy[i],&point[i]);
     printf("Student code:%s\n",code[i]);
     printf("Student name:%s\n",name[i]);
     printf("Date of birth:%d-%3s-%d \n",dd[i],mm[i],yy[i]);
     printf("Learning point:%.1f\n ",point[i]);
     printf("\n--------------------------------\n\n");
     i=i+1;
   }
   fclose(fptr);			   	
}
void lookup(){
   char code[100][10];
   char mm[100][10];
   int dd[100],yy[100],i;
   float point[100];
   char name[100][100]; 
   char name2[100];
   int s;
   FILE *fptr;
	fptr = fopen("student.txt","r");
	    if(fptr == NULL){
            printf("Error!");   
                exit(1);             
        }
    i=0;
    fflush(stdin);
    printf("\nPlease enter student name: ");
    scanf("%[^\n]",name2);
    chuan_ten(name2);
    while(!feof(fptr))
  {
     fscanf(fptr,"%s\n%[^\n]\n%d-%3s-%d\n%f\n#\n",&code[i],&name[i],&dd[i],&mm[i],&yy[i],&point[i]);
     s=strcmp(name2,name[i]);
     if(s==0){
     printf("\nStudent code:%s\n",code[i]);
     printf("Student name:%s\n",name[i]);
     printf("Date of birth:%d-%3s-%d \n",dd[i],mm[i],yy[i]);
     printf("Learning point:%.1f\n ",point[i]);
     printf("--------------------------------\n");
     i=i+1;}
   }
   fclose(fptr);			   	
}

int main(int argc, char** argv){
	char choice[10];
	char ch;
	do{
	printf("1.Enter student list\n");
	printf("2.Look up student\n");
	printf("3.Display student list\n");
	printf("4.Exit\n");
	printf("Please choose menu ( 1 - 4 ):");
	scanf("%s",&choice);
	fflush(stdin);
    if(strcmp(choice,"1")==0){
			do{
			filewrite();
			printf("\nPress enter to continue, ESC to return main menu.\n\n");
            fflush(stdin);
            ch=getch();
            if (ch == 27 ) break;
			} while (ch==13);
			}
	else if(strcmp(choice,"2")==0){
			do{
			lookup();
			printf("\nPress enter to continue, ESC to return main menu.\n\n");
            fflush(stdin);
            ch=getch();
            if (ch == 27 ) break;
			} while (ch==13);
			}
	else if(strcmp(choice,"3")==0){
			do{
			fileprint();
			printf("\nPress enter to continue, ESC to return main menu.\n\n");
            fflush(stdin);
            ch=getch();
            if (ch == 27 ) break;
			} while (ch==13);
			}
	else if(strcmp(choice,"4")==0){
			printf("\nExit the program.\n");
		}
		else{
			printf("\nRe-enter choice again.\n\n");
	}}while(strcmp(choice,"4")!=0);
	return 0;
}
