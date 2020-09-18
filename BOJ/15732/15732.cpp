#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 987654321;

int arr[10001][3];
int n,k,d; 
bool possible(const int box)
{
    long long cnt = 0;
    for(int i = 0; i < k; ++i)
    {
        int high = std::min(box, arr[i][1]);
        if(high >= arr[i][0])
		{
			int diff = high-arr[i][0];
			cnt += (diff/arr[i][2])+1;
		}
    }
    return cnt >= d;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> d;
    for(int i = 0; i < k; ++i)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    int low = 0, high = n;
    int res;
    while(low <= high)
    {
        int mid = (high+low)/2;
        if(possible(mid))
        {
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    
    cout << res << '\n';
}