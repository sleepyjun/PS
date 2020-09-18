// https://www.acmicpc.net/problem/1280
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const long long MOD = 1000000007;
long long sum[524288];
struct SumSeg {
	int size,leaf;
	SumSeg(int n) : size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void update(int i, int v)
	{
		i += leaf;
		sum[i] += v;
		for(i/=2; i>0; i/=2)
			sum[i] = sum[i*2]+sum[i*2+1];
	}
	long long query(int l, int r)
	{
		l += leaf; r += leaf;
		long long res = 0;
		while(l <= r)
		{
			if(l%2 == 1) res += sum[l++];
			if(r%2 == 0) res += sum[r--];
			l /= 2; r /= 2;
		}
		return res;
	}
};
long long cnt[524288];
struct CntSeg {
	int size,leaf;
	CntSeg(int n) : size(n)
	{
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void update(int i)
	{
		i+=leaf;
		cnt[i]++;
		for(i/=2; i>0; i/=2)
			cnt[i] = cnt[i*2]+cnt[i*2+1];
	}
	long long query(int l, int r)
	{
		l += leaf; r += leaf;
		long long res = 0;
		while(l <= r)
		{
			if(l%2 == 1) res += cnt[l++];
			if(r%2 == 0) res += cnt[r--];
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
	int max = -1;
	SumSeg ss(200001);
	CntSeg cs(200001);
	long long res = 1;

	int x; cin >> x;
	max=std::max(max,x);
	cs.update(x); ss.update(x,x);
	for(int i = 1; i < n; ++i) 
	{
		cin >> x;
		max=std::max(max,x);
		
		long long temp = 0;
		temp = (temp + (cs.query(0,x-1)*x - 
			ss.query(0,x-1)))%MOD;
		temp = (temp + (ss.query(x+1,max)-
			cs.query(x+1,max)*x))%MOD;
		ss.update(x,x);
		cs.update(x);
		// cout << temp << ' ';
		res = (res*temp)%MOD;
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;