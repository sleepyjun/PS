// https://www.acmicpc.net/problem/14427
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 262144;
std::vector<pii> arr(MAX, {INF, INF});

bool cmp(const pii &a, const pii &b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
struct Seg {
	int size, leaf;

	Seg():size(1),leaf(1) {}
	Seg(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = std::min(arr[i*2], arr[i*2+1], cmp);
	}
	void update(int i, int v)
	{
		i += leaf; arr[i].first = v;
		for(i/=2; i > 0; i/=2)
			arr[i] = std::min(arr[i*2], arr[i*2+1], cmp);
	}
	int query(int l, int r)
	{
		pii res = {INF,INF};
		l += leaf; r += leaf;
		while(l < r) // [l, r)
		{
			if(l%2 == 1) res = std::min(res, arr[l++], cmp);
			if(r%2 == 1) res = std::min(res, arr[--r], cmp);
			l/=2; r/=2;
		}
		return res.second;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	Seg s(n);
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		arr[s.leaf+i] = {x,i};
	}
	s.init();

	int t; cin >> t;
	while(t--)
	{
		int q; cin >> q;
		switch(q) {
		case 1:
			int i,v; cin >> i >> v;
			s.update(i-1,v);
			break;
		case 2:
			cout << s.query(0, n)+1 << '\n';
			break;
		}
	}
}//g++ -o a -std=c++11 *.cpp