// https://www.acmicpc.net/problem/2243
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int N = 1000000;
const int MAX = 2097152; // 2^(ceil(log2(N))+1)
long long arr[MAX];

struct SegTree {
	int size, leaf;
	SegTree(int n): size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void update(int i, int v)
	{
		i += leaf;
		arr[i] += v;
		for(i/=2; i>=1; i/=2)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	int query(int pri)
	{
		int pos = 1;
		while(pos < leaf)
		{
			if(pri <= arr[pos*2]) pos *= 2;
			else pri -= arr[pos*2], pos = pos*2+1;
		}
		return pos - leaf;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	SegTree seg(N);

	while(t--)
	{
		int a; cin >> a;
		if(a == 1) //query
		{
			int b; cin >> b;
			int ret = seg.query(b);
			cout << ret+1 << '\n';
			seg.update(ret, -1);
		}
		else if(a == 2) //update
		{
			int b,c; cin >> b >> c;
			seg.update(b-1,c);
		}
	}
}//g++ -o a -std=c++17 *.cpp