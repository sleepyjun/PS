// https://www.acmicpc.net/problem/1867
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 501;

int A[MAX], B[MAX];
bool visited[MAX];
std::vector<int> adj[MAX];

bool dfs(int a) {
  if (true == visited[a]) return false;
  visited[a] = true;

  for (int b: adj[a]) {
    if (B[b] == -1 || dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return true;
    }
  }
  return false;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, k; cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int y,x; cin >> y >> x;
    adj[y].push_back(x);
  }

  int match = 0;
  std::fill(A, A+MAX, -1);
  std::fill(B, B+MAX, -1);
  for (int i = 1; i <= n; ++i) {
    std::fill(visited, visited+MAX, false);
    if (true == dfs(i)) match++;
  }
  cout << match << '\n';
}
// g++ -o a -std=c++17 *.cpp