#include <bits/stdc++.h>

using namespace std;

typedef struct _Node {
  int id;
  _Node *child;
  _Node *sibling;
} Node;

Node *create_node(int x) {
  Node *newNode = new Node;
  newNode->id = x;
  newNode->child = nullptr;
  newNode->sibling = nullptr;
  return newNode;
}

bool exists(Node *root, int id) {
  if (root == nullptr) {
    return false;
  }
  if (root->id == id) {
    return true;
  }
  return exists(root->child, id) || exists(root->sibling, id);
}

void in_order(Node *root) {
  if (root == nullptr) {
    return;
  }

  if (root->child != nullptr) {
    in_order(root->child);
  }

  cout << root->id << " ";

  if (root->child != nullptr) {
    Node *sibling = root->child->sibling;
    while (sibling != nullptr) {
      in_order(sibling);
      sibling = sibling->sibling;
    }
  }
}

void pre_order(Node *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->id << " ";

  Node *child = root->child;
  while (child != nullptr) {
    pre_order(child);
    child = child->sibling;
  }
}

void post_order(Node *root) {
  if (root == nullptr) {
    return;
  }

  Node *child = root->child;
  while (child != nullptr) {
    post_order(child);
    child = child->sibling;
  }

  cout << root->id << " ";
}
void free_tree(Node *root) {
  if (root == nullptr) {
    return;
  }

  free_tree(root->child);
  free_tree(root->sibling);

  delete root;
}

void insert(Node *root, int u, int v) {
  if (!exists(root, v) || exists(root, u)) {
    return;
  }

  if (root->id == v) {
    Node *newNode = create_node(u);
    if (root->child == nullptr) {
      root->child = newNode;
    } else {
      Node *last_sibling = root->child;
      while (last_sibling->sibling != nullptr) {
        last_sibling = last_sibling->sibling;
      }
      last_sibling->sibling = newNode;
    }
    return;
  }

  insert(root->child, u, v);
  insert(root->sibling, u, v);
}

int main() {
  string command;
  int x, y;
  Node *head = nullptr;
  while (true) {
    cin >> command;
    if (command == "*") {
      break;
    } else if (command == "MakeRoot") {
      cin >> x;
      head = create_node(x);
    } else if (command == "Insert") {
      cin >> x >> y;
      insert(head, x, y);
    } else if (command == "InOrder") {
      in_order(head);
      cout << '\n';
    } else if (command == "PreOrder") {
      pre_order(head);
      cout << '\n';
    } else if (command == "PostOrder") {
      post_order(head);
      cout << '\n';
    }
  }
  free_tree(head);
}
