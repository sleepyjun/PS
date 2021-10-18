// 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::set<int> s[9];

int calc(const int &x, const int &y, const int &cond) {
    switch (cond) {
        case 0: return x+y;
        case 1: return x-y;
        case 2: return x/y;
        default: return x*y;
    }
}
void init(const int &N) {
    int n = N;
    for (int i = 1; i <= 8; ++i) {
        s[i].insert(n);
        for (int j = 1; j < i; ++j) {
            for (const int &x: s[j]) {
                for (const int &y: s[i-j]) {
                    for (int c = 0; c < 4; ++c) {
                        int ret = calc(x,y,c);
                        if (ret != 0) s[i].insert(ret);
                    }
                }
            }
        }
        n *= 10;
        n += N;
    }
}
int solution(int N, int number) {
    init(N);
    for (int i = 1; i <= 8; ++i) {
        if (s[i].find(number) != s[i].end()) return i;
    }
    return -1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int k; cin >> k;
  int n; cin >> n;
  while (n--) {
    int num; cin >> num;
    int ret = solution(k, num);
    if (ret == -1) cout << "NO";
    else cout << ret;
    cout << '\n';
  }
}
// g++ -o a -std=c++17 *.cpp