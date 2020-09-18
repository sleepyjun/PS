#include <iostream>
#include <algorithm>
using namespace std;

int arr[5001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(arr,arr+5001,-1);
	int n;
	cin>>n;
	
	arr[5] = arr[3] = 1;
	
	for(int i=6; i<=n; ++i)
	{
		if(arr[i-3] != -1)
			arr[i] = arr[i-3]+1;
		if(arr[i-5] != -1)
			arr[i] = arr[i-5]+1;
	}
	cout << arr[n] << '\n';
}