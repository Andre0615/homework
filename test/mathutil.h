#ifndef MATHUTIL_H
#define MATHUTIL_H

int Element_wise_Multiplication(const int A[3][3],const int B[3][3],int C[3][3]){ 
    int i;
    int j;
    for(j=0;j<3;j++){
         for(i=0;i<3;i++){
            C[i][j]=A[i][j]*B[i][j];
        }
    }
}
int Multiplication(const int A[3][3],const int B[3][3],int C[3][3]){
    int temp,i,j,k;
    for(j=0;j<3;j++){
         for(i=0;i<3;i++){
            temp=0;
            for(k=0;k<3;k++){
                temp=temp+A[k][j]*B[i][k];
            }
            C[i][j]=temp;
        }
    }
}
int transpose(const int A[3][3],int C[3][3]){
    int i,j;
    for(j=0;j<3;j++){
         for(i=0;i<3;i++){
            C[i][j]=A[j][i];
        }
    }
}
int Det2(const int A[2][2]){
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}
int Det3(const int A[3][3]){
    int i,j;
    int add=0;
    int minus=0;
    int temp;
    for(i=0;i<3;i++){
        temp=1;
        for(j=0;j<3;j++){
            temp=temp*A[(i+j)%3][(j)];
        }
        add=add+temp;
    }
    for(i=0;i<3;i++){
        temp=1;
        for(j=0;j<3;j++){
            if(i-j<0){
                temp=temp*A[(i-j+3)][(j)];
            }
            else{
                temp=temp*A[(i-j)][(j)];
            }
        }
        minus=minus+temp;
    }
    return add-minus;
}
int Adjoint(const int A[3][3],int B[3][3]){
    int i,j,k,l,m,n;
    int temp[2][2];
    int C[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m=0;
            for(k=0;k<3;k++){
                n=0;
                if(k==i)continue;
                for(l=0;l<3;l++){
                    if(l==j)continue;
                    temp[m][n]=A[k][l];
                    n++;
                }
                m++;
            }
            C[i][j]=Det2(temp);
            if((i+j)%2==1){
                C[i][j]=-C[i][j];
            }
        }
    }
    transpose(C,B);
}
int Inverse_Matrix(const int A[3][3],float B[3][3]){
    int i,j;
    int C[3][3];
    int k=Det3(A);
    if(k==0){
        printf("wrong");
        return 0;
    }
    printf("%d\n",k);
    Adjoint(A,C);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            B[i][j]=(float)C[i][j]/k;
        }
    }
}
#endif
