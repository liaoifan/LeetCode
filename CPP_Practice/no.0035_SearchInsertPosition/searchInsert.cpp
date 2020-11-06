#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    vector<int>::iterator ptr;
    int i = 0;  //計算目前指到第幾個位置

    for (ptr = nums.begin(); ptr != nums.end(); ++ptr) {
      if (target <= *ptr) {
        return i;
      }
      ++i;
    }
    return i;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 3, 5, 6};
  int target = 0;

  Solution solution;

  cout << solution.searchInsert(nums, target) << endl;
}
