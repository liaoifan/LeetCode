#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//宣告一個名叫Solution的類別
class Solution {
 public:
  //宣告一個public的方法，其回傳資料是vector<int>
  //引入資料是(vector<int> &nums, int target)
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer(2);

    for (unsigned int i = 0; i < nums.size(); i++) {
      for (unsigned int j = i + 1; j < nums.size(); j++) {
        if ((nums[i] + nums[j]) == target) {
          answer[0] = i;
          answer[1] = j;
          break;
        }
      }
    }

    return answer;
  }
};

int main(int argc, char* argv[]) {
  Solution Answer;

  vector<int> container;       //建立一個名叫container的vector容器
  container = {2, 7, 11, 15};  //將容器中塞入一些測試用的數值
  int target = 9;              //將目標設為9

  Answer.twoSum(container, target);

  return 0;
}
