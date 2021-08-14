#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
void NhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("Enter element[%d] = ",i);
        a[i] = checkInputInt((char *)"",INT_MIN,INT_MAX);
    }
}
void XuatMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void Sort(int a[], int n){
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
}
void ThemPhanTu(int *a, int &n, int val){
	int pos,i;
	if(val<a[0]){
		pos=0;
	}else{
		for(i=n-1;i>=0;i--){
			if(val>=a[i]){
				pos=i+1;
				break;
			}
		}
	}
    for(int i = n; i >pos; i--){
        a[i] = a[i-1];
    }
    a[pos]=val;
    a=(int*)realloc(a,(n+1)*sizeof(int));
    ++n;
}
int main(int argc, char** argv){
	int size,i,n,*a;
	size = checkInputInt((char *)"Please enter size of array: ",1,INT_MAX);
	a=(int*)malloc(size*sizeof(int));
    NhapMang(a,size);
	printf("The array after sorting:\n");
	Sort(a,size);
    XuatMang(a,size);
    printf("\nPlease enter new value: ");
    scanf("%d",&n);
    a=(int*)realloc(a,(size+1)*sizeof(int));
    ThemPhanTu(a,size,n);
    printf("New array:\n");
    XuatMang(a,size);
    free(a);
	return 0;
}
