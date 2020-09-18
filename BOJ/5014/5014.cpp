#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool visited[1000001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int f,s,g,u,d;
	std::queue<int> q;
	cin >> f >> s >> g >> u >> d;
	
	bool flag = true;
	int res = 0;
	q.push(s);
	visited[s] = true;
	while(flag && !q.empty())
	{
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			int curr = q.front();
			if(curr == g)
			{
				flag = false;
				break;
			}
			q.pop();
			
			int nu = curr+u;
			int nd = curr-d;
			if(nu <= f && !visited[nu])
			{
				visited[nu] = true;
				q.push(nu);
			}
			if(nd >= 1 && !visited[nd])
			{
				visited[nd] = true;
				q.push(nd);
			}
		}
		res++;
	}
	
	if(flag)
		cout << "use the stairs";
	else
		cout << res-1;
	cout << '\n';
}
//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;