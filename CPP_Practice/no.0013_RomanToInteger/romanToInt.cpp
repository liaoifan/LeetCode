#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int answer = 0;
    int number = 0;
    int serial[15] = {0};
    int length = 0;  //共幾個羅馬字母

    for (int i = 0; s[i] != '\0'; i++) {  //將字串轉成數字，並存入serial陣列中
      switch (s[i]) {
        case 'I':
          number = 1;
          break;
        case 'V':
          number = 5;
          break;
        case 'X':
          number = 10;
          break;
        case 'L':
          number = 50;
          break;
        case 'C':
          number = 100;
          break;
        case 'D':
          number = 500;
          break;
        case 'M':
          number = 1000;
          break;
        default:
          number = 0;
          break;
      }
      //		cout << s[i] << ":" << number << "\t" ;
      serial[i] = number;
      length = i;
    }

    for (int i = length; i >= 0; i--)  //計算答案的迴圈以及邏輯
    {
      if (i != length) {
        if (serial[i] < serial[i + 1])
          answer -= serial[i];
        else
          answer += serial[i];
      } else
        answer += serial[i];
    }

    //	cout <<"\nanswer:"<<  answer << endl;

    //	cout << endl;

    return answer;
  }
};

int main(int argc, char *argv[]) {
  string romanNumber[] = {"III",   "IV",      "IX",
                          "LVIII", "MCMXCIV", "MMMDCCCLXXXVIII"};

  Solution x;

  for (int i = 0; i < 6; i++) {
    x.romanToInt(romanNumber[i]);
  }

  return 0;
}
