#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {  //看不懂引入的參數

  int answer_length = 0;
  bool compare_flag = true;
  char *answer = "";

  printf("輸入字串共%d組\n", strsSize);

  if (strsSize == 0) {
    return answer;
  }

  int i = 0;
  for (char *ptr1 = strs[0] + i; *ptr1 != '\0';
       ptr1++) {  //取第0個字串的第i個字元來做比對，這裡字串結束真的有'\0'嗎？
    printf("%d\n", i);
    printf("第0個字串第%d個字元:%c\n", i, *ptr1);
    for (int j = 1; j < strsSize; j++) {  //取第j個字串的第i個字元來做比對
      printf("%d\n", j);
      printf("第%d個字串第%d個字元:%c\n", j, i, *(strs[j] + i));
      if (*(strs[j] + i) != *(strs[0] + i)) {  //如果比對結果不同，跳出迴圈
        compare_flag = false;
        break;
      }
      if (*(strs[j] + i) == '\0') {
        break;
      }
    }
    if (compare_flag == false) {
      printf("第%d個字元%c沒通過測試\n\n", i, *ptr1);
      break;
    }
    printf("第%d個字元%c通過測試\n\n", i, *ptr1);
    ++answer_length;
    ++i;
  }
  printf("總共有%d個字元通過測試\n", answer_length);

  ///*
  answer = (char *)malloc(sizeof(strs[0]) * answer_length);

  for (int i = 0; i <= answer_length; i++) {
    if (i != answer_length) {
      *(answer + i) = *(strs[0] + i);
    } else {
      *(answer + i) = '\0';
    }
    printf("%c\n", *(strs[0] + i));
  }
  //*/

  printf("==============================\n");

  return answer;
}

int main(int argc, char *argv[]) {
  char *strs[] =
      {};  //宣告一個字元指標的陣列，並分別指派值給 *strs[0], *strs[1], *strs[2]
  int strsSize = sizeof(strs) / sizeof(strs[0]);  //元素數量這樣算ok？

  printf(
      "strs內容：%p\t, strs位址：%p\n\n", strs,
      &strs);  //印出後發現str的值和位址一樣，表示strs是一個指到自己的指標，代表什麼？
  for (int i = 0; i < strsSize; i++) {
    printf("strs[%d]字元內容：%c, 字元位址：%p\n", i, *strs[i], strs[i]);
    for (char *ptr = strs[i]; *ptr != '\0'; ptr++) {
      printf("字元內容：%c\t字元位址：%p, ", *ptr, ptr);
      printf("\n");
    }
    printf("\n");
  }

  for (char *ptr = longestCommonPrefix(strs, strsSize); *ptr != '\0'; ptr++) {
    printf("%c", *ptr);
  }

  return 0;
}
