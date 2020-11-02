#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    const int bits = 32;  // uint32_t 總共佔了幾個 bit
    bool index = 0;       //目前處理位置的布林值
    uint32_t answer = 0;  //答案
    uint32_t add_bit = pow(
        2,
        bits -
            1);  // 反轉後要加回answer的值。由於 2^0 對應到 2^31，初始值是 2^31

    for (int i = 0; i < bits; i++) {  // 從第0位處理到第31位
      index = n % 2;  //取出輸入n最右邊的2進位值，不是0就是1
      n /= 2;         //去掉輸入n的最右邊1位
      answer += index * add_bit;  //將answer加上對應的2進位反轉的值
      add_bit /= 2;               //下一個bit所代表的2進位值移1位
    }
    return answer;
  }
};

struct TestCaseStruct {
  uint32_t input;
  uint32_t expected_output;
};

int main(int argc, char *argv[]) {
  vector<TestCaseStruct> test_cases = {
      {0b00000010100101000001111010011100,
       964176192},  //輸入的測試資料和預期答案
      {0b11111111111111111111111111111101, 3221225471}};

  int test_case_index = 0;
  Solution solution;
  for (auto &test_case : test_cases) {
    if (solution.reverseBits(test_case.input) ==
        test_case.expected_output) {  //將回傳值和答案做比較
      cout << "test_case[" << test_case_index << "] is pass." << endl;
    } else {
      cout << "test_case[" << test_case_index << "] is fail." << endl;
    }
    ++test_case_index;
  }

  return 0;
}
