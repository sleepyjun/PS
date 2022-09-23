//? 최소 공통 조상
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX_NODE 100001
 
using namespace std;
 
// depth :: 노드의 깊이(레벨)
// ac[x][y] :: x의 2^y번째 조상을 의미
int depth[MAX_NODE];
int ac[MAX_NODE][20];
 
typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];
 
int max_level;
 
// DP(ac)배열 만드는 과정
void getTree(int here, int parent)
{
    // here의 깊이는 부모노드깊이 + 1
    depth[here] = depth[parent] + 1;
 
    // here의 1번째 조상은 부모노드
    ac[here][0] = parent;
    
    // MAX_NODE에 log2를 씌어 내림을 해준다.
    max_level = (int)floor(log2(MAX_NODE));
 
    for (int i = 1; i <= max_level; i++)
    {
        // tmp :: here의 2^(i-1)번째 조상
        /* 
            즉, ac[here][i] = ac[tmp][i-1]은
            here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
            예를들어 i = 3일때
            here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
            i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
        */
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }
 
    // dfs 알고리즘
    int len = graph[here].size();
    for (int i = 0; i < len; i++)
    {
        int there = graph[here][i];
        if (there != parent)
            getTree(there, here);
    }
}
 
int main()
{
    int n, m;
 
    scanf("%d", &n);
 
    // 양방향 그래프 형성
    for (int i = 1; i < n; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
 
    // make_tree에 1,0이 들어가기때문에 0은 -1로 지정
    depth[0] = -1;
 
    // 루트 노드인 1번 노드부터 트리 형성
    getTree(1, 0);
 
    // 쿼리문 시작
    scanf("%d", &m);
 
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        if (depth[a] != depth[b])
        {
            // depth[b] >= depth[a]가 되도록 swap
            if (depth[a] > depth[b])
                swap(a, b);
 
            // b를 올려서 depth를 맞춰준다.
            /* 
                이렇게하면 만약 max_level이 4라면
                2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식으로 찾아갈텐데
                결국 1, 2, 3, 4, 5 ..., 31까지 모두 찾는 방식과 같아진다.
                예를들어, i가 4일때와 1일때 만족했다 치면
                depth[a] <= depth[ac[b][4]]에 의해
                b = ac[b][4];가 되어 b는 b의 16번째 조상을 보고 있을 것이고
                depth[a] <= depth[ac[b][1]]에 의해(현재 b는 처음 b의 16번째 조상인 b로 바뀌었다.)
                b = ac[b][1];이 되어 b는 b의 2번째 조상을 보게 된다.
                즉, b의 16번째 조상의 2번째 조상을 보는 것이니 b의 18번째 조상을 보게 된다.
                (하고자 하는 말은 3번째, 7번째, 11번째 이런 조상들도 모두 볼 수 있다는 의미이다.)
            */
            for (int i = max_level; i >= 0; i--)
            {
                // b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고간다.
                if (depth[a] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }
 
        int lca = a;
 
        // a와 b가 다르다면 현재 깊이가 같으니
        // 깊이를 계속 올려 서로 다른 노드의 조상이 같아질 때까지 반복한다.
        // 즉, 서로 다른 노드(2,3)의 조상이 1로 같다면 lca = ac[2][0]에 의해 2의 조상이 1임을 알 수 있고
        // 마찬가지로 ac[3][0] 또한 3의 조상이 1임을 알게되며 알고리즘이 끝이난다.
        if (a != b)
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[a][i] != ac[b][i])
                {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }
 
        printf("%d\n", lca);
    }
    return 0;
}
 
//This source code Copyright belongs to Crocus
/*=========================================*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 18; // roundup log(2, 100000)
 
int N, M;
int parent[100000][MAX]; // parent[i][k]: i의 2^k번째 부모
int depth[100000]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> adj[100000]; // 인접 리스트
 
// dfs로 트리 제작하며 parent[i][0], depth 배열 채움
void makeTreeByDFS(int curr){
    for(int next: adj[curr]){
        if(depth[next] == -1){
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            makeTreeByDFS(next);
        }
    }
}
 
 
 
int main(){
    // 트리 정보 입력
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 배열 초기화
    memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;
    // 트리 만들기
    makeTreeByDFS(0);
 
    // parent 배열 채움
    for(int j=0; j<MAX-1; j++)
        for(int i=1; i<N; i++)
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];
 
    // 쿼리 입력받기
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
 
        // depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
 
        // 깊이 차(diff)를 없애며 u를 이동시킴
        for(int j=0; diff; j++){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }
 
        // u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
        if(u != v){
            // 높이 2^17, 2^16, ..., 2^2, 2, 1 순으로 시도
            for(int j=MAX-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            // 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
            u = parent[u][0];
        }
 
        // LCA 출력
        printf("%d\n", u+1);
    }
}
// [출처] 최소 공통 조상(Lowest Common Ancestor) (수정: 2019-08-31)|작성자 라이

/*======================================*/

//!응용문제 최소 최대 간선 찾기
// https://www.acmicpc.net/problem/3176
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 17;
int parent[100001][MAX];
int max[100001][MAX];
int min[100001][MAX];
int depth[100001];
std::vector<pii> adj[100001];

void make(int curr)
{
	
	for(const auto& next: adj[curr])
	{
		int nNode = next.first;
		int nCost = next.second;
		if(depth[nNode] == -1)
		{
			min[nNode][0] = max[nNode][0] = nCost;
			parent[nNode][0] = curr;
			depth[nNode] = depth[curr] + 1;
			make(nNode);
		}
	}
}

int getLCA(int u, int v)
{
	if(depth[u] < depth[v]) std::swap(u, v);
	int diff = depth[u] - depth[v];
	
	for(int i = 0; diff; ++i)
	{
		if(diff % 2) u = parent[u][i];
		diff /= 2;
	}
	
	if(u != v)
	{
		for(int i = MAX-1; i >= 0; --i)
		{
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	
	return u;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&parent[0][0], &parent[100000][MAX], -1);
	std::fill(&max[0][0], &max[100000][MAX], -1);
	std::fill(&min[0][0], &min[100000][MAX], INF);
	std::fill(depth, depth+100001, -1);
	
	int n; cin >> n;
	
	for(int i = 0; i < n-1; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	depth[1] = 0;
	make(1);
	
	for(int j = 0; j < MAX-1; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(parent[i][j] != -1)
			{
				min[i][j+1] = std::min(min[i][j], min[parent[i][j]][j]);
				max[i][j+1] = std::max(max[i][j], max[parent[i][j]][j]);
				parent[i][j+1] = parent[parent[i][j]][j];
			}
		}
	}
		
	int t; cin >> t;
	while(t--)
	{
		int s, e; cin >> s >> e;
		int mid = getLCA(s, e);
	
		int leftDiff = depth[s] -  depth[mid];
		int rightDiff = depth[e] - depth[mid];
		int leftMax = -1, rightMax = -1;
		int leftMin = INF, rightMin = INF;
		
		for(int i = 0; leftDiff; ++i)
		{
			if(leftDiff % 2)
			{
				leftMax = std::max(leftMax, max[s][i]);
				leftMin = std::min(leftMin, min[s][i]);
				s = parent[s][i];
			}
			leftDiff /= 2;
		}
		
		for(int i = 0; rightDiff; ++i)
		{
			if(rightDiff % 2)
			{
				rightMax = std::max(rightMax, max[e][i]);
				rightMin = std::min(rightMin, min[e][i]);
				e = parent[e][i];
			}
			rightDiff /= 2;
		}
		
		cout << std::min(leftMin, rightMin) << ' ' << std::max(leftMax, rightMax) << '\n';
	}
}//g++ -o a -std=c++17 *.cpp

