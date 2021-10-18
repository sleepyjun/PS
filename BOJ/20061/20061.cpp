// https://www.acmicpc.net/problem/20061
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
// x y
int board[15][15];
int line;

void blueRun(int t, int x, int y) {
  std::vector<pii> v;
  v.push_back({x,y});
  if (t == 2) {
    v.push_back({x,y+1});
  } else if (t == 3) {
    v.push_back({x+1,y});
  }

  while (1) {
    bool flag = false;
    for (const auto &p: v) {
      int nx = p.first;
      int ny = p.second+1;

      if (ny > 9) {
        flag = true;
        break;
      }
      if(board[nx][ny] != 0) {
        flag = true;
        break;
      }
    }

    if (flag) break;
    else {
      for (auto &p: v)
        p.second++;
    }
  }

  for (const auto &p: v) {
    int cx = p.first;
    int cy = p.second;
    board[cx][cy] = 1;
  }
}
void greenRun(int t, int x, int y) {
  x = 4;
  std::vector<pii> v;
  v.push_back({x,y});
  if (t == 2) {
    v.push_back({x,y+1});
  } else if (t == 3) {
    v.push_back({x+1,y});
  }

  while (1) {
    bool flag = false;
    for (const auto &p: v) {
      int nx = p.first+1;
      int ny = p.second;

      if (nx > 9) {
        flag = true;
        break;
      }
      if(board[nx][ny] != 0) {
        flag = true;
        break;
      }
    }

    if (flag) break;
    else {
      for (auto &p: v)
        p.first++;
    }
  }

  for (const auto &p: v) {
    int cx = p.first;
    int cy = p.second;
    board[cx][cy] = 1;
  }
}
void run(int t, int x, int y) {
  blueRun(t,x,y);
  greenRun(t,x,y);
}

int blueLine() {
  int count = 0;
  for (int col = 6; col < 10; ++col) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[i][col] == 0) {
        flag = true;
        break;
      }
    }

    if (flag == false) {
      count++;
      for (int i = 0; i < 4; ++i)
        board[i][col] = 0;
    }
  }

  return count;
}
int greeLine() {
  int count = 0;
  for (int row = 6; row < 10; ++row) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[row][i] == 0) {
        flag = true;
        break;
      }
    }

    if (flag == false) {
      count++;
      for (int i = 0; i < 4; ++i)
        board[row][i] = 0;
    }
  }

  return count;
}

void blueMoving(int count = 0) {
  for (int col = 9; col >= 6-count; --col) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[i][col] == 1) {
        flag = true;
        break;
      }
    }

    if (flag == false) {
      for (int i = 0; i < 4; ++i) {
        board[i][col] = board[i][col-1];
        board[i][col-1] = 0;
      }
    }
  }
}
void greenMoving(int count = 0) {
  for (int row = 9; row >= 6-count; --row) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[row][i] == 1) {
        flag = true;
        break;
      }
    }

    if (flag == false) {
      for (int i = 0; i < 4; ++i) {
        board[row][i] = board[row-1][i];
        board[row-1][i] = 0;
      }
    }
  }
}

void clearLine() {
  int blue = blueLine();
  int green = greeLine();

  for (int i = 0; i < blue; ++i) blueMoving();
  for (int i = 0; i < green; ++i) greenMoving();
  line += (blue+green);
}

int blueProcessing() {
  int count = 0;
  for (int col = 4; col < 6; ++col) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[i][col] == 1) {
        flag = true;
        break;
      }
    }
    if (flag) {
      count++;
    }
  }

  for (int i = 0; i < count; ++i) {
    int col = 9-i;
    for (int j = 0; j < 4; ++j)
      board[j][col] = 0;
  }
  return count;
}
int greenProcessing() {
  int count = 0;
  for (int row = 4; row < 6; ++row) {
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
      if (board[row][i] == 1) {
        flag = true;
        break;
      }
    }
    if (flag) {
      count++;
    }
  }

  for (int i = 0; i < count; ++i) {
    int row = 9-i;
    for (int j = 0; j < 4; ++j)
      board[row][j] = 0;
  }
  return count;
}
void processing() {
  int blue = blueProcessing();
  int green = greenProcessing();

  for (int i = 0; i < blue; ++i) blueMoving(blue);
  for (int i = 0; i < green; ++i) greenMoving(green);
}
int counting() {
  int count = 0;
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      // cout << board[x][y] << ' ';
      if (board[x][y] == 1) count++;
    }
    // cout << '\n';
  }

  return count;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  while (n--) {
    int t, x, y; cin >> t >> x >> y;
    run(t, x, y);
    clearLine();
    processing();
  }
  int count = counting();

  cout << line << '\n';
  cout << count << '\n';
}
// g++ -o a -std=c++17 *.cpp