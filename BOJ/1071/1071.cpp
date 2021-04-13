// https://www.acmicpc.net/problem/1071
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
	
    std::multiset<int> arr;
	int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        arr.insert(x);
    }
    while(!arr.empty())
    {
        int x = *(arr.begin());
        if(arr.find(x+1) != arr.end())
        {
            auto it = arr.lower_bound(x+2);
            if(it != arr.end())
            {
                for(int i = 0; i < arr.count(x); ++i)
                    cout << x << ' ';
                arr.erase(x);
                cout << *it << ' ';
                arr.erase(it);
            }
            else
            {
                cout << x+1 << ' ';
                arr.erase(arr.find(x+1));
            }
        }
        else
        {
            for(int i = 0; i < arr.count(x); ++i)
                cout << x << ' ';
            arr.erase(x);
        }
        
    }
}//g++ -o a -std=c++11 *.cpp