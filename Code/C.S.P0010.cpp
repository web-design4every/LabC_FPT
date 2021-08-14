#include<stdio.h>
#include <stdlib.h>
int main(){
	int i,j,k,n,*a;
	printf("Please enter size of array: ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("\nElement[%d] = ",i);
		scanf("%d",&a[i]);
	}
	printf("\nThe original array: \n");
	for(i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
            for (k=j;k<n-1;++k )
                a[k]=a[k+1];
            n--;
            j--;
        } 
    }
}
	printf("\nThe array after removing duplicate elements: \n");
	for (i = 0; i < n; i++) 
	{
		printf("%d  ", a[i]);
	}
	free(a);
	return 0;
}
