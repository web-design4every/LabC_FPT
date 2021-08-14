#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main()
{   
    char file[30];
    char guess,ch,c;
	srand(time(NULL));
	FILE *fp;
	do{
		printf("What file stores the puzzle words?\n");
		scanf("%s",file);
		if(fopen(file,"r") != NULL){
			break;
			printf("This file is not exited.\n");
		}else printf("This file is not exited.\n"); 
	}while(1);
	fp = fopen(file,"r");
	if (fp == NULL){
		printf("Error!");
		exit(1);
	}
	int line = 0, maxLen = 0,count = 0, numchar = 0;
	while ((c = fgetc(fp)) != EOF)
    {
            if(c != ' ' && c!= '\n' && c!= EOF){
			numchar += 1;
		}
		    if(c == '\n'){
			line += 1;
			if(numchar > maxLen){
				maxLen = numchar;
			}
			numchar = 0;
		}
    }
    fclose(fp);
	char str[line][maxLen];
	fp = fopen(file,"r");
	while( fscanf(fp,"%s",str[count++]) == 1){     
    } 
	fclose(fp);
do{
	Sleep(1000);
	system("cls");
	char choice[3];
    printf("Would you like to play hangman (Yes/No)?\n");
    scanf("%s",&choice);
	fflush(stdin);
if ((strcmp(choice,"no") == 0)||(strcmp(choice,"No") == 0)){
			printf("\nThank for playing!\n");
    	    exit(1);
	}
else if ((strcmp(choice,"yes") == 0)||(strcmp(choice,"Yes") == 0)){
    int n=rand()%line,check,incorrect=0;
    char word[strlen(str[n])];
    strcpy(word,str[n]);
    int a=strlen(word);
//    printf("%s",word);
    char wordtemp[a]="";
    for(int i=0;i<a;i++){
          strcat(wordtemp,"-");	
	}
	
    do{
	   printf("\nYou currently have %d incorrect guesses.",incorrect);
	   printf("\nHere is your puzzle:\n");
	   printf("%s",wordtemp);
	   
	do{
	check=1;
	printf("\nPlease enter your guess\n");
	scanf("%c%c",&guess,&ch);
	fflush(stdin);
	for (int i = 0; i < a; i++){
		if(guess>='a'&&guess<='z'&&ch=='\n'){
		   if(guess == wordtemp[i]){
			printf("Sorry, you have guessed that letter already.\n");
			check=0;
			break;
		}	
	}else{
	 printf("\nInvalid guess! Please enter again.\n");
}
}
    }while(check==0);
    
	for(int i = 0; i < strlen(wordtemp);i++){
		if(guess == word[i]){
		wordtemp[i] = guess;
		if(strcmp(wordtemp,word) == 0){
			printf("Congratuations! You got the word, %s\n",word);
			check=0;
		}else{
			for(int j = i + 1;j < strlen(wordtemp);j++){
			    if(guess == word[j]){
				    wordtemp[j] = guess;
				}
		   }
			printf("Congratuations, you guessed a letter in the puzzle!\n");
	   }
			break;
		}else{
			if(i == strlen(wordtemp) -1){
				incorrect++;
				if(incorrect == 5){
					printf("Sorry, you have made 5 incorrect guesses, you lose.\n");
					printf("The correct word was %s\n",word);
				}
					else printf("Sorry, that letter is NOT in the puzzle!\n");
					break;	
				}		 
	}}
    }while(check!=0&&incorrect<5);
    }else{
		printf("\nPlease re-enter again\n");
}
}while(1);
   return(0);
}
