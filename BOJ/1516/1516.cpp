// https://www.acmicpc.net/problem/1516
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

int time[501];
int prev[501];
std::vector<int> next[501];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    std::queue<int> q;
    std::fill(prev, prev+501, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> time[i];
        while(1)
        {
            int x; cin >> x;
            if(x == -1) break;
            prev[i]++;
            next[x].push_back(i);
        }
        if(prev[i] == 0) q.push(i);
    }
    
    int res[501];
    std::copy(time,time+501,res);
    
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        for(const auto &n : next[curr])
        {
            res[n] = std::max(res[n], res[curr]+time[n]);
            prev[n]--;
            if(prev[n] == 0) q.push(n);
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << res[i] << '\n';
}//g++ -o a -std=c++11 *.cpp