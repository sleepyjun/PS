// https://www.acmicpc.net/problem/10021 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using info = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<info> edge;
int p[2001];

int calc(const pii &a, const pii &b) {
  return (a.first - b.first) * (a.first - b.first) + 
        (a.second - b.second) * (a.second - b.second);
}

int find(int u) {
  if (p[u] == -1) return u;
  return p[u] = find(p[u]);
}
bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  p[v] = u;
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n, c; cin >> n >> c;
  std::vector<pii> v;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    v.push_back({x, y});
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int w = calc(v[i], v[j]);
      if (w < c) continue;

      edge.push_back({w, i, j});
      edge.push_back({w, j, i});
    }
  }

  std::sort(edge.begin(), edge.end());
  std::fill(p, p+2001, -1);

  int result = 0, cnt = 0;

  for (int i = 0; i < edge.size(); ++i) {
    int w, u, v;
    std::tie(w, u, v) = edge[i];

    if (merge(u, v)) {
      result += w;
      cnt++;
      if (cnt == n-1) break;
    }
  }

  cout << (cnt == n-1 ? result : -1) << '\n';
}
// g++ -o a -std=c++17 *.cpp