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

bool visited[100000];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, t, g;
	std::queue<int> q;
	cin >> n >> t >> g;
	if(n==g)
	{
		cout << 0 << '\n';
		return 0;
	}
	q.push(n);
	visited[n] = true;
	int cnt = 0;
	bool flag = true;
	while(t-- && flag && !q.empty())
	{
		int qSize = q.size();
		for(int i = 0; flag && i < qSize; ++i)
		{
			int curr = q.front();
			q.pop();
			for(int j = 0; j < 2; ++j)
			{
				int newNum;
				if(j == 0)
					newNum = curr+1;
				else if(j == 1)
					newNum = curr*2;
				if(newNum > 99999) continue;
                if(j == 1 && newNum != 0)
				{
					for(int k = 1; k <= 10000; k *= 10)
					{
						if(newNum / k < 10)
						{
							newNum -= k;
							break;
						}
					}
				}
				if(visited[newNum] == true) continue;
				if(newNum == g)
				{
					flag = false;
					break;
				}
				visited[newNum] = true;
				q.push(newNum);
			}
		}
		cnt++;
	}
	if(flag) cout << "ANG";
	else cout << cnt;
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;