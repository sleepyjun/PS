// https://www.acmicpc.net/problem/20529
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

int func(const std::vector<std::string> &arr)
{
    int diff = 0;
    for(int i = 0; i < 3; ++i)
        for(int j = i+1; j < 3; ++j)
            for(int k = 0; k < 4; ++k)
                if(arr[i][k] != arr[j][k]) diff++;
    return diff;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        std::vector<std::string> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int res = INF;

        for(int i = 0; res != 0 && i < n; ++i)
        {
            for(int j = i+1; res != 0 && j < n; ++j)
            {
                for(int k = j+1; res != 0 && k < n; ++k)
                {
                    int temp = func({arr[i],arr[j],arr[k]});
                    res = std::min(res, temp);
                }
            }
        }

        cout << res << '\n';
    }
}//g++ -o a -std=c++11 *.cpp