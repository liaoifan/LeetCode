#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty() == true) {  // early return
      return string("");
    }

    string prefix = "";   //最後要回傳的答案字串
    char compare = '\0';  //存放第0個字串中，目前拿來比對的字元
    string compareString;  //存放目前正在比較的字串
    bool flag = false;     //確認字元比對是否成功的flag

    string startString = strs[0];  //存放第0個字串

    for (int i = 0; startString[i] != '\0';
         i++) {  //控制拿第0個字串中第幾個字元出來比較的迴圈

      compare = startString[i];

      for (
          unsigned int j = 1; j < strs.size();
          j++) {  //控制和第幾個字串比較的迴圈，因為第0個字串已經被拿來比較了，所以從第1個字串開始比

        compareString = strs[j];  //將要拿來比較的字串放入compareString中

        flag = true;  //比較前，先將比較成功的flag設為true
        if (compare !=
            compareString
                [i]) {  //比對到字元不同，則將flag設為false，並停止比較迴圈
          flag = false;
          break;
        }
      }

      if (flag == true)
        prefix += compare;
      else if (flag == false)
        break;
    }

    return prefix;
  }
};

int main(int argc, char* argv[]) {
  Solution answer;
  // vector <string> test = {"flower","flow","flow"};
  vector<string> test = {};

  cout << answer.longestCommonPrefix(test) << endl;

  return 0;
}
