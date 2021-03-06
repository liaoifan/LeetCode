#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int answer = 0;     //答案
    int remainder = 0;  //餘數
    int temp = 0;  //拿來暫存輸入x的值，避免改到原始的輸入

    temp = abs(x);  //將輸入x轉成整數方便後續運算

    while (temp > 0) {
      if ((answer >= 214748364)) {  //溢位條件判斷，當運算值要超過
                                    //(2^31-1)=2147483647 直接 return 0
        if ((answer == 214748364) && (temp % 10 <= 7)) {
        } else
          return 0;
      }
      remainder = temp % 10;             // 取輸入temp的最後一位數
      answer = answer * 10 + remainder;  // 將取到的餘數塞入answer的個位數
      temp = temp / 10;                  // 移除temp的最後一位數
    }

    return (x > 0) ? answer : -answer;
  }
};

int main(int argc, char *argv[]) {
  int a[] = {123, -123, 120, 0, 1534236469};

  Solution x;

  for (int i = 0; i < 5; i++) {
    cout << a[i] << "\t" << x.reverse(a[i]) << endl;
  }

  return 0;
}
