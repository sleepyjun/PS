#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x,y,w,h;
	int arr[4];
	cin >> x >> y >> w >> h;
	arr[0] = x;
	arr[1] = y;
	arr[2] = w-x;
	arr[3] = h-y;
	sort(arr,arr+4);
	cout << arr[0] << '\n';
}