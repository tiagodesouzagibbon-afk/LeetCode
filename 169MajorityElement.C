#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {
    int resultado;
    int count = 0;

    for ( int i = 0; i < numsSize; i++ ) {
        if ( count == 0 ) {
            resultado = nums[i];
            count = 1;
        } else if ( resultado == nums[i] ) {
            count++;
        } else count--;
    }

    return resultado;
}

int main() {

    int c1[3] = {3,2,3};
    int c2[7] = {2,2,1,1,1,2,2};
    int c3[6] = {-1,1,1,1,2,1};
    int c4[3] = {3,3,4};

    int correto = 0;

    if ( majorityElement ( c1, 3 ) == 3 ) correto++;
    if ( majorityElement ( c2, 7 ) == 2 ) correto++;
    if ( majorityElement ( c3, 6 ) == 1 ) correto++;
    if ( majorityElement ( c4, 3 ) == 3 ) correto++;
    
    printf("%d/4 testes corretos.", correto);

    return 0;
}