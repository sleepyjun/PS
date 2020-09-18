#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
const int INF = 987654321;
std::vector<pii> v[801];
int n,e; 

int root(int start, int end) 
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > pq;
	std::vector<int> dist(801, INF);
	dist[start] = 0; pq.push({0,start});
	while(!pq.empty())
	{
		int weight = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < weight)
			continue;
		for(int i = 0; i < v[here].size(); ++i)
		{
			int there = v[here][i].first;
			int nextWeight = weight + v[here][i].second;
			
			if(dist[there] > nextWeight)
			{
				dist[there] = nextWeight;
				pq.push({nextWeight, there});
			}
		}
	}
	
	return dist[end];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> e;
	for(int i = 0; i < e; ++i)
	{
		int a,b,c; cin >> a >> b >> c;
		//a node, b node, c weight
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	int mustA, mustB; cin >> mustA >> mustB;
	
	bool resABFlag = false;
	bool resBAFlag = false;
	int resAB = 0;
	int resBA = 0;
	int temp;
	/*A->B*/
	if((temp = root(1, mustA)) >= INF) resABFlag = true;
	else resAB+=temp;
	if((temp = root(mustA, mustB)) >= INF) resABFlag =true;
	else resAB+=temp;
	if((temp = root(mustB, n)) >= INF) resABFlag =true;
	else resAB+=temp;
	/*B->A*/
	if((temp = root(1, mustB)) >= INF) resBAFlag = true;
	else resBA+=temp;
	if((temp = root(mustB, mustA)) >= INF) resBAFlag = true;
	else resBA+=temp;
	if((temp = root(mustA, n)) >= INF) resBAFlag = true;
	else resBA+=temp;
	
	if(resABFlag == true && resBAFlag == true)
		cout << -1 << '\n';
	else if(resABFlag == true && resBAFlag == false)
		cout << resBA << '\n';
	else if(resABFlag == false && resBAFlag == true)
		cout << resAB << '\n';
	else
		cout << std::min(resAB, resBA) << '\n';
}