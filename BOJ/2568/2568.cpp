// https://www.acmicpc.net/problem/2568
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    std::map<int, int> m;
    std::vector<pii> v(n);
    std::vector<int> position(n), arr(n), ans;
    for(int i = 0; i < n; ++i)
    {
        int a,b; cin >> a >> b;
        v[i] = {a,b};
        m[b] = a;
    }
    std::sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i) arr[i] = v[i].second;

    for(int i = 0; i < n; ++i)
    {
        auto it = std::lower_bound(ans.begin(), ans.end(), arr[i]);
        position[i] = it-ans.begin();
        if(it == ans.end()) ans.push_back(arr[i]);
        else *it = arr[i];
    }

    int sz = ans.size()-1;
    for(int i = n-1; i >= 0; --i)
    {
        if(position[i] == sz)
        {
            m.erase(arr[i]);
            sz--;
        }
    }

    ans.clear();
    for(auto it = m.begin(); it != m.end(); ++it)
        ans.push_back(it->second);
    std::sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int n : ans)
        cout << n << '\n';
}//g++ -o a -std=c++11 *.cpp