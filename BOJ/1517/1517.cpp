// https://www.acmicpc.net/problem/1517
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 1048576;
int arr[MAX];
std::vector<pii> v;

struct SegTree {
	int size, leaf;
	SegTree(): size(0), leaf(0) {}
	SegTree(int n): size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}

	void update(int i)
	{
		i += leaf;
		arr[i]++;
		for(i/=2; i>0; i/=2) arr[i]++;
	}
	int query(int l, int r)
	{
		int ret = 0;
		l += leaf, r += leaf;
		while(l < r)
		{
			if(l % 2 == 1) ret += arr[l++];
			if(r % 2 == 1) ret += arr[--r];
			l /= 2, r /= 2;
		}
		return ret;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	SegTree s(n);
	for(int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		v.push_back({x, i});
	}
	sort(v.begin(), v.end(), std::greater<pii>());
	long long ans = 0;
	for(const auto& p: v)
	{
		ans += s.query(0, p.second);
		s.update(p.second-1);
	}
	cout << ans << '\n';
}//g++ -o a -std=c++17 *.cpp