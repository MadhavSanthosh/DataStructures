#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node {
  int val;
  struct node *next;
};
struct node *head;

void main() {
  int choice = 0;
  while (choice != 4) {
    printf("\n\nChose one from the below options...\n");
    printf("\n1.Push\n2.Pop\n3.Show\n4.Exit\n");
    printf("Enter choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      push();
      break;
    }
    case 2: {
      pop();
      break;
    }
    case 3: {
      display();
      break;
    }
    case 4: {
      break;
    }
    default: {
      printf("Enter valid choice\n ");
    }
    };
  }
}
void push() {
  int val;
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL) {
    printf("Not able to push the element\n");
  } else {
    printf("Enter the value\n");
    scanf("%d", &val);
    if (head == NULL) {
      ptr->val = val;
      ptr->next = NULL;
      head = ptr;
    } else {
      ptr->val = val;
      ptr->next = head;
      head = ptr;
    }
    printf("Item pushed");
  }
}

void pop() {
  int item;
  struct node *ptr;
  if (head == NULL) {
    printf("Underflow\n");
  } else {
    item = head->val;
    ptr = head;
    head = head->next;
    free(ptr);
    printf("Item popped : %d\n", item);
  }
}
void display() {
  int i;
  struct node *ptr;
  ptr = head;
  if (ptr == NULL) {
    printf("Stack is empty\n");
  } else {
    printf("Printing Stack elements \n");
    while (ptr != NULL) {
      printf("%d\n", ptr->val);
      ptr = ptr->next;
    }
  }
}