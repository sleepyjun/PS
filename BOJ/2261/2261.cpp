#include <iostream>
#include <algorithm>
#include <vector>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = 987654321;

std::vector<pii> v;

int dist(const pii& p1, const pii& p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) +
		(p1.second - p2.second) * (p1.second - p2.second);
}
bool comp(const pii& p1, const pii& p2)
{
	return p1.second < p2.second;
}

int simple(int s, int e)
{
	int res = INF;
	for(int i=s; i<=e; ++i)
	{
		for(int j=i+1; j<=e; ++j)
			res = std::min(res, dist(v[i],v[j]));
	}
	return res;
}
int solve(int s, int e)
{
	if(e-s <= 2) return simple(s,e);
	
	int mid = (s+e)/2;
	int left = solve(s, mid);
	int right = solve(mid+1, e);
	int res = std::min(left, right);
	std::vector<pii> canBe;
	
	for(int i=s; i<=e; ++i)
	{
		int diff = v[mid].first - v[i].first;
		if(diff*diff < res)
			canBe.push_back(v[i]);
	}
	
	std::sort(canBe.begin(), canBe.end(), comp);
	
	for(int i=0; i<canBe.size(); ++i)
	{
		for(int j=i+1; j<canBe.size(); ++j)
		{
			int diff = canBe[i].second-canBe[j].second;
			if(diff*diff < res)
				res = std::min(res, dist(canBe[i], canBe[j]));
			else
				break;
		}
	}
	
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		v.push_back({x,y});	
	}
	
	std::sort(v.begin(), v.end());
	
	cout << solve(0, n-1) << '\n';
}