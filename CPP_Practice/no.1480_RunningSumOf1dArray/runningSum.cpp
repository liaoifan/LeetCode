#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> answer;
    vector<int>::iterator ptr;
    int sum = 0;

    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      sum += *ptr;
      answer.push_back(sum);
    }
    return answer;
  }
};

struct TestCaseStruct {
  vector<int> input;
  vector<int> expected_output;
};

int main(int argc, char *argv[]) {
  vector<TestCaseStruct> test_cases = {{{1, 2, 3, 4}, {1, 3, 6, 10}},
                                       {{1, 1, 1, 1, 1}, {1, 2, 3, 4, 5}},
                                       {{3, 1, 2, 10, 1}, {3, 4, 6, 16, 17}}};

  Solution solution;

  int test_case_index = 0;

  for (auto &test_case : test_cases) {
    if (solution.runningSum(test_case.input) == test_case.expected_output) {
      cout << "test case [" << test_case_index << "] is pass." << endl;
    } else {
      cout << "test case [" << test_case_index << "] is fail." << endl;
    }
    test_case_index++;
  }
  return 0;
}
