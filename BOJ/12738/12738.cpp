/* https://www.acmicpc.net/problem/12738
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
	
	int n, ans = 1; cin >> n;
    std::vector<int> arr,v;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        arr.push_back(x);
    }
    v.push_back(arr[0]);
    for(int x : arr)
    {
        if(v.back() < x)
        {
            v.push_back(x);
            ans++;
        }
        else
        {
            auto it = std::lower_bound(v.begin(),v.end(),x);
            *it = x;
        }
    }
    cout << ans << '\n';
}//g++ -o a -std=c++11 *.cpp
*/
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
    std::vector<int> arr(n), ans;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n; ++i)
    {
        auto it = std::lower_bound(ans.begin(), ans.end(), arr[i]);
        if(it == ans.end()) ans.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << ans.size() << '\n';
}//g++ -o a -std=c++11 *.cpp