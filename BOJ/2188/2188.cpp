// 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 201;

std::vector<int> adj[MAX];
int A[MAX], B[MAX];
bool visited[MAX];
int n, m;

bool dfs(int a) {
  visited[a] = true;
  for (int b: adj[a]) {
    if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
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

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int s; cin >> s;
    for (int j = 0; j < s; ++j) {
      int x; cin >> x;
      x--;
      adj[i].push_back(x);
    }
  }

  int match = 0;
  std::fill(A, A+MAX, -1);
  std::fill(B, B+MAX, -1);
  for (int i = 0; i < n; ++i) {
    if (A[i] == -1) {
      std::fill(visited,visited+MAX,false);
      if (true == dfs(i)) match++;
    }
  }

  cout << match << '\n';
}
// g++ -o a -std=c++17 *.cpp