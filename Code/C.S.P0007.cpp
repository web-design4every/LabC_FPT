#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int xoa(char *a, int q)
{
    int n = strlen(a), i;
    for (i = q; i <n-1; i++){
        a[i] = a[i + 1];
    }
    a[n-1]='\0';
    return 0;
}
int xoakhoangtrang(char *a)
{
    int i, n=strlen(a);
    for (i = 0; i < n-1; i++){
        if (a[i] == 32 && a[i + 1] == 32){
            xoa(a, i);
            i--;
    }
}
    if (a[0] == 32){
            xoa(a, 0);
    }
    if (a[n-1] == 32){
            xoa(a, n-1);
    }
    return 0;
}
int main(int argc, char** argv)
{
	do{
        char *str;
        str=(char*)calloc(1000,sizeof(char*));
        printf("\nPlease enter a string:");
        fflush(stdin);
        gets(str);
        xoakhoangtrang(str);
        printf("The string after removing:%s\n", str);
        printf("Press enter to continue, Esc to exit.\n");
    do{
        char ch;
        fflush(stdin);
        ch=getch();
        if (ch == 13 ) break;
        else if (ch == 27)  exit(1);
    } while (1);
 }while(1);
        return 0;
}
