#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int arr[1001];
int upper[1001];
int lower[1001];
int n; 
int funcLo(int idx);

int funcUp(int idx)
{
	int &ret = upper[idx + 1];
    if (ret != -1) return ret;

    ret = 1;
	
    for (int next = idx + 1; next < n; next++)
        if (idx == -1 || arr[idx] < arr[next])
		{
            ret = std::max(ret, 
			std::max(funcUp(next), funcLo(next)) + 1);
		}
	return ret;
}

int funcLo(int idx)
{
	int &ret = lower[idx + 1];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = idx + 1; next < n; next++)
        if (idx == -1 || arr[idx] > arr[next])
            ret = std::max(ret, 1 + funcLo(next));
    return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	std::fill(upper, upper+1001, -1);
	std::fill(lower, lower+1001, -1);
	
	int res = std::max(funcUp(-1), funcLo(-1));
	
	cout << res-1 << '\n';
	// for(int i = 0; i <= n; ++i)
	// 	cout << upper[i] << ' ';
	// cout << '\n';
	// for(int i = 0; i <= n; ++i)
	// 	cout << lower[i] << ' ';
	// cout << '\n';
}