#include <malloc.h>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;         //這個ListNode裡面存的值
  ListNode *next;  //宣告一個指向ListNode變數的指標next
  ListNode()
      : val(0),
        next(nullptr) {
  }  // 當使用ListNode時，不使用任何引數，則新建一個ListNode，val設為0；next為nullptr
  ListNode(int x)
      : val(x),
        next(nullptr) {
  }  // 當使用ListNode時，若有引入int，則新建一個ListNode，val設為引入指；next為nullptr
  ListNode(int x, ListNode *next)
      : val(x),
        next(next) {
  }  // 當使用ListNode時，若有引入int 和指標，val 和 next皆設為引入值
};

// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    //先將2個 linked list 轉成2個vector
    vector<int> num1;
    vector<int> num2;
    vector<int>::iterator iter;

    struct ListNode *ptr;

    ptr = l1;
    while (ptr != nullptr) {
      num1.push_back(ptr->val);
      ptr = ptr->next;
    }

    ptr = l2;
    while (ptr != nullptr) {
      num2.push_back(ptr->val);
      ptr = ptr->next;
    }

    //將2個vecotr合併：將num1 後面塞入 num2
    num1.insert(num1.end(), num2.begin(), num2.end());

    //將vector以遞增作排序
    sort(num1.begin(), num1.end(), less<int>());

    //將vector num1轉成Linked List
    struct ListNode *head, *newptr;
    for (iter = num1.begin(); iter != num1.end(); iter++) {
      newptr = (struct ListNode *)malloc(
          sizeof(struct ListNode));  //配置一塊可容納 ListNode
                                     //結構的記憶體，並將啟始位址給newptr
      newptr->val = *iter;  // Node內的變數賦值
      newptr->next =
          nullptr;  // Node內的next指標設為NULL，因為如果沒有下一個Node的話，這就是最後一個Node了

      if (iter == num1.begin()) {
        head = ptr = newptr;  // head1只在第1次更新，以保留最開頭的位置
      } else {
        ptr->next =
            newptr;  //把上一個Node的next指標從NULL更新為目前這一個Node的位址，如果是第1次不用做這件事
        ptr = newptr;  //更新ptr1為最新的位址
      }
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  vector<int> L1 = {1, 2, 4};
  vector<int> L2 = {1, 3, 4};

  vector<int>::iterator iter1;
  vector<int>::iterator iter2;

  /*
          Linked List的3種指標功能說明：

          newptr指標：
     負責儲存新分配的記憶體的起始位址，每開一個新的記憶體就會被更新一次

          head指標：		存放整個Linked
     List的第一個Node的位址，所以只會被賦值一次，Linked List最重要的資訊

          ptr指標：		功能1：ptr =
     newptr，將目前的位址存下來，當newptr被更新之後還指在前一個node
                                          功能2：ptr->next =
     newptr，當新的node被建立好之後，把前一個node連上新的node
  */

  //由L1[]產生Linked List l1
  struct ListNode *head1, *ptr1, *newptr1;
  for (iter1 = L1.begin(); iter1 != L1.end(); iter1++) {
    newptr1 = (struct ListNode *)malloc(
        sizeof(struct ListNode));  //配置一塊可容納 ListNode
                                   //結構的記憶體，並將啟始位址給newptr
    newptr1->val = *iter1;  // Node內的變數賦值
    newptr1->next =
        nullptr;  // Node內的next指標設為NULL，因為如果沒有下一個Node的話，這就是最後一個Node了

    if (iter1 == L1.begin()) {
      head1 = ptr1 = newptr1;  // head1只在第1次更新，以保留最開頭的位置
    } else {
      ptr1->next =
          newptr1;  //把上一個Node的next指標從NULL更新為目前這一個Node的位址，如果是第1次不用做這件事
      ptr1 = newptr1;  //更新ptr1為最新的位址
    }
  }

  //由L2[]產生Linked List l2
  struct ListNode *head2, *ptr2, *newptr2;
  for (iter2 = L2.begin(); iter2 != L2.end(); iter2++) {
    newptr2 = (struct ListNode *)malloc(
        sizeof(struct ListNode));  //配置一塊可容納 ListNode
                                   //結構的記憶體，並將啟始位址給newptr
    newptr2->val = *iter2;  // Node內的變數賦值
    newptr2->next =
        nullptr;  // Node內的next指標設為NULL，因為如果沒有下一個Node的話，這就是最後一個Node了

    if (iter2 == L2.begin()) {
      head2 = ptr2 = newptr2;  // head只在第1次更新，以保留最開頭的位置
    } else {
      ptr2->next =
          newptr2;  //把上一個Node的next指標從NULL更新為目前這一個Node的位址，如果是第1次不用做這件事
      ptr2 = newptr2;  //更新ptr1為最新的位址
    }
  }

  Solution solution;

  struct ListNode *ptr;

  //印出所有L1資料
  ptr = solution.mergeTwoLists(head1, head2);
  while (ptr != nullptr) {
    cout << ptr->val;
    ptr = ptr->next;
  }
  cout << endl;

  /*
          struct ListNode *ptr;

          //印出所有L1資料
          ptr = head1;
          while( ptr != nullptr) {
                  cout << ptr->val << "\n" ;
                  ptr = ptr->next;
          }

          //印出所有L2資料
          ptr = head2;
          while( ptr != nullptr) {
                  cout << ptr->val << "\n" ;
                  ptr = ptr->next;
          }
  */

  return 0;
}
