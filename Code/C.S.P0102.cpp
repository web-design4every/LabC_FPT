#include<stdio.h>
#include <cstdlib>

int main() {
   int i, j, mat1[10][10], mat2[10][10], mat3[10][10];
   int row1, col1, row2, col2;

   printf("\nPlease enter row of matrix 1: ");
   scanf("%d", &row1);
   printf("\nPlease enter column of matrix 1: ");
   scanf("%d", &col1);

   for (i = 1; i <= row1; i++) {
      for (j = 1; j <= col1; j++) {
         printf("Element a[%d][%d] : ", i, j);
         scanf("%d", &mat1[i][j]);
      }
   }
   while(true){
   printf("\nPlease enter row of matrix 2: ");
   scanf("%d", &row2);
   printf("\nPlease enter column of matrix 2: ");
   scanf("%d", &col2);
   
   if (row1 != row2 || col1 != col2) {
      printf("\nTwo matrices are not the same size!!!");
      printf("\nPlease re-enter again.");
   }else break;
}
   for (i = 1; i <= row2; i++)
      for (j = 1; j <= col2; j++) {
         printf("Element b[%d][%d] : ", i, j);
         scanf("%d", &mat2[i][j]);
      }

   for (i = 1; i <= row1; i++)
      for (j = 1; j <= col1; j++) {
         mat3[i][j] = mat1[i][j] + mat2[i][j];
      }

   printf("\nResult: \n");
   for (i = 1; i <= row1; i++) {
      for (j = 1; j <= col1; j++) {
         printf("[%d]\t", mat3[i][j]);
      }
      printf("\n");
   }

   return (0);
}
