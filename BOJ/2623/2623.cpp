// https://www.acmicpc.net/problem/2623
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> next[1001];
int prev[1001];
int res[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int t; cin >> t;
        if(t==0) continue;
        int pre; cin >> pre;
        for(int j = 1; j < t; ++j)
        {
            int curr; cin >> curr;
            next[pre].push_back(curr);
            prev[curr]++;
            pre = curr;
        }
    }

    std::queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(prev[i] == 0) q.push(i);

    for(int i = 1; i <= n; ++i)
    {
        if(q.empty())
        {
            cout << "0\n";
            return 0;
        }

        int curr = q.front(); q.pop();
        res[i] = curr;
        for(int n : next[curr])
        {
            prev[n]--;
            if(prev[n] == 0) q.push(n);
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << res[i] << '\n';
}//g++ -o a -std=c++11 *.cpp