#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {

    int i;
    int max = nums[0];
    int min = nums[0];
    for ( i = 1; i < numsSize; i++ ) {
        if ( max < nums[i] ) max = nums[i];
        if ( min > nums[i] ) min = nums[i];
    }

    int *count = (int*)calloc( max - min + 1, sizeof(int) );
    for ( i = 0; i < numsSize; i++ ) {
        count[nums[i] - min]++;
        if ( count[nums[i] - min] > numsSize/2 ) break;
    }
    free ( count );
    return nums[i];
}

int main() {

    int c1[3] = {3,2,3};
    int c2[7] = {2,2,1,1,1,2,2};
    int c3[6] = {-1,1,1,1,2,1};

    int correto = 0;

    if ( majorityElement ( c1, 3 ) == 3 ) correto++;
    if ( majorityElement ( c2, 7 ) == 2 ) correto++;
    if ( majorityElement ( c3, 6 ) == 1 ) correto++;
    
    printf("%d/3 testes corretos.", correto);

    return 0;
}