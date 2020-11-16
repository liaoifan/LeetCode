#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define NumBits 32
uint32_t reverseBits(uint32_t n) {
  uint32_t answer = 0;
  bool stack[NumBits] = {0};

  for (int i = 0; i < NumBits; i++) {
    stack[i] = n & 1;
    n >>= 1;
  }

  for (int i = 0; i < NumBits; i++) {
    answer += (int)stack[i];
    printf("%d\n", answer);
    if (i != NumBits - 1) {
      answer <<= 1;
    }
  }

  return answer;
}

int main(int argc, char *argv[]) {
  uint32_t input = 0b00000010100101000001111010011100;

  printf("Answer = %d\n", reverseBits(input));

  return 0;
}
