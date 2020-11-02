#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int max_odd_length = 0;
    int sum = 0;
    vector<int> subArray;

    if (arr.size() == 1) {  // early return
      return arr[0];
    }

    max_odd_length = (arr.size() % 2 == 0)
                         ? (arr.size() - 1)
                         : arr.size();  //算arr出最長的奇數長度

    // 3層迴圈
    // k：控制 subArray的長度 1、3、5、...、max_odd_length
    // j：控制 單一長度的subArray，第幾個subArray 1、2、3、...、arr.size()-k+1
    // i：控制 單一subArray中，第幾個數值
    for (int k = 1; k <= max_odd_length; k += 2) {
      // cout << "subArray長度" << k << "時" << endl ;
      for (int j = 1; j <= arr.size() - k + 1; j++) {
        // cout << "第" << j << "組subArray：" ;
        for (int i = 0; i < k; i++) {
          sum += arr[i + (j - 1)];
          // cout << arr[i+j] << " " ;
        }
        // cout << endl;
      }
      // cout << endl;
    }
    return sum;
  }
};

struct TestCaseStruct {
  vector<int> input;
  int expected_output;
};

int main(int argc, char *argv[]) {
  vector<TestCaseStruct> test_cases = {
      {{1, 4, 2, 5, 3}, 58}, {{1, 2}, 3}, {{10, 11, 12}, 66}, {{1}, 1}};
  Solution solution;
  int test_case_index = 0;
  for (auto &test_case : test_cases) {
    if (solution.sumOddLengthSubarrays(test_case.input) ==
        test_case.expected_output) {
      cout << "test case [" << test_case_index << "] is pass."
           << "\n\n";
    } else {
      cout << "test case [" << test_case_index << "] is fail."
           << "\n\n";
    }
    test_case_index++;
  }
  return 0;
}
