// https://www.acmicpc.net/problem/13334
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool cmp(const pii &a, const pii &b)
{
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    std::vector<pii> arr;
    for(int i = 0; i < n; ++i)
    {
        int a,b; cin >> a >> b;
        if(a > b) std::swap(a,b);
        arr.push_back({a,b});
    }
    int d; cin >> d;

	std::sort(arr.begin(), arr.end(), cmp);
	int max = 0;
	
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
	for (int i = 0; i < arr.size(); ++i)
	{
		int e = arr[i].second;
		if (e - d <= arr[i].first && arr[i].second <= e)
			pq.push(arr[i]);
		else continue;
			
		while (!pq.empty()){
			if (e - d > pq.top().first || pq.top().second > e)
				pq.pop();
			else
				break;
		}
		max = std::max(max, (int)pq.size());
	}
	cout << max;

	cout << '\n';
}//g++ -o a -std=c++11 *.cpp