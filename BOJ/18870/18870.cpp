// https://www.acmicpc.net/problem/18870
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
	
    int n; cin >> n;
	std::vector<int> arr(n);
    std::set<int> s;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    std::vector<int> point(s.begin(), s.end());
    for(auto& p : arr)
        cout << std::lower_bound(point.begin(), point.end(), p) - point.begin() << ' ';
         
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp