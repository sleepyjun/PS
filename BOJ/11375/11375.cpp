// https://www.acmicpc.net/problem/11375
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 1001;

int A[MAX], B[MAX];
bool visited[MAX];
std::vector<int> adj[MAX];

bool dfs(int a) {
  if (true == visited[a]) return false;
  visited[a] = true;

  for (int b: adj[a]) {
    // b가 매칭되어 있지 않거나
    // 매칭되어있을 경우 매칭된 A점이 다른점으로 매칭가능한지 판별함
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

  int n, m; cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    while (t--) {
      int x; cin >> x;
      adj[i].push_back(x-1);
    }
  }

  int match(0);
  std::fill(A, A+MAX, -1);
  std::fill(B, B+MAX, -1);
  for (int i = 0; i < n; ++i) {
    std::fill(visited, visited+MAX, false);
    if (true == dfs(i)) match++;
  }
  cout << match << '\n';
}
// g++ -o a -std=c++17 *.cpp