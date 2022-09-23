//? 위상정렬
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
    int N, M, indegree[1000] = {0};
    vector<int> adj[1000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int K, prev, curr;
        scanf("%d", &K);
        if(K == 0) continue;
 
        scanf("%d", &prev);
        for(int i=1; i<K; i++){
            scanf("%d", &curr);
            indegree[curr-1]++;
            adj[prev-1].push_back(curr-1);
            prev = curr;
        }
    }
 
    int result[1000];
    queue<int> Q;
    // 위상 정렬 시작: 큐에 indegree가 0인 정점을 다 넣음
    for(int i=0; i<N; i++)
        if(indegree[i] == 0) Q.push(i);
 
    // 위상 정렬
    for(int i=0; i<N; i++){
        // 도중에 큐가 비면 불가능
        if(Q.empty()){
            puts("0");
            return 0;
        }
 
        int curr = Q.front();
        Q.pop();
        result[i] = curr+1;
        // 인접한 정점을 순회하면서 indegree 1씩 감소. 0이 되면 큐에 넣음
        for(int next: adj[curr])
            if(--indegree[next] == 0) Q.push(next);
    }
 
    // 결과 출력
    for(int i=0; i<N; i++)
        printf("%d\n", result[i]);
} 

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int main(){
    int N, time[500], result[500] = {0}, indegree[500] = {0};
    vector<int> adj[500];
    queue<int> Q;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", time+i);
        while(1){
            int pre;
            scanf("%d", &pre);
            if(pre == -1) break;
            indegree[i]++;
            adj[pre-1].push_back(i);
        }
        // indegree = 0인 정점을 큐에 넣어 둠
        if(indegree[i] == 0){
            result[i] = time[i];
            Q.push(i);
        }
    }
 
    // 위상 정렬
    for(int i=0; i<N; i++){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            // 최소 건설 완료 시간 갱신
            result[next] = max(result[next], result[curr]+time[next]);
            // 간선을 삭제하여 next의 indegree가 0이 되면 next도 큐에 넣음
            if(--indegree[next] == 0) Q.push(next);
        }
    }
 
    // 결과 출력
    for(int i=0; i<N; i++)
        printf("%d\n", result[i]);
}
// [출처] 위상 정렬(Topological Sort) (수정: 2017-06-22)|작성자 라이

