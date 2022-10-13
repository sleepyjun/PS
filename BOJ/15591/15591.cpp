// https://www.acmicpc.net/problem/15591 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<pii> adj[5001];
bool visited[5001];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, q; cin >> n >> q;

  for (int i = 0; i < n-1; ++i) {
    int p, q, r; cin >> p >> q >> r;
    adj[p].push_back({q, r});
    adj[q].push_back({p, r});
  }

  while (q--) {
    std::fill(visited, visited+n+1, false);
    int k, v; cin >> k >> v;
    int count = 0;
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
      int curr = q.front(); q.pop();

      for (const pii &next: adj[curr]) {
        if (visited[next.first] == true) continue;

        if (next.second >= k) {
          visited[next.first] = true;
          q.push(next.first);
          count++;
        }
      }
    }

    cout << count << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp