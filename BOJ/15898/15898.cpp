// https://www.acmicpc.net/problem/15898
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int COORD[4][2] = {
  {0,0},
  {1,0},
  {0,1},
  {1,1}
};
struct M {
  int n[4][4];
  char c[4][4];

  void cw() {
    int tn[4][4];
    int tc[4][4];

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        tn[j][3-i] = n[i][j];
        tc[j][3-i] = c[i][j];
      }
    }

    std::copy(&tn[0][0], &tn[3][4], &n[0][0]);
    std::copy(&tc[0][0], &tc[3][4], &c[0][0]);
  }

  void print() {
    cout << "=====================\n";
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cout << n[i][j] << ' ';
      }
      cout << '\n';
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cout << c[i][j] << ' ';
      }
      cout << '\n';
    }
    cout << "=====================\n";
  }
};

M material[10];
std::vector<pii> v(3);
int res = 0;

void make(const std::vector<int> &choice) {
  int npot[5][5]; std::fill(&npot[0][0], &npot[4][5], 0);
  char cpot[5][5]; std::fill(&cpot[0][0], &cpot[4][5], 'W');

  M temp[3];
  for (int k = 0; k < 3; ++k) {
    std::copy(&material[choice[k]], &material[choice[k]+1], &temp[k]);

    int coord = v[k].first;
    int rotate = v[k].second;

    for (int i = 0; i < rotate; ++i)
      temp[k].cw();
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        int y = i + COORD[coord][0];
        int x = j + COORD[coord][1];

        if (npot[y][x] + temp[k].n[i][j] < 0) npot[y][x] = 0;
        else if (npot[y][x] + temp[k].n[i][j] > 9) npot[y][x] = 9;
        else npot[y][x] += temp[k].n[i][j];

        if (temp[k].c[i][j] != 'W') cpot[y][x] = temp[k].c[i][j];
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (cpot[i][j] == 'R') sum += (npot[i][j] * 7);
      else if (cpot[i][j] == 'B') sum += (npot[i][j] * 5);
      else if (cpot[i][j] == 'G') sum += (npot[i][j] * 3);
      else if (cpot[i][j] == 'Y') sum += (npot[i][j] * 2);
    }
  }
  res = std::max(res, sum);
}
void lots(const int &n, int idx = 0) {
  if (idx == 3) {
    std::vector<int> l(n,1);
    for (int i = 0; i < 3; ++i) l[i] = 0;

    do {
      std::vector<int> choice;
      for (int i = 0; i < n; ++i) {
        if (l[i] == 0) choice.push_back(i);
      }

      std::sort(choice.begin(), choice.end());
      do {
        make(choice);
      } while (std::next_permutation(choice.begin(), choice.end()));
      
    } while (std::next_permutation(l.begin(), l.end()));
    
    return;
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      v[idx] = {i,j};
      lots(n, idx+1);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) cin >> material[k].n[i][j];

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j) cin >> material[k].c[i][j];
  }
  lots(n);

  cout << res << '\n';
}
// g++ -o a -std=c++17 *.cpp