#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

std::vector<std::pair<std::pair<int, int>, int> > xyr;
/*
xyr[i].first == x,y좌표
xyr[i].first.first == x
xyr[i].first.second == y
xyr[i].second == r
*/
int parent[3001];

int find(int x)
{
	if(x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x != y)
	{
		parent[y] = x;
	}
}



int centerDist(int x1, int y1, int x2, int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int radiusDist(int r1, int r2)
{
	return ((r1+r2)*(r1+r2));
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		xyr.clear();
		int n; cin >> n;
		xyr.resize(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> xyr[i].first.first >> xyr[i].first.second
			>> xyr[i].second;
			parent[i] = i;
		}
		int ans = n;
		for(int i = 0; i < n; ++i)
		{
			for(int j = i+1; j < n; ++j)
			{
				int cDist = centerDist(xyr[i].first.first, xyr[i].first.second,
								xyr[j].first.first, xyr[j].first.second);
				int rDist = radiusDist(xyr[i].second, xyr[j].second);
				if(cDist <= rDist)
				{
					if(find(i) != find(j))
					{
						ans--;
						merge(i,j);
					}
				}
			}
		}
		
		cout << ans << '\n';
	}
}