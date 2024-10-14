#include <bits/stdc++.h>
using namespace std;

int minSteps(int m, int n, int d) {
  if (d > max(m, n))
    return -1;
  queue<vector<int>> q;
  vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
  q.push({0, 0, 0});
  visited[0][0] = true;

  while (!q.empty()) {

    auto curr = q.front();
    q.pop();

    int jug1 = curr[0];
    int jug2 = curr[1];
    int steps = curr[2];

    if (jug1 == d || jug2 == d)
      return steps;
    if (!visited[m][jug2]) {
      visited[m][jug2] = true;
      q.push({m, jug2, steps + 1});
    }
    if (!visited[jug1][n]) {
      visited[jug1][n] = true;
      q.push({jug1, n, steps + 1});
    }
    if (!visited[0][jug2]) {
      visited[0][jug2] = true;
      q.push({0, jug2, steps + 1});
    }
    if (!visited[jug1][0]) {
      visited[jug1][0] = true;
      q.push({jug1, 0, steps + 1});
    }
    int pour1to2 = min(jug1, n - jug2);
    if (!visited[jug1 - pour1to2][jug2 + pour1to2]) {
      visited[jug1 - pour1to2][jug2 + pour1to2] = true;
      q.push({jug1 - pour1to2, jug2 + pour1to2, steps + 1});
    }
    int pour2to1 = min(jug2, m - jug1);
    if (!visited[jug1 + pour2to1][jug2 - pour2to1]) {
      visited[jug1 + pour2to1][jug2 - pour2to1] = true;
      q.push({jug1 + pour2to1, jug2 - pour2to1, steps + 1});
    }
  }
  return -1;
}

int main() {

  int a, b, c;
  cin >> a >> b >> c;
  cout << minSteps(a, b, c);
  return 0;
}
