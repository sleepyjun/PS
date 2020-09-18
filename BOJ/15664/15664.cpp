#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int n, m;
set<int> s;
set<string> res;
int cnt[10001];
int arr[10];

void dfs(int idx)
{
	if(idx == m)
	{
		string temp;
		for(int i = 0; i < m; ++i)
		{
			temp += to_string(arr[i]);
			temp += ' ';
		}
		temp.erase(temp.end()-1,temp.end());
		if(res.find(temp) == res.end())
		{
			cout << temp << '\n';
			res.insert(temp);
		}
		return;
	}
	
	set<int>::iterator iter = s.begin();
	for(int i = 0; i < n && iter != s.end(); ++i, ++iter)
	{
		if(idx - 1 >= 0 && arr[idx-1] > *iter) continue;
		if(cnt[*iter])
		{
			cnt[*iter]--;
			arr[idx] = *iter;
			dfs(idx+1);
			cnt[*iter]++;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		int temp; cin >> temp;
		cnt[temp]++; s.insert(temp);
	}

	dfs(0);
}