#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int>::iterator ptr;

    cout << "排序前：";
    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      cout << *ptr;
    }
    cout << endl;

    bool flag = 1;  //檢查輸入是否全為0的flag

    //先檢查輸入的vector是否全為0
    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      if (*ptr != 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      return;
    }

    int zeroes = 0;
    //		vector<int>::iterator ptr_end = nums.end();
    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      if (*ptr == 0) {
        nums.erase(ptr);
        ptr--;
        zeroes++;
        //		nums.push_back(0);
      }
    }

    for (int i = 0; i < zeroes; i++) {
      nums.push_back(0);
    }

    cout << "排序後：";
    for (ptr = nums.begin(); ptr != nums.end(); ptr++) {
      cout << *ptr;
    }
    cout << endl;
  }
};

int main(int argc, char* argv[]) {
  vector<int> input = {0, 0, 1};
  vector<int> output = {1, 0, 0};

  Solution solution;

  solution.moveZeroes(input);

  return 0;
}
