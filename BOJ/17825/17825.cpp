// https://www.acmicpc.net/problem/17825
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Node {
  int score;
  int next;
  int pNext;
  Node() {}
  Node(int s, int n, int p): score(s), next(n), pNext(p) {}
};

int order[10];
int dice[10];
int horseLoc[4];
bool visited[40];
Node map[40]; //0 is start 21 is end
int res = 0;

int move(int horse, int iter) {
  int currIdx = horseLoc[horse];
  int prevIdx = horseLoc[horse];

  for (int i = 0; i < iter; ++i) {
    if (i == 0 && map[currIdx].pNext != 0)
      currIdx = map[currIdx].pNext;
    else 
      currIdx = map[currIdx].next;
  }

  if (currIdx != 21 && visited[currIdx]) {
    return -1;
  }
  else {
    visited[prevIdx] = false;
    visited[currIdx] = true;
    horseLoc[horse] = currIdx;
  }
  return currIdx;
}

void run(int idx) {
  if (idx == 10) {
    int sum = 0;
    std::fill(visited, visited+40, false);
    std::fill(horseLoc, horseLoc+4, 0);
    for (int i = 0; i < 10; ++i) {
      int movedIdx = move(order[i], dice[i]);

      if (movedIdx == -1) return;
      else sum += map[movedIdx].score;
    }

    res = std::max(res, sum);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    order[idx] = i;
    run(idx+1);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for (int i = 0; i < 10; ++i) {
    cin >> dice[i];
  }

  for (int i = 0; i <= 20; ++i) {
    map[i] = {i*2, i+1, 0};
  } map[21] = {0, 21, 0};
  map[5].pNext = 22;
  map[22] = {13, 23, 0};
  map[23] = {16, 24, 0};
  map[24] = {19, 25, 0};
  

  map[10].pNext = 26;
  map[26] = {22, 27, 0};
  map[27] = {24, 25, 0};

  map[15].pNext = 28;
  map[28] = {28, 29, 0};
  map[29] = {27, 30, 0};
  map[30] = {26, 25, 0};

  map[25] = {25, 31, 0};
  map[31] = {30, 32, 0};
  map[32] = {35, 20, 0};

  run(0);

  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp