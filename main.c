#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize; // Early return for small arrays

    int slow = 2; // Start from the third element
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[slow - 2]) {
            nums[slow++] = nums[i]; // Copy and increment in one step
        }
    }
    return slow;
}

void printArray(int* nums, int numsSize, int k) {
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]);
        if (i < k - 1) {
            printf(",");
        }
    }
    for (int i = k; i < numsSize; i++) {
        printf(",_");
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1, 1, 1, 2, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input: nums = [1,1,1,2,2,3]\n");
    int k1 = removeDuplicates(nums1, numsSize1);
    printf("Output: %d, nums = ", k1);
    printArray(nums1, numsSize1, k1);

    int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Input: nums = [0,0,1,1,1,1,2,3,3]\n");
    int k2 = removeDuplicates(nums2, numsSize2);
    printf("Output: %d, nums = ", k2);
    printArray(nums2, numsSize2, k2);

    return 0;
}
