// 
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

	while(t--) // index is 0~n-1 think about cin >> arr
	{
		long long a, b, c; cin >> a >> b >> c;
		if(a == 1)
			s.update(b-1, c);
		else if(a == 2)
			cout << s.query(b-1, c) << '\n';
	}
}//g++ -o a -std=c++17 *.cpp