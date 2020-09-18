#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while(T--)
	{
		v.clear();
		int N; cin >> N;
		for(int i = 0; i < N; ++i)
		{
			pair<int, int> p;
			cin >> p.first >> p.second;
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		int m = v[0].second;
		for(int i = 1; i < v.size(); ++i)
		{
			if(m < v[i].second)
				N--;
			else m = v[i].second;
		}
		
		cout << N << '\n';
	}
}