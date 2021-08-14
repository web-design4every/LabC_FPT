#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
   char *string;
   string=(char*)malloc(1000*sizeof(char));
   int i = 0,max=1,j;
   printf("Please enter string: ");
   gets(string);
   for (i = 0; string[i] != '\0'; ++i) {
        while (!((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || string[i] == '\0')) {
            for (j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
            string[j] = '\0';
        }
    }
    printf("%s\n",string);
   printf("Times of appearance for each character: \n");
   int freq[58];
   memset(freq, 0, sizeof(freq));     
    for (i = 0; i < strlen(string); i++) 
    { 
        freq[string[i] - 'A']++; 
    }
   for (i = 0; i < strlen(string); i++) { 
        if (freq[string[i] - 'A'] != 0) { 
            printf("%c - %d \n",string[i],freq[string[i] - 'A']); 
            freq[string[i] - 'A'] = 0; 
        } 
    } 
    printf("\n-----------------------------------------------------------\n");
    printf("Characters that appears the most:\n");
    for (i = 0; i < strlen(string); i++) 
    { 
        freq[string[i] - 'A']++; 
    }
    for(i = 0; i < strlen(string); i++)
  	{
		if(max < freq[string[i] - 'A'])
		{
			max = freq[string[i] - 'A'];		
		}
	}	
	for(i = 0; i < strlen(string); i++)
	{
		if(max==freq[string[i] - 'A'])
		{
		printf("%c - %d\n",string[i],freq[string[i] - 'A']);
		freq[string[i] - 'A'] = 0;
	    }
	}
   free(string);
   return 0;
}

