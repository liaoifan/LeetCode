#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char *s) {
  const int input_length = strlen(s);
  int answer = 0;
  int *ptr_Int = (int *)malloc(sizeof(int) * input_length);

  int i = 0;
  for (char *ptr = s; *ptr != '\0';
       ptr++) {  //將羅馬字元轉成 int 存在 ptr_Int 中
    switch (*ptr) {
      case 'I':
        *(ptr_Int + i) = 1;
        break;
      case 'V':
        *(ptr_Int + i) = 5;
        break;
      case 'X':
        *(ptr_Int + i) = 10;
        break;
      case 'L':
        *(ptr_Int + i) = 50;
        break;
      case 'C':
        *(ptr_Int + i) = 100;
        break;
      case 'D':
        *(ptr_Int + i) = 500;
        break;
      case 'M':
        *(ptr_Int + i) = 1000;
        break;
    }
    ++i;
  }

  for (int *ptr = ptr_Int; ptr < ptr_Int + input_length; ptr++) {
    if (ptr == ptr_Int + input_length -
                   1) {  // special case：最後一個元素特別處理，避免指針指過頭
      answer += *ptr;
      return answer;
    }

    if (*ptr >= *(ptr + 1)) {
      answer += *ptr;
    } else {
      answer -= *ptr;
    }
  }
  free(ptr_Int);

  return answer;
}

int main(int argc, char *argv[]) {
  char data[] = "MCMXCIV";
  printf("答案是%d\n", romanToInt(data));
  return 0;
}
