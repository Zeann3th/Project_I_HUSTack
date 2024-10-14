#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  struct _Node *left;
  struct _Node *right;
  int value;
} Node;

Node *createnode(int x);
void preorder(Node *root);
void insert(Node *p, Node **root);
void freetree(Node *root);

int main() {
  int x;
  char s[10];
  Node *head = NULL;

  while (1) {
    scanf("%s", s);
    if (strcmp(s, "insert") == 0) {
      scanf("%d", &x);
      if (head == NULL) {
        head = createnode(x);
      } else {
        insert(createnode(x), &head);
      }
    } else if (strcmp(s, "#") == 0) {
      break;
    }
  }

  preorder(head);
  printf("\n");

  freetree(head);
  return 0;
}

Node *createnode(int x) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = x;
  newNode->right = newNode->left = NULL;
  return newNode;
}

void freetree(Node *root) {
  if (root == NULL) {
    return;
  }

  freetree(root->right);
  freetree(root->left);

  free(root);
}

void insert(Node *p, Node **root) {
  if (*root == NULL) {
    *root = p;
    return;
  }

  if (p->value > (*root)->value) {
    if ((*root)->right != NULL) {
      insert(p, &((*root)->right));
    } else {
      (*root)->right = p;
    }
  } else {
    if ((*root)->left != NULL) {
      insert(p, &((*root)->left));
    } else {
      (*root)->left = p;
    }
  }
}

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->value);
  preorder(root->left);
  preorder(root->right);
}
