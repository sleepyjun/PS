// https://www.acmicpc.net/problem/17140
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool cmp(const pii &a, const pii &b) {
  if (a.second != b.second) return a.second < b.second;
  return a.first < b.first;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  std::vector<int> arr[110];
  for (auto &a: arr) a.resize(110, 0);

  int r,c,k; cin >> r >> c >> k;
  int row = 3, col = 3;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cin >> arr[i][j];
    }
  }

  int time = 0;
  do {
    if (arr[r][c] == k) break;
    if (time == 101) {
      cout << -1 << '\n';
      return 0;
    }

    if (row >= col) {
      int max = col;
      for (int y = 1; y <= row; ++y) {
        std::map<int, int> m;
        std::vector<pii> p;
        for (int x = 1; x <= col; ++x) {
          m[arr[y][x]]++;
          arr[y][x] = 0;
        }

        for (int i = 1; i <= 100; ++i)
          if(m[i] != 0) p.push_back({i,m[i]});

        std::sort(p.begin(), p.end(), cmp);

        int size = (p.size() > 50 ? 50 : p.size());
        for (int i = 0; i < size; ++i) {
          int idx = 1 + i*2;
          arr[y][idx++] = p[i].first;
          arr[y][idx] = p[i].second;
        }
        
        max = std::max(max, size*2);
      }
      col = max;
    } else {
      int max = row;
      for (int x = 1; x <= col; ++x) {
        std::map<int, int> m;
        std::vector<pii> p;
        for (int y = 1; y <= row; ++y) {
          m[arr[y][x]]++;
          arr[y][x] = 0;
        }
        
        for (int i = 1; i <= 100; ++i)
          if(m[i] != 0) p.push_back({i,m[i]});
        
        std::sort(p.begin(), p.end(), cmp);

        int size = (p.size() > 50 ? 50 : p.size());
        for (int i = 0; i < size; ++i) {
          int idx = 1 + i*2;
          arr[idx++][x] = p[i].first;
          arr[idx][x] = p[i].second;
        }

        max = std::max(max, size*2);
      }
      row = max;
    }

    /*
    cout << "=====================\n";
    for (int y = 1; y <= row; ++y) {
      for (int x = 1; x <= col; ++x) {
        cout << arr[y][x] << ' ';
      }
      cout << '\n';
    }
    cout << "=====================\n";
    */
  } while (++time);
  cout << time << '\n';
}
// g++ -o a -std=c++17 *.cpp