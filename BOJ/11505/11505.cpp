// https://www.acmicpc.net/problem/11505
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 2097152;
const long long MOD = 1e9+7;
long long arr[MAX];

struct SegTree {
	int leaf, size;
	SegTree(): leaf(0), size(0) {}
	SegTree(int n): size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
		std::fill(arr,arr+MAX,1);
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = (arr[i*2]%MOD * arr[i*2+1]%MOD)%MOD;
	}
	void update(int i, long long v)
	{
		i += leaf;
		arr[i] = v;
		for(i/=2; i > 0; i/=2)
			arr[i] = (arr[i*2]%MOD * arr[i*2+1]%MOD)%MOD;
	}
	long long query(int l, int r)
	{
		long long res = 1;
		l += leaf, r += leaf;
		while(l < r)
		{
			if(l % 2 == 1) res = (res%MOD * arr[l++]%MOD)%MOD;
			if(r % 2 == 1) res = (res%MOD * arr[--r]%MOD)%MOD;
			l/=2, r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
	int t = m+k;
	SegTree s(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[s.leaf+i];
	s.init();
	while(t--)
	{
		int a,b,c; cin >> a >> b >> c;
		if(a == 1)
			s.update(b-1,c);
		else if(a == 2)
			cout << s.query(b-1, c) << '\n';
	}	
}//g++ -o a -std=c++17 *.cpp