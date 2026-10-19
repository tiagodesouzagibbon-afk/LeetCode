#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Swap ( int *a, int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    while ( mid <= high ) {
        if ( nums[mid] == 0 ) {
            Swap ( &nums[low], &nums[mid] );
            low++;
            mid++;
        } else if ( nums[mid] == 1 ) {
            mid++;
        } else {
            Swap ( &nums[mid], &nums[high] );
            high--;
        }
    }
}

int main() {

    int c1[6] = {2,0,2,1,1,0};
    int r1[6] = {0,0,1,1,2,2};
    int c2[3] = {2,0,1};
    int r2[3] = {0,1,2};

    int correto = 0;

    sortColors ( c1, 6 );
    sortColors ( c2, 3 );

    if ( memcmp( c1, r1, 6 * sizeof(int) ) == 0 ) correto++;
    if ( memcmp( c2, r2, 3 * sizeof(int) ) == 0 ) correto++;
    
    printf("%d/2 testes corretos.", correto);

    return 0;
}