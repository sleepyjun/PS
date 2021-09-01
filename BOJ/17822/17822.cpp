// https://www.acmicpc.net/problem/17822
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <deque>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n, m, t;
bool check[51][51];
std::deque<int> panel[51];

void cw(const int &x, const int &k) {
  for (int i = x; i <= n; i += x) {
    for (int j = 0; j < k; ++j) {
      panel[i].push_front(panel[i].back());
      panel[i].pop_back();
    }
  }
} 
void ccw(const int &x, const int &k) {
  for (int i = x; i <= n; i += x) {
    for (int j = 0; j < k; ++j) {
      panel[i].push_back(panel[i].front());
      panel[i].pop_front();
    }
  }
}
bool vanish() {
  std::fill(&check[0][0], &check[50][51], false);
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    int jump = (i == n ? -1 : i+1);
    for (int j = 0; j < m; ++j) {
      if (panel[i][j] == 0) continue;
      int prev = (j == 0 ? m-1 : j-1);
      int next = (j == m-1 ? 0 : j+1);

      if (jump != -1) {
        if (panel[i][j] == panel[jump][j]) {
          flag = check[i][j] = check[jump][j] = true;
        }
      }
      if (panel[i][j] == panel[i][prev]) {
        flag = check[i][j] = check[i][prev] = true;
      }
      if (panel[i][j] == panel[i][next]) {
        flag = check[i][j] = check[i][next] = true;
      }
    }
  }
  return flag;
}
void print();
void print(const char *str);
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m >> t;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x; cin >> x;
      panel[i].push_back(x);
    }
  }

  while (t--) {
    int x, d, k;
    cin >> x >> d >> k;

    switch(d) {
      case 0:
        cw(x,k);
        break;
      case 1:
        ccw(x,k);
        break;
    }
    if (true == vanish()) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (check[i][j] == true) panel[i][j] = 0;
        }
      }
    } else {
      int sum = 0;
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (panel[i][j] == 0) continue;
          cnt++;
          sum += panel[i][j];
        }
      }

      double avg = (double)sum/cnt;
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (panel[i][j] == 0) continue;
          if (avg < (double)panel[i][j]) panel[i][j]--;
          else if (avg > (double)panel[i][j]) panel[i][j]++;

        }
      }
    }
  }
  
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      res += panel[i][j];
    }
  }

  cout << res << '\n';
}
void print() {
  cout << "=======================\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << panel[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "=======================\n";
}
void print(const char *str) {
  cout << "=========" << str << "=========\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << panel[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "=======================\n";
}
// g++ -o a -std=c++17 *.cpp