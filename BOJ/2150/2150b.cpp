// https://www.acmicpc.net/problem/2150
// !타잔 알고리즘
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

const int MAX = 10001;
std::vector<std::vector<int> > adj, ans;
std::stack<int> st;
int discover[MAX], scc[MAX];
int v,e,visitCnt,sccCnt=1; 

int dfs(int curr)
{
    discover[curr] = ++visitCnt;
    st.push(curr);

    int res = discover[curr];
    for(int next : adj[curr])
    {
        if(discover[next] == 0) res = std::min(res, dfs(next));
        else if(scc[next] == 0) res = std::min(res, discover[next]);
    }

    if(res == discover[curr])
    {
        std::vector<int> currScc;
        while(1)
        {
            int t = st.top(); st.pop();
            currScc.push_back(t);
            scc[t] = sccCnt;
            if(t == curr) break;
        }
        std::sort(currScc.begin(), currScc.end());
        ans.push_back(currScc);
        sccCnt++;
    }
    return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> v >> e;
    adj.resize(v+1);
    for(int i = 0; i < e; ++i)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= v; ++i)
        if(discover[i] == 0) dfs(i);
    std::sort(ans.begin(), ans.end());
    cout << sccCnt-1 << '\n';

    for(const auto &currScc : ans)
    {
        for(int x : currScc)
            cout << x << ' ';
        cout << "-1\n";
    }
}//g++ -o a -std=c++11 *.cpp