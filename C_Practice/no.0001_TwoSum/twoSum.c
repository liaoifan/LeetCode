#include <stdio.h>
#include <stdlib.h>

struct KeyValue {
  int key;
  int value;
};

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  const int answer_length = 2;
  const int input_max = 1000000000;
  int *answer = (int *)malloc(sizeof(int) *
                              answer_length);  //記憶體配置並指定給answer指標
  int different_input = numsSize;

  //計算實際上有幾種input的迴圈
  int i = 0;
  for (int *ptr1 = &nums[0]; ptr1 < &nums[numsSize - 1]; ++ptr1) {
    int j = i + 1;
    for (int *ptr2 = ptr1 + 1; ptr2 < &nums[numsSize]; ++ptr2) {
      if (*ptr1 <= input_max && *ptr1 == *ptr2) {
        *ptr2 = input_max + 1;
        different_input--;
      }
      ++j;
    }
    ++i;
  }

  //將key和value存起來
  struct KeyValue data[different_input];

  int k = 0;
  i = 0;
  for (int *ptr1 = &nums[0]; ptr1 < &nums[numsSize]; ++ptr1) {
    if (*ptr1 <= input_max) {
      data[k].key = i;
      data[k].value = *ptr1;
      ++k;
    }
    ++i;
  }

  printf("There are %d different input numbers\n", different_input);
  for (int i = 0; i < different_input; i++) {
    printf("data[%d] 的 key 是 %d , value 是 %d. \n", i, data[i].key,
           data[i].value);
  }

  for (struct KeyValue *iter1 = &data[0]; iter1 < &data[different_input - 1];
       ++iter1) {
    for (struct KeyValue *iter2 = iter1 + 1; iter2 < &data[different_input];
         ++iter2) {
      if (((*iter1).value + (*iter2).value == target)) {
        answer[0] = (*iter1).key;
        answer[1] = (*iter2).key;
        *returnSize = answer_length;
        return answer;
      }
    }
  }

  *returnSize = answer_length;
  return answer;
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize[] = {0};
  int target = 5;

  twoSum(nums, numsSize, target, returnSize);
  //	printf("%d\t%d", *twoSum(nums , numsSize , target , returnSize ) ,
  //*(twoSum(nums , numsSize , target , returnSize )+1) );

  return 0;
}
