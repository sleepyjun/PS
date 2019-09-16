#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool hasPair[10];
int res;
bool v[10][10];
void func(int n)
{
	int fast = -1;
	for(int i = 0; i < n; ++i)
		if(!hasPair[i])
		{
			fast = i;
			break;
		}
	
	if(fast == -1) { res++; return; }
	for(int i = fast+1; i < n; ++i)
		if(!hasPair[i] && v[fast][i])
		{
			hasPair[i] = hasPair[fast] = true;
			func(n);
			hasPair[i] = hasPair[fast] = false;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		for(int i = 0 ; i < 10 ; ++i)
			for(int j = 0 ; j < 10; ++j)
				v[i][j] = false;
		fill(hasPair, hasPair+10, false);
		res = 0;
		for(int i = 0; i < m; ++i)
		{
			int a,b; cin >> a >> b;
			v[a][b] = v[b][a] = true;
		}
		func(n);
		cout << res << '\n';
	}
}