//? 플로이드
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000; // 절대 나올 수 없는 경로값
 
int main(){
    int N, M, dist[100][100];
    scanf("%d %d", &N, &M);
    // dist 배열 초기화
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            dist[i][j] = i==j ? 0 : INF;
    // 간선 정보 입력받음
    for(int i=0; i<M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
    
    // 플로이드 와샬 알고리즘 적용
    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    
    // 이제 dist 배열은 실제 최단 경로를 담고 있음
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ", dist[i][j]);
        puts("");
    }
}

//? 방문 가능 체크
// https://www.acmicpc.net/problem/6156 
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool arr[101][101];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m; cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    arr[u][v] = true;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (arr[i][k] & arr[k][j]) {
          arr[i][j] = true;
        }
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    int count = 0;
    for (int j = 1; j <= n; ++j) {
      if (arr[i][j] || arr[j][i]) {
        count++;
      }
    }
    if (count == n-1) {
      answer++;
    }
  }

  cout << answer << '\n';
}
// g++ -o a -std=c++17 *.cpp