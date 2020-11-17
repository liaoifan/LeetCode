#include <stdio.h>

int sumOddLengthSubarrays(int* arr, int arrSize) {
  int sum = 0;
  int maxOddLength = 0;

  maxOddLength = (arrSize % 2 == 0) ? (arrSize - 1) : arrSize;

  for (int i = 1; i <= maxOddLength;
       i += 2) {  //處理長度為 1、3、5、...、maxOddLength 的迴圈
    printf("處理長度為%d的集合：\n", i);
    for (int j = 0; j <= arrSize - i;
         j++) {  //處理每個子集合中，開頭第一個元素到最後一個元素
      for (int k = j; k < j + i; k++) {  //處理子集合內的元素加總
        sum += arr[k];
        printf("%d,", arr[k]);
      }
      printf("\n");
    }
  }

  return sum;
}

int main(int argc, char* argv[]) {
  int arr[] = {1, 4, 2, 5, 3};
  int arrSize = sizeof(arr) / sizeof(arr[0]);

  sumOddLengthSubarrays(arr, arrSize);

  return 0;
}
