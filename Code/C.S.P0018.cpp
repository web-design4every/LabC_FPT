#include <dirent.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
int main()
{   
    int n;
    char ch;
    char file1[100],file2[100],fname[100];
    char fnew1[100],fnew2[100],fnamew[100];
	char dpath[50]="D:\\Directory\\" ;
	do{
	memset(fnew1,0,100);
    memset(fnew2,0,100);
    memset(fnamew,0,100);
    //xóa bo nho dem cua file name
	printf("\n\n1) Read file\n");
	printf("2) Copy files\n");
	printf("3) Merge two files\n");
	printf("4) List files in a directory\n");
	printf("5) Delete file\n");
	printf("6) Exit program\n");
	n = checkInputInt((char *)"Please choose menu(1-6) ",1,6);
    if(n==1){
    	FILE *fptr;
    	printf("Enter the name of file you wish to see: ");
    	gets(fname);
    	strcat(fnamew,dpath);
		strcat(fnamew,fname);
    	fptr=fopen(fnamew,"r");
    	if(fptr == NULL){
                   printf("Error! File is not available.\n");               
               }else{
            while ((ch = fgetc(fptr)) != EOF)// doc ki tu trong file
        {
            printf("%c", ch);
        }}
            fclose(fptr);  
}
    else if(n==2){
    	printf("Enter name of file to copy:");
    	gets(file1);
    	printf("Enter name of target file:");
    	gets(file2);
    	strcat(fnew1,dpath);
		strcat(fnew1,file1);
    	strcat(fnew2,dpath);
		strcat(fnew2,file2);
		FILE *fptr;
		FILE *fp;
		fptr=fopen(fnew1,"r");
		fp=fopen(fnew2,"w");
		if(fptr == NULL||fp == NULL){
                   printf("Error! File is not available.\n");                
        }else{
         while((ch = fgetc(fptr)) != EOF) 
        {   
            fprintf(fp,"%c",ch); 
         } 
         printf("File copied successfully!!\n");
     }
		 fclose(fptr);
		 fclose(fp);     
        }
	else if(n==3){
		printf("Enter name of first file: ");
		gets(file1);
		printf("Enter name of second file: ");
		gets(file2);
		printf("Enter name of file which will store contents of two files: ");
		gets(fname);
		strcat(fnew1,dpath);
		strcat(fnew1,file1);
    	strcat(fnew2,dpath);
		strcat(fnew2,file2);
		strcat(fnamew,dpath);
		strcat(fnamew,fname);
		FILE *fptr;
		FILE *fp;
		FILE *fpt;
		fptr=fopen(fnew1,"r");
		fp=fopen(fnew2,"r");
		fpt=fopen(fnamew,"w");
		if(fptr == NULL||fp == NULL){
                   printf("Error! File is not available.\n");                
        }else{
         while((ch = fgetc(fptr)) != EOF) 
        {   
            fputc(ch,fpt); 
         }
         while((ch = fgetc(fp)) != EOF) 
        {   
            fputc(ch,fpt); 
         }
         printf("Two files were merged into %s file successfully!!\n",fname);
         }
         fclose(fp);
         fclose(fptr);
         fclose(fpt);
	}
	else if(n==4){
    DIR *d;
    struct dirent *dir;
    d = opendir("D:\\Directory\\");
    if (d != NULL)
    {
    	//in tat ca cac tap tin và thu muc trong directory
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
    }else{
    	perror("Error ");
	}
	closedir(d);
}
	else if(n==5){
		int status;
		printf("Enter name of a file you wish to delete: ");
		gets(fname);
		strcat(fnamew,dpath);
		strcat(fnamew,fname);
		status = remove(fnamew);
		if (status == 0)
             printf("%s file deleted successfully!!!\n", fname);
        else{
             printf("Unable to delete the file\n");
             perror("Following error occurred");
            }
	    }
	else if(n==6){
		printf("\nExit the program.\n");
	}
	else{
		printf("\nRe-enter again\n");
	}
}while(n!=6);
    return(0);
}
