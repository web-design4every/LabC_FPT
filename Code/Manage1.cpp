#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
struct Birthday{
	int dd;
	char mm[3];
	int yy;
};
struct SV{
	char code[10];
	char name[30];
	struct Birthday date;
	float point;
};
void filewrite(SV &sv){
	int count;
	int dd=sv.date.dd;
	char *mm=sv.date.mm;
	int yy=sv.date.yy;
	FILE *fptr;
	fptr = fopen("student.txt","a+");
	            if(fptr == NULL){
                   printf("Error!");   
                    exit(1);             
               }  
    
	    printf("\nEnter new student:\n");
		printf("Student code: ");fflush(stdin);
		gets(sv.code);
		printf("Student name: ");fflush(stdin);
		gets(sv.name);
		printf("Date of birth: ");fflush(stdin);
		scanf("%d-%3s-%d",sv.date.dd,sv.date.mm,sv.date.yy);
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
		
		
}

int main(int argc, char** argv){
	struct SV *ptr;
	int size=0,choice;
	ptr = (struct SV*)calloc(size, sizeof(struct SV));
	printf("1.Enter student list\n");
	printf("2.Look up student\n");
	printf("3.Display student list\n");
	printf("4.Exit\n");
	printf("Please choose menu ( 1 - 4 ):");
	scanf("%s",&choice);
	fflush(stdin);
	filewrite();
}
