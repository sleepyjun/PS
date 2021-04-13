// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    pii ans;
	int sum = INF;
    int n; cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
	std::sort(v.begin(), v.end());
    int s = 0, e = n-1;
    while(1)
    {
        if(s==e) break;
        int x = abs(v[s]+v[e]);
        if(sum > x)
        {
            sum = x;
            ans.first = v[s];
            ans.second = v[e];
        }
        if(abs(v[s]) > abs(v[e])) s++;
        else e--;
    }

    cout << ans.first << ' ' << ans.second << '\n';
}//g++ -o a -std=c++11 *.cpp