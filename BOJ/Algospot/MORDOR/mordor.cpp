#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[100001];
int init(std::vector<int>& v, int start, int end, int node)
{
	if(start == end)
		return v[node] = arr[start];
	int mid = (start+end)/2;
	int left = init(v, start, mid, node*2);
	int right = init(v, mid+1, end, node*2+1);
	
	return v[node] = std::min(left, right);
}
int query(const std::vector<int>& v, int left, int right,
		 int start, int end, int node)
{
	if(left > end || right < start)
		return INF;
	if(left <= start && end <= right)
		return v[node];
	int mid = (start+end)/2;
	return std::min(query(v,left,right,start,mid,node*2),
				   query(v,left,right,mid+1,end,node*2+1));
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,q; cin >> n >> q;
		std::vector<int> mins(4*n);
		std::vector<int> maxs(4*n);
		std::fill(arr,arr+n,0);
		for(int i = 0; i < n; ++i)
			cin >> arr[i];
		init(mins, 0, n-1, 1);
		for(int i = 0; i < n; ++i)
			arr[i] = -arr[i];
		init(maxs, 0, n-1, 1);
		for(int i = 0; i < q; ++i)
		{
			int a,b; cin >> a >> b;
			int min = query(mins, a, b, 0, n-1, 1);
			int max = query(maxs, a, b, 0, n-1, 1);
			
			cout << -(min + max) << '\n';
		}
	}
}