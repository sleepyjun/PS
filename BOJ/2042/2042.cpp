#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef long long ll;
const int INF = 987654321;

std::vector<ll> arr, tree;
ll init(int start, int end, int node)
{
    if(start == end)
        return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2) +
                    init(mid+1,end,node*2+1);
}
void update(int start, int end, int node, int idx, ll diff)
{
    if(!(start <= idx && idx <= end)) return;
    tree[node] += diff;
    if(start != end)
    {
        int mid = (start+end)/2;
        update(start,mid,node*2,idx,diff);
        update(mid+1,end,node*2+1,idx,diff);
    }
    else
    {
        
    }
}
ll sum(int start, int end, int left, int right, int node)
{
    if(left > end || right < start)  return 0;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start+end)/2;
    return sum(start,mid,left,right,node*2) +
        sum(mid+1,end,left,right,node*2+1);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m,k; cin >> n >> m >> k;
    int t = m+k;
    arr.resize(n+1); tree.resize(n*4);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    init(1,n,1);
    while(t--)
    {
        int a; cin >> a;
        if(a == 1)
        {
            int b;
            ll c;
            cin >> b >> c;
            update(1,n,1,b,c-arr[b]);
            arr[b] = c;
        }
        else if(a == 2)
        {
            int b,c;
            cin >> b >> c;
            cout << sum(1,n,b,c,1) << '\n';
        }
    }
}