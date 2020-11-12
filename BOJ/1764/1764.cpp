// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
    std::string str;
    std::set<std::string> temp;
    std::set<std::string> res;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        temp.insert(str);
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> str;
        if(temp.find(str) != temp.end())
            res.insert(str);
    }

    cout << res.size() << '\n';
    for(auto ans : res)
        cout << ans << '\n';
}//g++ -o a -std=c++11 *.cpp