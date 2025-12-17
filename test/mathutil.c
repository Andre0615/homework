#include "mathutil.h"
#include <stdlib.h>
#include <stdio.h>

int Element_wise_Multiplication(const int A[3][3],const int B[3][3],int C[3][3]){ 
    int i;
    int j;
    for(j=0;j<3;j++){
         for(i=0;i<3;i++){
            C[i][j]=A[i][j]*B[i][j];
        }
    }
}

