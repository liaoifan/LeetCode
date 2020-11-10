#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  const int answer_length = 2;
  int *answer = (int *)malloc(sizeof(int) *
                              answer_length);  //記憶體配置並指定給answer指標

  int i = 0;
  for (int *ptr1 = &nums[0]; ptr1 < &nums[numsSize - 1]; ++ptr1) {
    int j = i + 1;
    int finding = target - *ptr1;
    for (int *ptr2 = ptr1 + 1; ptr2 < &nums[numsSize]; ++ptr2) {
      if (*ptr2 == finding) {
        answer[0] = i;
        answer[1] = j;
        *returnSize = answer_length;
        return answer;
      }
      ++j;
    }
    ++i;
  }

  *returnSize = answer_length;
  return answer;
}

int main(int argc, char *argv[]) {
  int nums[100000] = {0};
  int target = 7;
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int returnSize[] = {0};
  int *answer;

  FILE *fin;  //讀入測試資料
  fin = fopen("inputdata.txt", "r");
  if (fin == NULL) {
    printf("Fail To Open File inputdata!\n");
    return -1;
  }

  int n = 0;  //將100000筆測試資料寫入nums[]陣列
  for (int i = 0; i < 100000; i++) {
    fscanf(fin, "%d,", &n);
    nums[i] = n;
  }

  clock_t begin = clock();
  answer = twoSum(nums, numsSize, target, returnSize);
  printf("回傳的答案：[%d,%d]\n", *answer, *(answer + 1));
  clock_t end = clock();
  double elapsed_seconds = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("執行時間：%f秒\n", elapsed_seconds);

  return 0;
}
