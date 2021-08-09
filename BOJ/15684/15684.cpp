// https://www.acmicpc.net/problem/15684
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int N,M,H;

bool line[40][20]; // 높이와 세로선

inline bool run() {
  for (int i = 1; i <= N; ++i) {
    int r = i;
    for(int j = 1; j <= H; ++j) {
      if (line[j][r-1]) r--;
      else if (line[j][r]) r++;
    }
    if (r != i) return false;
  }
  return true;
}

int limit;
bool find = false;
void dfs(int h=1, int cnt=0) {
  if (true == find) return;
  if (cnt == limit) {
    if (true == run()) find = true;
    return;
  }

  for (int i = h; i <= H; ++i) {
    for(int j = 1; j <= N-1; ++j) {
      if (true == find) return;
      if (true == line[i][j]) continue;
      if (line[i][j-1] || line[i][j+1]) continue;
      line[i][j] = true;
      dfs(i, cnt+1);
      line[i][j] = false;
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M >> H;

  for (int i = 0; i < M; ++i) {
    int a,b; cin >> a >> b;
    line[a][b] = true;
  }

  for (;limit <= 3; ++limit) {
    dfs();
    if (true == find) {
      cout << limit << '\n';
      return 0;
    }
  }
  
  cout << -1 << '\n';
}
// g++ -o a -std=c++17 *.cpp