#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
  int length = 0;
  int offset = 0;

  if (numsSize == 0 || numsSize == 1) {
    return numsSize;
  }

  int i = 1;
  int *end = nums + numsSize;
  for (int *ptr1 = nums; ptr1 < end; ptr1++) {  //走訪array
    offset = 0;
    for (int *ptr2 = ptr1 + 1; ptr2 < end; ptr2++) {  //計算offset值
      if (*ptr2 == *ptr1) {
        ++offset;
      } else {
        break;
      }
    }

    // offset陣列
    for (int *ptr3 = ptr1 + 1; ptr3 < end - offset; ptr3++) {
      *ptr3 = *(ptr3 + offset);
    }
    end -= offset;
    ++length;

    //印出此次迴圈執行結果
    printf("第 %d 次執行，offset %d 位，length = %d ：", i++, offset, length);
    for (int *ptr1 = nums; ptr1 < nums + numsSize; ptr1++) {
      printf("%d ", *ptr1);
    }
    printf("\n");
  }

  return length;
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 1};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  printf("Remove前：");
  for (int *ptr1 = nums; ptr1 < nums + numsSize; ptr1++) {
    printf("%d ", *ptr1);
  }
  printf("\n");

  removeDuplicates(nums, numsSize);

  printf("Remove後：");
  for (int *ptr1 = nums; ptr1 < nums + numsSize; ptr1++) {
    printf("%d ", *ptr1);
  }
  printf("\n");

  return 0;
}
