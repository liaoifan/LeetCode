#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
  struct ListNode* search_node = head;
  struct ListNode* tail_node;
  int counter = 0;
  int offset = 0;

  if (head == NULL || head->next == NULL) {
    return head;
  }

  //先將linked list接成一個loop
  counter = 1;
  while (search_node->next != NULL) {
    search_node = search_node->next;
    ++counter;
  }
  tail_node = search_node;
  search_node->next = head;

  offset = k % counter;
  //再將head位移counter-offset 次
  for (int i = 0; i < counter - offset; i++) {
    head = head->next;
  }

  //將最後一個位置接到NULL
  search_node = tail_node;
  for (int i = 0; i < counter - offset; i++) {
    search_node = search_node->next;
  }
  search_node->next = NULL;

  printf("Linked List總長度為%d\n", counter);

  return head;
}

int main(int argc, char* argv[]) {
  int data[] = {1, 2, 3, 4, 5};
  int size_data = sizeof(data) / sizeof(data[0]);
  struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
  head->val = 0;
  head->next = NULL;
  struct ListNode* ptr;

  ptr = head;
  for (int i = 0; i < size_data; i++) {
    ptr->val = data[i];
    if (i == size_data - 1) {
      ptr->next = NULL;
    } else {
      ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    }
    ptr = ptr->next;
  }

  printf("位移前：\n");
  ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->val);
    ptr = ptr->next;
  }
  printf("\n");

  int k = 11;
  printf("位移%d後：\n", k);
  ptr = rotateRight(head, k);
  while (ptr != NULL) {
    printf("%d ", ptr->val);
    ptr = ptr->next;
  }
  printf("\n");

  return 0;
}
