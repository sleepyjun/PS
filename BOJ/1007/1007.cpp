// https://www.acmicpc.net/problem/1007
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pll = std::pair<long long, long long>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	cout << std::fixed;
	cout.precision(6);
	while(t--)
	{
		std::vector<pll> v;
		std::vector<int> p;
		int n; cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int y,x; cin >> y >> x;
			v.push_back({y,x});
			if(i < n/2) p.push_back(0);
			else p.push_back(1);
		}
		
		double res = 999999;
		do {
			long long y=0,x=0;
			for(int i = 0; i < v.size(); ++i)
			{
				if(p[i] == 0)
				{
					y += v[i].first;
					x += v[i].second;
				}
				else
				{
					y -= v[i].first;
					x -= v[i].second;
				}
				
			}
			res = std::min(res, sqrt((y*y)+(x*x)));
		} while(std::next_permutation(p.begin(), p.end()));
		cout << res << '\n';
	}
}//g++ -o a -std=c++11 *.cpp