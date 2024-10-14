#include <bits/stdc++.h>
#include <iterator>

using namespace std;

bool contains(list<int> l1, int z) {
  for (list<int>::iterator ptr = l1.begin(); ptr != l1.end(); ptr++) {
    if (*ptr == z) {
      return true;
    }
  }
  return false;
}

void print(list<int> l1) {
  list<int>::iterator ptr;
  for (ptr = l1.begin(); ptr != l1.end(); ptr++) {
    cout << *ptr << " ";
  }
  cout << '\n';
}

int main() {
  int n, x, y;
  list<int> liszt;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    liszt.push_back(x);
  }
  string command;

  while (true) {
    cin >> command;
    if (command == "addlast") {
      cin >> x;
      if (!contains(liszt, x)) {
        liszt.push_back(x);
      }
    } else if (command == "addfirst") {
      cin >> x;
      if (!contains(liszt, x)) {
        liszt.push_front(x);
      }
    } else if (command == "addafter") {
      cin >> x;
      cin >> y;
      if (contains(liszt, y) && !contains(liszt, x)) {
        list<int>::iterator ptr = find(liszt.begin(), liszt.end(), y);
        advance(ptr, 1);
        liszt.insert(ptr, x);
      }
    } else if (command == "addbefore") {
      cin >> x;
      cin >> y;
      if (contains(liszt, y) && !contains(liszt, x)) {
        list<int>::iterator ptr = find(liszt.begin(), liszt.end(), y);
        liszt.insert(ptr, x);
      }
    } else if (command == "remove") {
      cin >> x;
      liszt.remove(x);
    } else if (command == "reverse") {
      liszt.reverse();
    } else if (command == "#") {
      break;
    }
  }
  print(liszt);
}
