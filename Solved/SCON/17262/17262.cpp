#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// bool exist[100002];

// vector<pair<int, int> > v;
// vector<int> same;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	// int minHour = 99999999;
	// int maxHour = -1;
	int minEndTime = 99999999;
	int maxStartTime = -1;
	for(int i = 0; i < n; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		// for(int j = p.first; j < p.second; ++j)
		// 	exist[j] = true;
		// if(p.first == p.second) same.push_back(p.first);
		// v.push_back(p);
		// minHour = min(minHour, p.first);
		// maxHour = max(maxHour, p.second);
		minEndTime = min(minEndTime, p.second);
		maxStartTime = max(maxStartTime, p.first);
	}
	int res = maxStartTime - minEndTime;
	cout << (res < 0 ? 0 : res) << endl;

}