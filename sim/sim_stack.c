#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  int value;
  struct _Node *next;
} Node;

Node *createnode(int x) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = x;
  newNode->next = NULL;
  return newNode;
}

void printlist(Node *root) {
  if (root != NULL) {
    printf("%d ", root->value);
    printlist(root->next);
  } else {
    printf("%s", "NULL");
  }
}

void push(Node **root, int x) {
  Node *p = createnode(x);
  p->next = *root;
  *root = p;
}

void pop(Node **root) {
  if (*root == NULL) {
    printf("%s\n", "NULL");
    return;
  }

  Node *tmp = *root;
  int value = (*root)->value;
  *root = (*root)->next;
  free(tmp);

  printf("%d\n", value);
}

void freeStack(Node **root) {
  while (*root != NULL) {
    Node *tmp = *root;
    *root = (*root)->next;
    free(tmp);
  }
}

int main() {
  char command[4];
  int x;
  Node *head = NULL;

  while (1) {
    scanf("%s", command);
    if (strcmp(command, "PUSH") == 0) {
      scanf("%d", &x);
      push(&head, x);
    } else if (strcmp(command, "POP") == 0) {
      pop(&head);
    } else if (strcmp(command, "#") == 0) {
      break;
    }
    /*printlist(head);*/
    /*printf("\n");*/
  }
  freeStack(&head);
}
