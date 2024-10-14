#include <bits/stdc++.h>

using namespace std;

int main() {
  queue<int> s;
  int n;
  string command;
  while (true) {
    cin >> command;
    if (command == "PUSH") {
      cin >> n;
      s.push(n);
    } else if (command == "POP") {
      if (s.empty()) {
        cout << "NULL\n";
        continue;
      }
      cout << s.front() << '\n';
      s.pop();
    } else if (command == "#") {
      break;
    }
  }
  return 0;
}
