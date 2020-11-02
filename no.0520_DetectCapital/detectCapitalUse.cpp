#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    bool valid = true;
    string::iterator ptr;
    ptr = word.begin();
    int num = 0;

    // early return：字串長度只有1就一定OK
    if (word.size() == 1) {
      return valid;
    }

    //先判斷是單字大小寫的開頭是AA、Aa、aa的型式：AA => 1 、Aa => 2 、aa =>
    //3、其他 => false

    if (isupper(*ptr) && isupper(*(ptr + 1))) {  // AA開頭
      num = 1;
    } else if (isupper(*ptr) && islower(*(ptr + 1))) {  // Aa開頭
      num = 2;
    } else if (islower(*ptr) && islower(*(ptr + 1))) {  // aa開頭
      num = 3;
    } else {
      valid = false;
    }

    switch (num) {
      case 1:  // AA開頭：從第0個檢查到最後，有小寫出現的話則為fasle
        for (ptr = word.begin(); ptr != word.end(); ptr++) {
          if (islower(*ptr)) {
            valid = false;
            break;
          }
        }
        break;

      case 2:  // Aa開頭，從第1個檢查到最後，有大寫出現的話則為false
        for (ptr = word.begin() + 1; ptr != word.end(); ptr++) {
          if (isupper(*ptr)) {
            valid = false;
            break;
          }
        }
        break;

      case 3:  // aa開頭，從第0個檢查到最後，有大寫出現的話則為false
        for (ptr = word.begin(); ptr != word.end(); ptr++) {
          if (isupper(*ptr)) {
            valid = false;
            break;
          }
        }
        break;
    }
    return valid;
  }
};

struct TestCaseStruct {
  string input;
  bool expected_output;
};

int main(int argc, char *argv[]) {
  vector<TestCaseStruct> test_cases = {
      {"USA", true},  //輸入的測試資料和預期答案
      {"FlAG", false},
      {"leetcode", true},
      {"Google", true}};

  int test_case_index = 0;
  Solution solution;
  for (auto &test_case : test_cases) {
    if (solution.detectCapitalUse(test_case.input) ==
        test_case.expected_output) {  //將回傳值和答案做比較
      cout << "test_case[" << test_case_index << "] is pass." << endl;
    } else {
      cout << "test_case[" << test_case_index << "] is fail." << endl;
    }
    ++test_case_index;
  }

  return 0;
}
