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