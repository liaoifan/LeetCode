#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
  int* answer = (int*)malloc(sizeof(int) * numsSize);
  int* ptr = answer;
  int sum = 0;
  *returnSize = 0;

  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    *ptr = sum;
    ++ptr;
    ++(*returnSize);

    printf("%d：sum = %d, answer = %d, returnSize = %d\n", i, nums[i],
           *(ptr - 1), *returnSize);
  }

  return answer;
}

int main(int argc, char* argv[]) {
  int nums[] = {1, 2, 3, 4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize = 0;
  int* ptr = runningSum(nums, numsSize, &returnSize);

  for (int i = 0; i < numsSize; i++) {
    printf("%d,", *ptr);
    ptr++;
  }
  printf("\n");

  return 0;
}
