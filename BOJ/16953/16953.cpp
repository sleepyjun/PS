// https://www.acmicpc.net/problem/16953
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull a,b; cin >> a >> b;
    int step = 1;
    std::queue<ull> q;
    std::map<ull,bool> visit;
    q.push(a); visit[a] = true;
    while(!q.empty())
    {
        int qSize = q.size();
        for(int i = 0; i < qSize; ++i)
        {
            ull curr = q.front(); q.pop();
            ull temp;
            if(curr == b)
            {
                cout << step << '\n';
                return 0;
            }
            temp = curr*2;
            if((temp <= 1000000000) && !visit[temp])
            {
                visit[temp] = true;
                q.push(temp);
            }
            temp = curr*10+1;
            if((temp <= 1000000000) && !visit[temp])
            {
                visit[temp] = true;
                q.push(temp);
            }
        }
        step++;
    }

    cout << -1 << '\n';
}//g++ -o a -std=c++11 *.cpp