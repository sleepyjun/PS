// https://www.acmicpc.net/problem/3015
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::stack<pii> st;
	int n; cin >> n;
	long long res = 0;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		int cnt = 1;
		while(!st.empty() && st.top().first < x)
		{
			res += st.top().second;
			st.pop();
		}
		if(!st.empty() && st.top().first == x)
		{
			res += st.top().second;
			cnt += st.top().second;
			st.pop();
		}
		if(!st.empty() && st.top().first > x)
			res++;
		st.push({x,cnt});
	}
	
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp