// https://www.acmicpc.net/problem/4196
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<std::vector<int> > adj, rAdj;
std::stack<int> st;
int group[100001], inDegree[100001], cnt;
bool visited[100001];

void dfs(int curr)
{
    visited[curr] = true;
    for(int next : adj[curr])
        if(false == visited[next]) dfs(next);
    st.push(curr);
}
void find(int curr, std::vector<int> &currScc)
{   
    visited[curr] = true;
    currScc.push_back(curr);
    group[curr] = cnt;
    for(int next : rAdj[curr])
        if(false == visited[next]) find(next, currScc);  
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
    while(t--)
    {
        std::fill(visited, visited+100001, false);
        std::fill(group, group+100001, -1);
        std::fill(inDegree, inDegree+100001, 0);

        cnt = 0;
        std::vector<std::vector<int> > scc;
        int n,m; cin >> n >> m;
        adj = std::vector<std::vector<int> >(n+1);
        rAdj = std::vector<std::vector<int> >(n+1);
        for(int i = 0; i < m; ++i)
        {
            int a,b; cin >> a >> b;
            adj[a].push_back(b);
            rAdj[b].push_back(a);
        }
        for(int i = 1; i <= n; ++i)
            if(false == visited[i]) dfs(i);

        std::fill(visited, visited+100001, false);
        while(false == st.empty())
        {
            int curr = st.top(); st.pop();
            if(true == visited[curr]) continue;
            std::vector<int> currScc;
            find(curr, currScc);

            scc.push_back(currScc);
            cnt++;
        }

        for(int i = 1; i <= n; ++i)
            for(int j : adj[i])
                if(group[i] != group[j]) inDegree[group[j]]++;

        int res = 0;
        for(int i = 0; i < cnt; ++i)
            if(inDegree[i] == 0) res++;
        cout << res << '\n';
    }  
}//g++ -o a -std=c++11 *.cpp