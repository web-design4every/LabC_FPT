#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void readFileInfo(FILE * fp,char fileName[], int &line,int &maxLen){
	char c;
	int numChars = 0;
	fp = fopen(fileName,"r");
	if (fp == NULL){
		printf("Error!");
		exit(1);
	}
	do{
		fflush(stdin);
		c = fgetc(fp);
		if(c != ' ' && c!= '\n' && c!= EOF){
			numChars += 1;
		}
		if(c == '\n'){
			line += 1;
			if(numChars > maxLen){
				maxLen = numChars;
			}
			numChars = 0;
		}
	}while(c != EOF);
	fclose(fp);
}
	
int main()
{
	FILE * fp;
	int line = 0, maxLen = 0,count = 0;
	char c,fileName[30];
	srand(time(NULL));
	
	do{
		printf("What file stores the puzzle words?\n");
		scanf("%s",fileName);
		if(fopen(fileName,"r") != NULL){
			break;
		}else
			printf("This file is not exited.\n"); 
	}while(1);
	// find number of lines and max length of lines
	readFileInfo(fp,fileName,line,maxLen);
	
	char str[line][maxLen];
	int index = 0,incorrect = 0,size = maxLen;
	
	fp = fopen(fileName,"r");
	//	read data from File to array
	while( fscanf(fp,"%s",str[count++]) == true){     
    } 
	fclose(fp);
	do{
		char choose[3],guess;
		printf("Would you like to play hangman? (yes/no)\n");
		gets(choose);
		if (strcmp(choose,"no") == 0){
			printf("\nThanks for playing!\n");
			exit(1);
		}
		int x = rand()%line,turn = 0;
		char word[strlen(str[x])],hideWord[strlen(str[x])],check = 1;
//		printf("%d\t%s\t",x,str[x]);
		strcpy(word,str[x]);
		strupr(word);
//		printf("%s\t",word);
		for(int i = 0; i < strlen(word); i++){
			hideWord[i] = '-';
		}
//		printf("%s",hideWord);
		do{
			printf("\nYou currently have %d incorrect guesses.\n",incorrect);
			printf("Here is your puzzle: \n");
			printf("%s\n",&hideWord);
			do{
				check = 1;
				printf("\nPlease enter your guess.\n");
				fflush(stdin);
				scanf("%c",&guess);
				fflush(stdin);
				for (int i = 0; i < strlen(hideWord); i++){
					if(guess == hideWord[i]){
						printf("Sorry, you have guessed that letter already.\n");
						check = 0;
						break;
					}
				}
			}while(check == 0);
			for(int i = 0; i < strlen(hideWord);i++){
				if(guess == word[i]){
					hideWord[i] = guess;
					if(strcmp(word,hideWord) == 0){
						printf("Congratuations! You got the word, %s\n",word);
						check = 0;
					}else{
						for(int j = i + 1;j < strlen(hideWord);j++){
							if(guess == word[j]){
								hideWord[j] = guess;
							}
						}
						printf("Congratuations, you guessed a letter in the puzzle!\n");
					}
					break;
				}else{
					if(i == strlen(hideWord) -1){
						incorrect++;
						if(incorrect == 5){
							printf("Sorry, you have made 5 incorrect guesses, you lose.\n");
							printf("The correct word was %s\n",word);
						}
						else printf("Sorry, that letter is NOT in the puzzle!\n");
						break;	
					}
						
				}
			}	
		}while(incorrect < 5 && check != 0);
		incorrect = 0;
	}while(1);
}
