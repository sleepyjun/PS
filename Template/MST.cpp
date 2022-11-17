//? 최소 스패닝 트리 크루스칼
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int uf[1000];  // union-find 배열

// union-find의 find 연산
int find(int a) {
  if (uf[a] < 0) return a;
  return uf[a] = find(uf[a]);
}

// union-find의 union 연산
bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return false;
  uf[b] = a;
  return true;
}

int main() {
  cout.tie(NULL);
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<tuple<int, int, int> > edge;
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, a, b});
  }
  // 간선을 가중치 기준으로 오름차순 정렬
  sort(edge.begin(), edge.end());

  // result: 가중치합, cnt: 뽑은 간선 수
  int result = 0, cnt = 0;
  fill(uf, uf + N, -1);
  for (int i = 0;; i++) {
    int w, u, v;
    tie(w, u, v) = edge[i];

    if (merge(u, v)) {
      result += w;
      if (++cnt == N - 1) break;  // N-1개 간선을 뽑으면 나감
    }
  }
  cout << result << '\n';
}