#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <conio.h>
using namespace std;
int main(int argc, char** argv){
	int a[10],n,i;    
    do{
	printf("\nConvert Decimal to Binary program\n");  
    printf("        Enter a positive number : ");    
    scanf("%d",&n);    
    for(i=0;n>0;i++){    
         a[i]=n%2;    
         n=n/2;    
    }    
    printf("        Binary number:");    
    for(int j=i-1;j>=0;j--){    
    printf("%d",a[j]);    
    }    
    printf("\nPress any key to do another conversion\n");
    }while(getch());
    return 0;  
}
