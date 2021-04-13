// https://www.acmicpc.net/problem/11266
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int v,e;
std::vector<int> adj[10001];
int whenVisit[10001], when;
bool cut[10001];

int dfs(int curr, bool isRoot=false)
{
    whenVisit[curr] = ++when;
    int ret = whenVisit[curr];
    int child = 0;

    for(int next : adj[curr])
    {
        if(whenVisit[next] != 0)
        {
            ret = std::min(ret, whenVisit[next]);
            continue;
        }

        child++;
        int prev = dfs(next);

        if(false == isRoot && prev >= whenVisit[curr])
            cut[curr] = true;
        ret = std::min(ret, prev);
    }
    if(true == isRoot) cut[curr] = (child >= 2);

    return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> v >> e;
    for(int i = 0; i < e; ++i)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= v; ++i)
        if(whenVisit[i] == 0) dfs(i,true);
    
    int cnt = 0;
    for(int i = 1; i <= v; ++i)
        if(true == cut[i]) cnt++;
    
    cout << cnt << '\n';
    for(int i = 1; i <= v; ++i)
        if(true == cut[i]) cout << i << ' ';
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp