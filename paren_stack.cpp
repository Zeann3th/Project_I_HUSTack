#include <bits/stdc++.h>

int check(std::string s, std::map<char, char> map) {
  std::stack<char> stack;
  for (char e : s) {
    /*std::cout << e;*/
    if (map.count(e)) {
      stack.push(e);
    } else if (!stack.empty() && e == map.at(stack.top())) {
      stack.pop();
    } else {
      return 0;
    }
  }
  return stack.empty() ? 1 : 0;
}

int main() {
  std::map<char, char> map;
  map['('] = ')';
  map['{'] = '}';
  map['['] = ']';

  std::string s;
  std::cin >> s;
  std::cout << check(s, map);
}
