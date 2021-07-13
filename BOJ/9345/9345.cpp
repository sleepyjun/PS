// https://www.acmicpc.net/problem/9345
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
int maxArr[2*MAX];
int minArr[2*MAX];

struct MaxSeg {
	int size;
	MaxSeg(int n): size(n) {}

	void init()
	{
		for(int i = size-1; i >= 1; --i)
			maxArr[i] = std::max(maxArr[i*2], maxArr[i*2+1]);
	}
	void update(int i, int j)
	{
		i += size;
		j += size;
		std::swap(maxArr[i], maxArr[j]);
		for(i/=2; i >= 1; i/=2)
			maxArr[i] = std::max(maxArr[i*2], maxArr[i*2+1]);
		for(j/=2; j >= 1; j/=2)
			maxArr[j] = std::max(maxArr[j*2], maxArr[j*2+1]);
	}
	int query(int l, int r)
	{
		int ret = -1;
		l += size;
		r += size;
		while(l < r)
		{
			if(l%2) ret = std::max(ret, maxArr[l++]);
			if(r%2) ret = std::max(ret, maxArr[--r]);

			l /= 2; r /= 2;
		}

		return ret;
	}
};

struct MinSeg {
	int size;
	MinSeg(int n): size(n) {}

	void init()
	{
		for(int i = size-1; i >= 1; --i)
			minArr[i] = std::min(minArr[i*2], minArr[i*2+1]);
	}
	void update(int i, int j)
	{
		i += size;
		j += size;
		std::swap(minArr[i], minArr[j]);
		for(i/=2; i >= 1; i/=2)
			minArr[i] = std::min(minArr[i*2], minArr[i*2+1]);
		for(j/=2; j >= 1; j/=2)
			minArr[j] = std::min(minArr[j*2], minArr[j*2+1]);
	}
	int query(int l, int r)
	{
		int ret = INF;
		l += size;
		r += size;
		while(l < r)
		{
			if(l%2) ret = std::min(ret, minArr[l++]);
			if(r%2) ret = std::min(ret, minArr[--r]);

			l /= 2; r /= 2;
		}

		return ret;
	}

};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(maxArr, maxArr+2*MAX, -1);
		std::fill(minArr, minArr+2*MAX, INF);
		int n, k; cin >> n >> k;
		MaxSeg maxSeg(n);
		MinSeg minSeg(n);
		for(int i = 0; i < n; ++i)
			maxArr[i+n] = minArr[i+n] = i;
		maxSeg.init();
		minSeg.init();

		while(k--)
		{
			int q, a, b; cin >> q >> a >> b;
			if(q == 0)
			{
				maxSeg.update(a,b);
				minSeg.update(a,b);
			}
			else if(q == 1)
			{
				int maxRes = maxSeg.query(a, b+1);
				int minRes = minSeg.query(a, b+1);

				if(maxRes == b && minRes == a)
					cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}//g++ -o a -std=c++17 *.cpp