#include <bits/stdc++.h>

using namespace std;

typedef struct _Node {
  string name;
  _Node *child;
  _Node *sibling;
} Node;

Node *create_node(string name) {
  Node *newNode = new Node;
  newNode->name = name;
  newNode->child = nullptr;
  newNode->sibling = nullptr;
  return newNode;
}

void free_tree(Node *root, map<string, bool> &visited) {
  if (root == nullptr) {
    return;
  }

  visited[root->name] = true;

  free_tree(root->child, visited);
  free_tree(root->sibling, visited);

  cout << root->name << " ";

  delete root;
}

int descendants(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  int acc = 0;
  Node *p = root->child;

  while (p != nullptr) {
    acc += 1;
    acc += descendants(p);
    p = p->sibling;
  }

  return acc;
}

int generations(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  int maxDepth = 0;
  Node *p = root->child;

  while (p != nullptr) {
    maxDepth = std::max(maxDepth, generations(p));
    p = p->sibling;
  }

  return 1 + maxDepth;
}

int main() {
  string child;
  string parent;
  map<string, Node *> heads;
  map<string, bool> visited;

  // Tree generation
  while (true) {
    cin >> child;
    if (child == "***") {
      break;
    } else {
      cin >> parent;
      if (heads.find(parent) == heads.end()) {
        heads[parent] = create_node(parent);
        visited[parent] = false;
      }

      if (heads.find(child) == heads.end()) {
        heads[child] = create_node(child);
        visited[child] = false;
      }

      if (heads[parent]->child == nullptr) {
        heads[parent]->child = heads[child];
      } else {
        Node *last_sibling = heads[parent]->child;
        while (last_sibling->sibling != nullptr) {
          last_sibling = last_sibling->sibling;
        }
        last_sibling->sibling = heads[child];
      }
    }
  }
  // commands
  while (true) {
    cin >> child;
    if (child == "***") {
      break;
    } else if (child == "descendants") {
      cin >> parent;
      cout << descendants(heads[parent]) << '\n';
    } else if (child == "generation") {
      cin >> parent;
      cout << generations(heads[parent]) - 1 << '\n';
    }
  }
  /**/
  /*for (const auto &value : heads) {*/
  /*  Node *p = value.second;*/
  /*  if (!visited[p->name]) {*/
  /*    free_tree(p, visited);*/
  /*  }*/
  /*}*/
}
