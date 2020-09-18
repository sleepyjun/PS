#include <iostream>
#include <algorithm>
#include <queue>
using std::cin; using std::cout;

struct RAND {
	unsigned int seed;
	RAND() : seed(1983) {}
	unsigned int next() {
		unsigned int ret = seed;
		seed = ((seed*214013u)+2531011u);
		return ret % 10000 + 1;
	}
};

int n, k;

int solve()
{
	RAND r;
	std::queue<int> q;
	int cnt = 0, sum = 0;
	for(int i = 0; i < n; ++i)
	{
		int newRand = r.next();
		sum += newRand;
		q.push(newRand);
		
		while(sum > k) {
			sum -= q.front();
			q.pop();
		}
		
		if(sum == k) cnt++;
	}
	
	return cnt;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		cin >> k >> n;
		cout << solve() << '\n';
	}
}