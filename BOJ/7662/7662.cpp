
// https://www.acmicpc.net/problem/7662
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
	
	int t; cin >> t;
    while(t--)
    {
        int order; cin >> order;
        std::multiset<long long> s;
        while(order--)
        {
            char c;
            long long n;
            cin >> c >> n;
            if(c == 'I') s.insert(n);
            else if(c == 'D')
            {
                if(s.empty() == true) continue;
                if(n == 1)
                {
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
                else
                {
                    auto it = s.begin();
                    s.erase(it);
                }
                
            }
        }
        if(s.empty() == true)
            cout << "EMPTY";
        else
            cout << *(--s.end()) << ' ' << *s.begin();
        cout << '\n';
    }
}//g++ -o a -std=c++11 *.cpp