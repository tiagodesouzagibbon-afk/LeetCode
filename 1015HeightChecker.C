#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Comp( const void *a, const void *b ) {
    return *(int*)a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize) {
    
    int i;
    int notEqual = 0;
    int expected[heightsSize];

    memcpy( expected, heights, heightsSize * sizeof(int) );
    qsort( expected, heightsSize, sizeof(int), Comp );
    for ( i = 0; i < heightsSize; i++ ) {
        if ( expected[i] != heights[i] ) notEqual++;
    }
    
    return notEqual;
}

int main() {

    int h1[6] = {1,1,4,2,1,3};
    int h2[5] = {5,1,2,3,4};
    int h3[5] = {1,2,3,4,5};

    int correto = 0;

    if ( heightChecker( h1, 6 ) == 3 ) correto++;
    if ( heightChecker( h2, 5 ) == 5 ) correto++;
    if ( heightChecker( h3, 5 ) == 0 ) correto++;

    printf("%d/3 testes corretos.", correto);

    return 0;
}