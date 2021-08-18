// https://www.acmicpc.net/board/search/all/problem/21611
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int DIR[4][2] = {
  { 0,-1},
  { 1, 0},
  { 0, 1},
  {-1, 0}
};
const int WRAP[] = {0, 3, 1, 0, 2};

int n,m;
int map[50][50];
int destroyCount[4];
std::vector<pii> idx;

void makeIdx() {
  int y = (n+1)/2;
  int x = (n+1)/2;
  int d = 0;
  int dist = 1;
  while (1) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < dist; ++j) {
        y += DIR[d][0];
        x += DIR[d][1];

        idx.push_back({y,x});

        if (y == 1 && x == 1) return;
      }

      d = (d+1)%4;
    }
    dist++;
  }
}

void destroy(int d, int s) {
  int y = (n+1)/2;
  int x = (n+1)/2;
  d = WRAP[d];
  for (int i = 0; i < s; ++i) {
    y += DIR[d][0];
    x += DIR[d][1];

    map[y][x] = 0;
  }
}

void move() {
  int temp[50][50];
  for (int i = 0; i < idx.size(); ++i) {
    int y = idx[i].first;
    int x = idx[i].second;

    if (map[y][x] != 0) continue;

    int zero = 1;

    for (int j = i+1; j < idx.size(); ++j) {
      int y = idx[j].first;
      int x = idx[j].second;

      if (map[y][x] != 0) break;
      zero++;
    }

    for (int j = i; j < idx.size()-zero; ++j) {
      int cy = idx[j].first;
      int cx = idx[j].second;
      int ny = idx[j+zero].first;
      int nx = idx[j+zero].second;

      std::swap(map[cy][cx], map[ny][nx]);
    }
  }

}

void explosion() {
  bool destroyed = false;

  while (1) {
    for (int i = 0; i < idx.size(); ++i) {
      int cy = idx[i].first;
      int cx = idx[i].second;

      if (map[cy][cx] == 0) continue;

      int ball = map[cy][cx];
      std::vector<pii> balls;
      balls.push_back({cy,cx});

      for (int j = i+1; j < idx.size(); ++j) {
        int ny = idx[j].first;
        int nx = idx[j].second;

        if (map[ny][nx] != ball) break;
        balls.push_back({ny, nx});
      }

      if (balls.size() >= 4) {
        for (const pii &p: balls) {
          int y = p.first;
          int x = p.second;
          map[y][x] = 0;
        }
        destroyed = true;
        destroyCount[ball] += balls.size();
      }
    }

    if (destroyed == false) break;

    destroyed = false;
    move();
  }
}

void group() {
  int check = 0;
  int temp[50][50];
  std::copy(&map[0][0], &map[49][50], &temp[0][0]);

  for (int i = 0; check < idx.size() && i < idx.size();) {
    int cy = idx[i].first;
    int cx = idx[i].second;

    if (temp[cy][cx] == 0) break;

    int ball = temp[cy][cx];
    int cnt = 1;

    for (int j = i+1; j < idx.size(); ++j) {
      int ny = idx[j].first;
      int nx = idx[j].second;

      if (temp[ny][nx] != ball) break;
      cnt++;
    }
    
    cy = idx[check].first;
    cx = idx[check].second;
    map[cy][cx] = cnt;
    if (check+1 < idx.size()) {
      int ny = idx[check+1].first;
      int nx = idx[check+1].second;
      map[ny][nx] = ball;
    } else break;

    check += 2;
    i += cnt;
  }
}
void print() {
  cout << "================================\n";
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cout << map[y][x] << ' ';
    }
    cout << '\n';
  }
  cout << "================================\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      cin >> map[y][x];
    }
  }
  makeIdx();

  while (m--) {
    int d, s; cin >> d >> s;
    destroy(d,s);
    move();
    explosion();
    group();
  }

  int res = 0;
  for (int i = 1; i <= 3; ++i) {
    res += destroyCount[i]*i;
  }

  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp