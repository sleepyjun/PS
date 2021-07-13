// https://www.acmicpc.net/problem/10999
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 1000001;
long long arr[2*MAX];
long long d[MAX];
int h;

struct SegTree {
	int size;
	SegTree(int n): size(n) {}

	void init()
	{
		for(int i = size-1; i >= 1; --i)
			arr[i] = arr[i*2] + arr[i*2+1];
	}

	void calc(int p, int k)
	{
		arr[p] = arr[p*2] + arr[p*2+1] + d[p] * k;
	}

	void apply(int p, long long v, int k)
	{
		arr[p] += v * k;
		if(p < size) d[p] += v;
	}

	void build(int l, int r)
	{
		int k = 2;
		
		l += size; r += size-1;
		for(; l > 1; k *= 2)
		{
			l /= 2; r /= 2;
			for(int i = r; i >= l; --i) calc(i, k);
		}
	}

	void push(int l, int r)
	{
		int s = h, k = 1 << (h-1);

		l += size; r += size-1;
		for(; s > 0; --s, k/=2)
		{
			for(int i = l >> s; i <= (r >> s); ++i)
			{
				if(d[i] != 0)
				{
					apply(i*2, d[i], k);
					apply(i*2+1, d[i], k);
					d[i] = 0;
				}
			}
		}
	}
	void modify(int l, int r, long long v)
	{
		if(v == 0) return;
		push(l, l+1);
		push(r-1, r);
		
		int l0 = l, r0 = r, k = 1;
		l += size; r += size;
		while(l < r)
		{
			if(l%2) apply(l++, v, k);
			if(r%2) apply(--r, v, k);

			l /= 2; r /= 2; k *= 2;
		}
		build(l0, l0+1);
		build(r0-1, r0);
	}
	long long query(int l, int r)
	{
		push(l, l+1);
		push(r-1, r);
		
		long long res = 0;
		l += size; r += size;
		
		while(l < r)
		{
			if(l%2) res += arr[l++];
			if(r%2) res += arr[--r];

			r/=2; l/=2;
		}

		return res;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int m,k; cin >> m >> k;
	int t = m+k;
	
	h = sizeof(int) * 8 - __builtin_clz(n);
	SegTree s(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[n+i];
	s.init();

	while(t--)
	{
		int q; cin >> q;
		if(q == 1)
		{
			int a,b; cin >> a >> b;
			long long c; cin >> c;
			s.modify(a-1, b, c);
		}
		else if(q == 2)
		{
			int a,b; cin >> a >> b;
			cout << s.query(a-1, b) << '\n';
		}
	}
}//g++ -o a -std=c++17 *.cpp