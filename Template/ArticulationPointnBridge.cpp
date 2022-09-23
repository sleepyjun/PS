// https://www.acmicpc.net/problem/11266
//? 단절점
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
//*****************************************************
// https://www.acmicpc.net/problem/11400
//? 단절선
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
std::vector<int> adj[100001];
int whenVisit[100001], when;
std::vector<pii> cut;

int dfs(int curr, int parent = 0)
{
    whenVisit[curr] = ++when;
    int ret = whenVisit[curr];

    for(int next : adj[curr])
    {
        if(next == parent) continue;

        if(whenVisit[next] != 0)
        {
            ret = std::min(ret, whenVisit[next]);
            continue;
        }

        int prev = dfs(next,curr);
        if(prev > whenVisit[curr])
            cut.push_back({std::min(curr,next), std::max(curr,next)});
        ret = std::min(ret, prev);
    }

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
        if(whenVisit[i] == 0) dfs(i);
    
    std::sort(cut.begin(), cut.end());
    cout << cut.size() << '\n';
    for(const pii &p : cut)
        cout << p.first << ' ' << p.second << '\n';
}//g++ -o a -std=c++11 *.cpp