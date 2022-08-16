// https://www.acmicpc.net/problem/24479
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> adj[100001];
bool visited[100001];
int result[100001];

void bfs(int node) {
  int index = 1;
  std::queue<int> q;
  q.push(node);
  visited[node] = true;
  result[node] = index++;

  while (!q.empty()) {
    int curr = q.front(); q.pop();

    for (int next: adj[curr]) {
      if(!visited[next]) {
        visited[next] = true;
        result[next] = index++;
        q.push(next);
      }
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  std::fill(visited, visited + 100001, false);

  int n, m, r;
  cin >> n >> m >> r;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    std::sort(adj[i].begin(), adj[i].end());
  }

  bfs(r);

  for (int i = 1; i <= n; ++i) {
    cout << result[i] << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp