#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/
class Solution {
 public:
  bool isValid(string s) {
    vector<char> input(
        s.begin(),
        s.end());  //先將輸入的string轉成vector<char>，以方便後續使用iterator操作
    vector<char>::iterator ptr;  //宣告一個iterator以操作vector

    if (input.size() % 2 !=
        0) {  // early return，輸入的字元數量如果不是偶數，直接return false
      return false;
    }
    /*
        cout << "input資料處理前：";  //印出處理前的資料
        for (ptr = input.begin(); ptr < input.end(); ptr++) {
          cout << *ptr;
        }
        cout << endl;
    */

    input.push_back(
        'a');  //處理之前，先隨便塞一個字元進到input後面，否則ptr+2運算到最後會出問題
    int times = input.size() /
                2;  //在worst case中，外層迴圈需要跑的次數為字串長度的一半
    for (int i = 0; i < times; i++) {
      for (
          ptr = input.begin(); ptr < input.end() - 1;
          ptr++) {  //用iterator走訪input，尋找相鄰的左右刮號"()"、"[]"、"{}"並將其移除
        if ((*ptr == '(' && *(ptr + 1) == ')') ||
            (*ptr == '[' && *(ptr + 1) == ']') ||
            (*ptr == '{' && *(ptr + 1) == '}')) {
          input.erase(ptr, ptr + 2);  //從input中移除相鄰的左右括號
          ptr--;  //因為移除資料需要將ptr向前offset 1
        }
      }
    }
    input.pop_back();  //將剛剛多塞入input的最後一個字元移除
                       /*
                           cout << "input資料處理後：";  //印出處理後的資料
                           for (ptr = input.begin(); ptr < input.end(); ptr++) {
                             cout << *ptr;
                           }
                           cout << endl;
                       */
    return input.empty();  //如果input被清空，則代表輸入為刮號為valid(return
                           // 1)；反之則為invalid(return 0)
  }
};

struct TestCaseStruct {
  string input;
  bool expected_output;
};

int main(int argc, char *argv[]) {
  vector<TestCaseStruct> test_cases = {{"()", true},  //輸入的測試資料和預期答案
                                       {"()[]{}", true}, {"(]", false},
                                       {"([)]", false},  {"{[]}", true},
                                       {"((", false}};

  int test_case_index = 0;
  Solution solution;
  for (auto &test_cases : test_cases) {
    if (solution.isValid(test_cases.input) ==
        test_cases.expected_output) {  //將回傳值和答案做比較
      cout << "test_case[" << test_case_index << "] is pass." << endl;
    } else {
      cout << "test_case[" << test_case_index << "] is fail." << endl;
    }
    ++test_case_index;
  }

  return 0;
}
