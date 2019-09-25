#include <stdio.h>

int main(){
    int i,j;
    int rowSums[2] = {0};
    int columnSums[3] = {0};
    int m[2][3] ={{9,7,4},
                  {20,15,3}};
    
    for(i = 0; i < 2; i++){//rowSums
        for(j = 0; j < 3; j++){
            rowSums[i] += m[i][j];
        }
    }
    for(i = 0; i < 3; i++){//columnSums
        for(j = 0; j < 2; j++){
            columnSums[i] += m[j][i];
        }
    }

    printf("Row sums: %d, %d\n",rowSums[0],rowSums[1]);
    printf("Column sums: %d, %d, %d",columnSums[0],columnSums[1],columnSums[2]);

}