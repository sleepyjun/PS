#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool arr[200001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<pii> v;
	v.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	std::sort(v.begin(), v.end());
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	
	pq.push(v[0].second);
	for(int i = 1; i < n; ++i)
	{
		int start = v[i].first;
		int end = v[i].second;
		if(pq.top() <= start)
		{
			pq.pop();
			pq.push(end);
		}
		else
			pq.push(end);
	}
	
	cout << pq.size() << '\n';
}