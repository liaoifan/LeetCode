#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int val;
  struct MyLinkedList* next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
  MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  head->val = -1;
  head->next = NULL;
  return head;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
  if (obj == NULL) {
    return -1;
  }

  MyLinkedList* search_index_node = obj;
  int search_index = 0;

  while (search_index != index && search_index_node->next != NULL) {
    ++search_index;
    search_index_node = search_index_node->next;
  }

  if (search_index == index) {
    return search_index_node->val;
  } else {
    return -1;
  }
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  if (obj->val == -1) {
    obj->val = val;
    return;
  }

  MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  temp->val = obj->val;
  temp->next = obj->next;
  obj->val = val;
  obj->next = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  if (obj == NULL) {
    myLinkedListAddAtHead(obj, val);
    return;
  }

  if (obj->val == -1) {
    myLinkedListAddAtHead(obj, val);
    return;
  }

  MyLinkedList* search_last_node = obj;
  while (search_last_node->next != NULL) {
    search_last_node = search_last_node->next;
  }
  MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  temp->val = val;
  temp->next = NULL;
  search_last_node->next = temp;
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not be
 * inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  if (index < 0) {  // return index < 0 的所有狀況
    return;
  } else if (obj == NULL && index == 0) {  //處理長度為0的所有狀況
    myLinkedListAddAtHead(obj, val);
    return;
  } else if (obj == NULL && index != 0) {
    return;
  }

  if (index == 0) {
    myLinkedListAddAtHead(obj, val);
    return;
  }

  MyLinkedList* search_node_old = NULL;
  MyLinkedList* search_node_new = obj;
  for (int i = 0; i < index; i++) {
    search_node_old = search_node_new;
    search_node_new = search_node_new->next;
  }

  MyLinkedList* insert = (MyLinkedList*)malloc(sizeof(MyLinkedList));
  insert->val = val;
  insert->next = search_node_new;
  search_node_old->next = insert;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  if (index < 0) {  // return index < 0 的所有狀況
    return;
  } else if (obj == NULL) {  // return 長度為0的所有狀況
    return;
  } else if (obj->next == NULL &&
             index ==
                 0) {  // return 長度為1的所有狀況，長度為1不能把最後1個node砍掉
    return;
  }

  if (index == 0) {
    MyLinkedList* temp = obj->next;
    obj->val = temp->val;
    obj->next = temp->next;
    free(temp);
    return;
  }

  MyLinkedList* search_node_old = NULL;
  MyLinkedList* search_node_new = obj;

  for (int i = 0; i < index; i++) {
    search_node_old = search_node_new;
    search_node_new = search_node_new->next;
    if (search_node_new == NULL) {
      return;
    }
  }

  MyLinkedList* temp = search_node_new->next;
  if (search_node_old != NULL) {
    search_node_old->next = temp;
  } else {
    obj = temp;
  }
  free(search_node_new);
}

void myLinkedListFree(MyLinkedList* obj) {
  if (obj == NULL) {
    return;
  }

  MyLinkedList* temp_old;
  MyLinkedList* temp_new;

  temp_old = obj;
  obj = NULL;
  while (temp_old != NULL) {
    temp_new = temp_old->next;
    free(temp_old);
    temp_old = temp_new;
  }
}
void printLinkedList(MyLinkedList* obj) {
  if (obj == NULL) {
    return;
  }
  MyLinkedList* temp = obj;
  int i = 0;
  while (temp != NULL) {
    printf("[%d]%d ", i, temp->val);
    ++i;
    temp = temp->next;
  }
  printf("\n");
}

/*
  Your MyLinkedList struct will be instantiated and called as such:

  MyLinkedList* obj = myLinkedListCreate();

  int param_1 = myLinkedListGet(obj, index);

  myLinkedListAddAtHead(obj, val);

  myLinkedListAddAtTail(obj, val);

  myLinkedListAddAtIndex(obj, index, val);

  myLinkedListDeleteAtIndex(obj, index);

  myLinkedListFree(obj);
*/

int main(int argc, char* argv[]) {
  printf("\n創造一個Linked List\n");
  MyLinkedList* head = myLinkedListCreate();
  printLinkedList(head);
  printf("\n");

  printf("在[0]加上10\n");
  myLinkedListAddAtIndex(head, 0, 10);
  printLinkedList(head);
  printf("\n");

  printf("在[0]加上20\n");
  myLinkedListAddAtIndex(head, 0, 20);
  printLinkedList(head);
  printf("\n");

  printf("在[1]加上30\n");
  myLinkedListAddAtIndex(head, 1, 30);
  printLinkedList(head);
  printf("\n");

  printf("第[%d]的資料是%d\n", 0, myLinkedListGet(head, 0));
  printLinkedList(head);
  printf("\n");

  return 0;
}
