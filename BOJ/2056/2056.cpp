// https://www.acmicpc.net/problem/2056
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



int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int time[10001], pre[10001], minTime[10001];
    std::vector<int> next[10001];
    std::queue<int> q;
    int res = 0;

	int n; cin >> n;
    std::fill(pre,pre+10001,0);
    std::fill(minTime, minTime+10001, 0);

    for(int i = 1; i <= n; ++i)
    {
        bool flag = true;
        int p; 
        cin >> time[i] >> p;
        for(int j = 0; j < p; ++j)
        {
            flag = false;
            int x; cin >> x;
            next[x].push_back(i);
            pre[i]++;
        }
        if(true == flag) 
        {
            q.push(i);
            minTime[i] = time[i];
            minTime[0] = std::max(minTime[0], minTime[i]);
        }
    }
    
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        for(int n : next[curr])
        {
            minTime[n] = std::max(minTime[n], minTime[curr]+time[n]);
            pre[n]--;
            if(pre[n] == 0) 
                q.push(n);
        }
    }
    for(int i = 0; i <= n; ++i)
        res = std::max(res, minTime[i]);
    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp