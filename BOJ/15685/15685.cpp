// https://www.acmicpc.net/problem/15685
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 110;
const int DIR[4][2] = {
  { 0, 1},
  {-1, 0},
  { 0,-1},
  { 1, 0}
};
bool map[MAX][MAX];

void curve(int x, int y, int d, int g) {
  std::vector<int> dragon;
  dragon.push_back(d);
  map[y][x] = true;
  y += DIR[d][0];
  x += DIR[d][1];
  map[y][x] = true;
  
  while (g--) {
    std::vector<int> v(dragon);
    int vSize = v.size();
    for (int i = vSize-1; i >= 0; --i) {
      int d = v[i];
      d = (d+1)%4;

      y += DIR[d][0];
      x += DIR[d][1];
      map[y][x] = true;

      dragon.push_back(d);
    }
  }
}
bool judge(const int &y, const int &x) {
  int cnt = 0;
  if (true == map[y][x]) cnt++;
  if (true == map[y+1][x]) cnt++;
  if (true == map[y][x+1]) cnt++;
  if (true == map[y+1][x+1]) cnt++;
  return cnt==4;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    int x,y,d,g;
    cin >> x >> y >> d >> g;
    curve(x,y,d,g);
  }

  int res = 0;
  for (int y = 0; y < MAX; ++y) {
    for (int x = 0; x < MAX; ++x) {
      if(true == judge(y,x)) res++;
    }
  }
  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp