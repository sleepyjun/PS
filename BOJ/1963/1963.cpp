// https://www.acmicpc.net/problem/1963
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

const int MAX = 10000;
bool isPrime[MAX];
bool visited[MAX];

void init() {
  std::fill(isPrime+2, isPrime+MAX, true);

  for (int i = 2; i*i < MAX; ++i) {
    if (isPrime[i])
      for (int j = i*i; j < MAX; j += i)
        isPrime[j] = false;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  init();
  int t; cin >> t;
  while (t--) {
    std::queue<int> q;
    std::fill(visited, visited+MAX, false);
    int src, dest; cin >> src >> dest;
    int cnt = 0;
    bool flag = true;
    q.push(src); visited[src] = true;

    while (!q.empty()) {
      int qSize = q.size();
      for (int i = 0; i < qSize; ++i) {
        int curr = q.front(); q.pop();
        if (curr == dest) {
          flag = false;
          break;
        }

        int temp;
        // change n000
        for (int j = 1; j <= 9; ++j) {
          temp = j*1000 + (curr%1000);

          if (!isPrime[temp] || visited[temp] == true) continue;
          visited[temp] = true;
          q.push(temp);
        }
        // change 0n00
        for (int j = 0; j <= 9; ++j) {
          temp = ((curr/1000) * 1000) + j*100 + (curr%100);

          if (!isPrime[temp] || visited[temp] == true) continue;
          visited[temp] = true;
          q.push(temp);
        }
        // change 00n0
        for (int j = 0; j <= 9; ++j) {
          temp = ((curr/100) * 100) + j*10 + (curr%10);

          if (!isPrime[temp] || visited[temp] == true) continue;
          visited[temp] = true;
          q.push(temp);
        }
        // change 000n
        for (int j = 0; j <= 9; ++j) {
          temp = ((curr/10)*10) + j;

          if (!isPrime[temp] || visited[temp] == true) continue;
          visited[temp] = true;
          q.push(temp);
        }
      }

      if (flag == false) break;
      cnt++;

    }

    if (flag == false) cout << cnt << '\n';
    else cout << "Impossible\n";
  }
}
// g++ -o a -std=c++17 *.cpp