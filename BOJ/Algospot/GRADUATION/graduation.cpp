#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int MAXN = 12;
const int INF = 987654321;
int n, k, m, l;

int prerequest[MAXN];
int classes[10];
int dp[10][1<<MAXN];

int bitCount(int n)
{
	int bits = 0;
	while(n != 0)
	{
		if((n&1) == 1) bits++;
		n >>= 1;
	}
	return bits;
}
int solve(int semester, int taken)
{
	if(bitCount(taken) >= k) return 0;
	if(semester == m) return INF;
	
	int& ret = dp[semester][taken];
	if(ret != -1) return ret;
	ret = INF;
	
	int canTake = (classes[semester] & ~taken);
	//find not yet taken class
	
	for(int i = 0; i < n; ++i)
	{
		if((canTake & (1 << i)) && (taken & prerequest[i]) != prerequest[i])
		{
			//class has int canTake
			//request class confirm
			canTake &= ~(1 << i);
		}
	}
	//remove class that not yet taken request class
	
	for(int take = canTake; take > 0; take = ((take - 1) & canTake))
	{
		if(bitCount(take) > l) continue;
		
		ret = std::min(ret, solve(semester+1, take|taken)+1);
	}
	ret = std::min(ret, solve(semester+1, taken));
	return ret;
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	
	while(t--)
	{
		std::fill(prerequest, prerequest+MAXN, 0);
		std::fill(classes, classes+10, 0);
		std::fill(&dp[0][0], &dp[9][(1<<MAXN)-1], -1);
		
		cin >> n >> k >> m >> l;
		
		for(int i = 0; i < n; ++i)
		{
			int pre; cin >> pre;
			int temp = 0;
			for(int j = 0; j < pre; ++j)
			{
				int x; cin >> x;
				temp |= (1 << x);
			}
			prerequest[i] = temp;
		}
		
		for(int i = 0; i < m; ++i)
		{
			int cnt; cin >> cnt;
			int temp = 0;
			for(int j = 0; j < cnt; ++j)
			{
				int x; cin >> x;
				temp |= (1 << x);
			}
			classes[i] = temp;
		}
		
		int res = solve(0, 0);
		if(res == INF) cout << "IMPOSSIBLE";
		else cout << res;
		cout << '\n';
	}
}