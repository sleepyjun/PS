// https://www.acmicpc.net/problem/14003
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    std::vector<int> arr(n), position(n), ans, lis;
    for(int i = 0; i < n; ++i) cin >> arr[i];

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
            lis.push_back(arr[i]);
            sz--;
        }
    }

    cout << lis.size() << '\n';
    for(int i = lis.size()-1; i >= 0; --i)
    {
        cout << lis[i] << ' ';
    }
}//g++ -o a -std=c++11 *.cpp