/*=========================================================*/
// official
// Based from http://codeforces.com/blog/entry/18051

#define MAX_N 10000

int n;
int t[MAX_N * 2];

void init() {
    for (int i = n - 1; i > 0; --i){
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

// [l, r)
int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
    }
    return ans;
}

void update(int pos, int val) {
    t[pos + n] = val; // update
    for (pos += n; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1]; // update by rule
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[n + i]); // a[0] => a[n]
    }
    init();
    update(0, 2); // a[0] = 2
    update(3, 2); // a[3] = 2
    int q = query(0, 3); // [0, 3); sum(a[0], ..., a[2]) == 2
    return 0;
}


// FINAL SEGMENT TREE
// 2042
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 1000000;
long long arr[2*MAX];
struct SegTree {
	int size;
	SegTree(int n) : size(n) {}
	void init()
	{
		for(int i = size-1; i > 0; --i) arr[i] = arr[i*2] + arr[i*2+1];
	}
	void update(int i, long long v)
	{
		i += size;
        arr[i] = v;
        for(i/=2; i>=1; i/=2)
			arr[i] = arr[i*2]+arr[i*2+1];
	}

	long long query(int l, int r) //[l,r)
	{
		long long res = 0;
		l += size; r += size;
		while(l < r)
		{
			if(l%2) res += arr[l++];
			if(r%2) res += arr[--r];
			l /= 2; r /= 2;
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
		cin >> arr[i+n];
	s.init();

	while(t--)
	{
		long long a, b, c; cin >> a >> b >> c;
		if(a == 1)
			s.update(b-1, c);
		else if(a == 2)
			cout << s.query(b-1, c) << '\n';
	}
}//g++ -o a -std=c++17 *.cpp

//lazy propagation
// https://www.acmicpc.net/problem/16975
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 100000;
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

	void apply(int p, long long v)
	{
		arr[p] += v;
		if(p < size) d[p] += v;
	}

	void build(int p)
	{
		while (p > 1) p >>= 1, arr[p] = std::max(arr[p<<1], arr[p<<1|1]) + d[p];
	}

	void push(int p)
	{
		for(int s = h; s > 0; --s)
		{
			int i = p >> s;
			if(d[i] != 0)
			{
				apply(i << 1, d[i]);
				apply(i << 1 | 1, d[i]);
				d[i] = 0;
			}
		}
	}

	void inc(int l, int r, long long v)
	{
		l += size; r += size;
		int l0 = 1, r0 = r;

		while(l < r)
		{
			if(l%2) apply(l++, v);
			if(r%2) apply(--r, v);
			l /= 2; r /= 2;
		}
		build(l0);
		build(r0-1);
	}

	long long query(int l, int r)
	{
		l += size; r += size;
		push(1);
		push(r-1);

		long long res = -100000000000;
		while(l < r)
		{
			if(l%2) res = std::max(res, arr[l++]);
			if(r%2) res = std::max(arr[--r], res);
			l /= 2; r /= 2;
		}

		return res;
	}

};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	h = sizeof(int) * 8 - __builtin_clz(n);
	SegTree s(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[n+i];
	s.init();

	int t; cin >> t;
	while(t--)
	{
		int q; cin >> q;
		if(q == 1)
		{
			long long l,r,v; cin >> l >> r >> v;
			s.inc(l-1,r,v);
		}
		else if(q == 2)
		{
			int x; cin >> x;
			cout << s.query(x-1, x) << '\n';
		}

		// for(int i = 0; i < n; ++i)
		//	cout << arr[i+n] << ' ';
		// cout << '\n';
	}
}//g++ -o a -std=c++17 *.cpp

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	h = sizeof(int) * 8 - __builtin_clz(n);
	SegTree s(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[n+i];
	s.init();

	int t; cin >> t;
	while(t--)
	{
		int q; cin >> q;
		if(q == 1)
		{
			long long l,r,v; cin >> l >> r >> v;
			s.modify(l-1,r,v);
		}
		else if(q == 2)
		{
			int x; cin >> x;
			cout << s.query(x-1, x) << '\n';
		}

		// for(int i = 0; i < n; ++i)
		//	cout << arr[i+n] << ' ';
		// cout << '\n';
	}
}//g++ -o a -std=c++17 *.cpp

// https://www.acmicpc.net/problem/10999
//! LAZY PROPAGATION FOR SUM INCREMENT
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
	// THIS IS MOST IMPORTANT PART!
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