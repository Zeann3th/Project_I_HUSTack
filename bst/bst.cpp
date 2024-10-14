#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node *left;
  Node *right;
  int value;
};

Node *createnode(int x);
void preorder(Node *root);
void insert(Node *p, Node *&root);
void freetree(Node *root);

int main() {
  int x;
  string s;
  Node *head = nullptr;

  while (true) {
    cin >> s;
    if (s == "insert") {
      cin >> x;
      if (head == nullptr) {
        head = createnode(x);
      } else {
        insert(createnode(x), head);
      }
    } else if (s == "#") {
      break;
    }
  }

  preorder(head);
  cout << '\n';

  freetree(head);
  return 0;
}

Node *createnode(int x) {
  Node *newNode = new Node;
  newNode->value = x;
  newNode->right = newNode->left = nullptr;
  return newNode;
}

void freetree(Node *root) {
  if (root == nullptr) {
    return;
  }

  freetree(root->right);
  freetree(root->left);

  delete root;
}

void insert(Node *p, Node *&root) {
  if (root == nullptr) {
    root = p;
    return;
  }

  if (p->value > root->value) {
    if (root->right != nullptr) {
      insert(p, root->right);
    } else {
      root->right = p;
    }
  } else if (p->value < root->value) {
    if (root->left != nullptr) {
      insert(p, root->left);
    } else {
      root->left = p;
    }
  }
}

void preorder(Node *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->value << " ";
  preorder(root->left);
  preorder(root->right);
}
