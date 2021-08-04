// https://www.acmicpc.net/problem/2251
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

bool visited[201][201][201];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int A,B,C; cin >> A >> B >> C;
  std::queue<iii> q;
  std::set<int> ans;
  
  q.push({0,0,C});

  while (!q.empty()) {
    int a,b,c;
    auto curr = q.front(); q.pop();
    std::tie(a,b,c) = curr;

    if(visited[a][b][c] == true) continue;
    if(a == 0) ans.insert(c);
    visited[a][b][c] = true;

    //a to b
    if (a != 0 && b < B) {
      int ta = a;
      int capacity = B-b;

      ta -= capacity;

      if (ta > 0) q.push({ta,B,c});
      else q.push({0,B+ta,c});
    }
    //a to c
    if (a != 0 && c < C) {
      int ta = a;
      int capacity = C-c;

      ta -= capacity;

      if (ta > 0) q.push({ta,b,C});
      else q.push({0,b,C+ta});
    }

    //b to a
    if (b != 0 && a < A) {
      int tb = b;
      int capacity = A-a;

      tb -= capacity;

      if (tb > 0) q.push({A,tb,c});
      else q.push({A+tb,0,c});
    }
    //b to c
    if (b != 0 && c < C) {
      int tb = b;
      int capacity = C-c;

      tb -= capacity;

      if (tb > 0) q.push({a,tb,C});
      else q.push({a,0,C+tb});
    }

    //c to a
    if (c != 0 && a < A) {
      int tc = c;
      int capacity = A-a;

      tc -= capacity;

      if (tc > 0) q.push({A,b,tc});
      else q.push({A+tc,b,0});
    }
    //c to b
    if (c != 0 && b < B) {
      int tc = c;
      int capacity = B-b;

      tc -= capacity;

      if (tc > 0) q.push({a,B,tc});
      else q.push({a,B+tc,0});
    }
  }

  for (int n: ans) {
    cout << n << ' ';
  }
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp