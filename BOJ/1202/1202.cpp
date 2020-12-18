// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    std::priority_queue<pii> pq;
    std::multiset<int> ms;
	int n,k; cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        int m,v; cin >> m >> v;
        pq.push({v,m});
    }
    for(int i = 0; i < k; ++i)
    {
        int c; cin >> c;
        ms.insert(c);
    }

    long long res = 0;
    while(1)
    {
        if(n == 0 || k == 0) break;
        const auto &curr = pq.top();
        int v = curr.first;
        int m = curr.second;
        pq.pop(); n--;

        auto it = ms.lower_bound(m);
        if(it != ms.end())
        {
            res += v;
            ms.erase(it);
            k--;
        }
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp