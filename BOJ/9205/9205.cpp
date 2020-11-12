// https://www.acmicpc.net/problem/9205
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <string>
#include <map>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

long long hash(long long x, long long y)
{
    return x*100000 + y;
}
int diff(const pii& src, const pii& dest)
{
    return abs(src.first - dest.first) + 
        abs(src.second - dest.second);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
    while(t--)
    {
        //Init
        int n; cin >> n;
        pii start; cin >> start.first >> start.second;
        std::vector<pii> combini;
        for(int i = 0; i < n; ++i)
        {
            int x, y; cin >> x >> y;
            combini.push_back({x,y});
        }
        pii end; cin >> end.first >> end.second;
        std::map<long long, bool> visited;
        //BFS
        std::queue<pii> q;
        bool flag = false;
        q.push(start); visited[hash(start.first,start.second)] = true;
        while(!q.empty())
        {
            pii node = q.front(); q.pop();
            if(diff(node,end) <= 1000)
            {
                flag = true;
                break;
            }
            for(auto com : combini)
            {
                if(true == visited[hash(com.first,com.second)]) continue;
                if(diff(node,com) <= 1000) 
                {
                    visited[hash(com.first,com.second)] = true;
                    q.push(com);
                }
            }
        }

        if(flag == true) cout << "happy\n";
        else cout << "sad\n";
    }
}//g++ -o a -std=c++11 *.cpp