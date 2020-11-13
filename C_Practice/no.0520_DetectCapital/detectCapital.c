#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool detectCapitalUse(char *word) {
  bool aa = true;
  for (char *ptr = word; *ptr != '\0'; ptr++) {
    if (isupper(*ptr)) {
      aa = false;
      break;
    }
  }
  if (aa == true) {
    return true;
  }

  bool AA = true;
  for (char *ptr = word; *ptr != '\0'; ptr++) {
    if (islower(*ptr)) {
      AA = false;
      break;
    }
  }
  if (AA) {
    return true;
  }

  bool Aa = true;
  if (islower(word[0])) {
    return false;
  }
  for (char *ptr = word + 1; *ptr != '\0'; ptr++) {
    if (isupper(*ptr)) {
      Aa = false;
      break;
    }
  }
  if (Aa) {
    return true;
  }

  return false;
}

int main(int argc, char *argv[]) {
  char word[] = {'a', 'B', 'c'};

  if (detectCapitalUse(word)) {
    printf("通過\n");
  } else {
    printf("不通過\n");
  }

  return 0;
}
