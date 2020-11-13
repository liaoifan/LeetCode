#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
  int search_index = -1;
  int index_min = 0;
  int index_max = numsSize - 1;
  int *ptr;

  while (1) {
    //二分搜尋法
    search_index = (index_max + index_min) / 2;
    ptr = nums + search_index;
    if (target == *ptr) {
      return search_index;
    } else if (target > *ptr) {
      index_min = search_index;
    } else if (target < *ptr) {
      index_max = search_index;
    }

    //當只剩下2個或1個可能時，再作細部判斷
    if ((index_max - index_min) <= 1) {
      if (target > nums[index_max]) {
        return index_max + 1;
      } else if (target == nums[index_max]) {
        return index_max;
      } else if (target > nums[index_min] && target < nums[index_max]) {
        return index_max;
      } else if (target == nums[index_min]) {
        return index_min;
      } else if (target < nums[index_min]) {
        return index_min;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 3, 5, 6};
  int target[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  printf("nums[] = {1,3,5,6}\n");

  for (int i = 0; i < 11; i++) {
    printf("輸入：%d,輸出：index[%d]\n", target[i],
           searchInsert(nums, numsSize, target[i]));
  }
  return 0;
}
