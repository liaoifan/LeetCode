#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    vector<int>::iterator ptr;

    if (nums.empty() == 1) {
      return 0;
    } else if (nums.size() == 1) {
      return 1;
    }

    for (ptr = nums.begin() + 1; ptr != nums.end(); ptr++) {
      if (*ptr == *(ptr - 1)) {
        nums.erase(ptr - 1);
        ptr--;
      }
    }

    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      cout << *ptr << "\t";
    }
    cout << endl;

    return nums.size();
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4};
  vector<int> ans = {0, 1, 2, 3, 4};

  Solution solution;

  cout << solution.removeDuplicates(nums);
}
