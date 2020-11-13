#include <stdio.h>

void moveZeroes(int *nums, int numsSize) {
  int *end = nums + numsSize;
  for (int *ptr1 = nums; ptr1 < end; ptr1++) {
    if (*ptr1 == 0) {
      for (int *ptr2 = ptr1; ptr2 < end; ptr2++) {
        if (ptr2 != end - 1) {
          *ptr2 = *(ptr2 + 1);
        } else {
          *ptr2 = 0;
        }
      }
      --end;
      --ptr1;
    }
  }
}

int main(int argc, char *argv[]) {
  int nums[] = {0, 0, 0, 1, 0};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  printf("移除前：");
  for (int i = 0; i < numsSize; i++) {
    printf("%d\t", nums[i]);
  }
  printf("\n");

  moveZeroes(nums, numsSize);

  printf("移除後：");
  for (int i = 0; i < numsSize; i++) {
    printf("%d\t", nums[i]);
  }
  printf("\n");

  return 0;
}
