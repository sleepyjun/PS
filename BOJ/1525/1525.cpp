// https://www.acmicpc.net/problem/1525
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int M = 100000000;
const int DIR[4][2] = {
  {0, 1},
  {1, 0},
  {-1, 0},
  {0 ,-1}
};
std::map<int, bool> m;

bool safe(const int &y, const int &x) {
  return (0 <= y && y <= 2) && (0 <= x && x <= 2);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int puzzle = 0;
  std::string puzzleStr;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int x; cin >> x;
      puzzleStr += char(x+'0');
    }
  }
  puzzle = std::stoi(puzzleStr);

  int cnt = 0;
  std::queue<int> q;
  q.push(puzzle); m[puzzle] = true;

  while(!q.empty()) {
    if (m[123456780] == true) break;
    
    int qSize = q.size();
    for (int i = 0; i < qSize; ++i) {
      puzzle = q.front(); q.pop();
      
      if (puzzle < M) { //first is 0
        puzzleStr = "0"+std::to_string(puzzle);
      } else {
        puzzleStr = std::to_string(puzzle);
      }
      int zeroPos = puzzleStr.find('0');
      for (int d = 0; d < 4; ++d) {
        int cy = zeroPos/3;
        int cx = zeroPos%3;

        int ny = cy + DIR[d][0];
        int nx = cx + DIR[d][1];
        if (false == safe(ny, nx)) continue;
        
        int nPos = ny*3 + nx;
        std::string nStr = puzzleStr;
        std::swap(nStr[zeroPos], nStr[nPos]);
        puzzle = std::stoi(nStr);
        if (true == m[puzzle]) continue;
        q.push(puzzle);
        m[puzzle] = true;
      }
    }
    cnt++;
  }

  if (m[123456780] == true) cout << cnt;
  else cout << -1;
  cout << '\n';
}
// g++ -o a -std=c++17 *.cpp