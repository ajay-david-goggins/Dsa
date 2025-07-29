#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if (nums == NULL || numsSize < 2) {
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {

                int *return_arr = (int *) malloc (2* sizeof(int));
                if (!return_arr) {
                    fprintf(stderr, "Memory allocation failed");
                    return NULL;
                }

                *returnSize = 2; 
                return_arr[0] = i;
                return_arr[1] = j;

                return return_arr;
            }
        }
    }

    *returnSize = 0;
    return NULL;

}
int main() {
    int a[] = { 3, 7, 9, 11};
    int rs = 0;
    int* p = twoSum(a, sizeof(a)/sizeof(a[0]), 9, &rs);

    if (rs != 0) {
        printf ("target indicies is %d and %d", p[0], p[1]);
        free(p);  // free memory no can access 
    } else {
        printf ("target not found");
    }

    return 0;


}
