// https://www.acmicpc.net/problem/1043
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

bool knowMember[51];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int res = 0;
    
	int n,m; cin >> n >> m;
    int t; cin >> t;
    std::queue<int> knowTruth;
    for(int i = 0; i < t; ++i)
    {
        int x; cin >> x;
        knowTruth.push(x);
        knowMember[x] = true;
    }

    std::vector<int> party[51]; //파티에 참여한 멤버
    std::vector<int> member[51]; //멤버가 참여한 파티
    for(int i = 1; i <= m; ++i)
    {
        int n; cin >> n;
        for(int j = 0; j < n; ++j)
        {
            int x; cin >> x;
            party[i].push_back(x);
            member[x].push_back(i);
        }
    }

    while(!knowTruth.empty())
    {
        int m = knowTruth.front();
        knowTruth.pop();
        for(int p : member[m])
        {
            for(int x : party[p])
            {
                if(true == knowMember[x]) continue;
                knowTruth.push(x);
                knowMember[x] = true;
            }
        }
    }

    for(int i = 1; i <= m; ++i)
    {
        bool flag = true;
        for(int m : party[i])
        {
            if(true == knowMember[m])
            {
                flag = false;
                break;
            }
        }
        if(true == flag) res++;
    }
    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp