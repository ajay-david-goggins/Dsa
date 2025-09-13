#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main () {
    int sum[] = {5, 8, 21, 45, 89};
    int rs = 0, target = 66;
    int *p = twoSum(sum, sizeof(sum)/sizeof(sum[0]), target, &rs);

    if (rs) {
        printf("Target found at p[%d] : %d and p[%d] : %d", p[0],sum[p[0]], p[1], sum[p[1]]);
        free (p);
    } else {
        printf("Target not found");
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* int *rs_arr = malloc( sizeof(int) * 2); */
    int i, j;

    if (nums == NULL || numsSize < 2) {
        return NULL;
    }

    for (i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target & 1) { // if target is odd answer maybe even, odd or odd, even 
                if (((nums[i] & 1) && !(nums[j] & 1)) || (!(nums[i] &1) && (nums[j]&1))) { // only allow different combination(odd, even)
                    if (nums[i] + nums[j] == target) {
                        int *rs_arr = (int *) malloc ( sizeof(int) * 2);
                        rs_arr[0] = i;
                        rs_arr[1] = j;
                        *returnSize = 2;

                        return rs_arr;
                    }

                }
            } else { // else target is defenitely
                if (((nums[i] & 1) && (nums[j] & 1)) || (!(nums[i] &1) && !(nums[j]&1))) { // only allow same combination(odd, even)
                    if (nums[i] + nums[j] == target) {
                        int *rs_arr = (int *) malloc ( sizeof(int) * 2);
                        rs_arr[0] = i;
                        rs_arr[1] = j;
                        *returnSize = 2;

                        return rs_arr;
                    }

                }
            }
        }
    }
}

