#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* Output = (int*)malloc(2*sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int y = i + 1; y < numsSize; y++) {
            if ((nums[i] + nums[y]) == target) {
                Output[0] = i;
                Output[1] = y;
                return Output;
            }
        }
    }

    return Output;
}

int main(){

    int nums[4] = {2,7,11,15};
    int returnsize; // Não sei bem pra que serve isso

    int* Retorno = twoSum(nums, 4, 9, &returnsize);

    printf("Output = [%d,%d]", Retorno[0], Retorno[1]);

    return 0;
}