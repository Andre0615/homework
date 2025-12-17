#include <stdio.h>
#include <stdlib.h>
#include "mathutil.h"

int main(){
    int i,j;
    int a[3][3]={{7,1,9},{7,5,4},{8,4,3}};

    int b[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int result1[3][3];
    float result2[3][3];
    Inverse_Matrix(a,result2);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        printf("(%f)",result2[i][j]);
        }
        printf("\n");
    }
    return 0;

}