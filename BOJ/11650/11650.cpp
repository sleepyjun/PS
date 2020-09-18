#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<pair<int,int> > v;
	int n;
	cin >> n;
	while(n--)
	{
		pair<int,int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i)
		cout << v[i].first << ' ' << v[i].second << '\n';
}