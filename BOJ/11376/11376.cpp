// https://www.acmicpc.net/problem/11376
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 2001;

int A[MAX], B[MAX];
int visited[MAX], visitCount;
std::vector<int> adj[MAX];

bool dfs(int a) {
  if (visited[a] == visitCount) return false;
  visited[a] = visitCount;

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

  int n, m; cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    while (t--) {
      int x; cin >> x;
      adj[i*2].push_back(x);
      adj[i*2+1].push_back(x);
    }
  }

  int match = 0;
  std::fill(A, A+MAX, -1);
  std::fill(B, B+MAX, -1);
  for (int i = 0; i < n*2; ++i) {
    visitCount++;
    match += dfs(i);
  }

  cout << match << '\n';
}
// g++ -o a -std=c++17 *.cpp