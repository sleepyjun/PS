#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

const int MOD = 10000;
int INIT, RESULT;
bool visited[10000];
std::vector<std::pair<int, char> > prev;

int rotate(int src, bool left = true)
{
	int res;
	if(left) res = (src%1000)*10 + src/1000;
	else res = (src%10)*1000 + src/10;
	return res;
}
void bfs()
{
	std::queue<int> q;
	std::stack<char> res;
	q.push(INIT);
	visited[INIT] = true;
	prev[INIT] = {-1,'\0'};

	while(!q.empty()) {
		// 0 <= curr <= 9999
		int temp, curr = q.front(); q.pop();
		
		// D > 2n mod 10000
		temp = (curr*2)%MOD;
		if(!visited[temp])
		{
			visited[temp] = true;
			prev[temp] = {curr, 'D'};
			q.push(temp);
		}
		if(temp == RESULT) break;
		// S > n-1 underflow 9999
		temp = (((curr-1) == -1) ? 9999 : curr-1);
		if(!visited[temp])
		{
			visited[temp] = true;
			prev[temp] = {curr, 'S'};
			q.push(temp);
		}
		if(temp == RESULT) break;
		// L > 1234 -> 2341
		temp = rotate(curr);
		if(!visited[temp])
		{
			visited[temp] = true;
			prev[temp] = {curr, 'L'};
			q.push(temp);
		}
		if(temp == RESULT) break;
		// R > 1234 -> 4123
		temp = rotate(curr,false);
		if(!visited[temp])
		{
			visited[temp] = true;
			prev[temp] = {curr, 'R'};
			q.push(temp);
		}
		if(temp == RESULT) break;
	}
	
	for(int i = RESULT;prev[i].first != -1; i = prev[i].first)
		res.push(prev[i].second);
	while(!res.empty())
	{
		cout << res.top();
		res.pop();
	}
	cout << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		cin >> INIT >> RESULT;
		std::fill(visited,visited+10000,false);
		prev.clear();
		prev.reserve(10000);
		bfs();
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;