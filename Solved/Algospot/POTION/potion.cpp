#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int cnts[201];
int currs[201];
int res[201];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int ceil(int a, int b)
{
	return (a+b-1) /b ;
}

void solve(int n)
{
	int b = cnts[1];
	for(int i = 2; i <= n; ++i) b = gcd(b, cnts[i]);
	//공통 최대공약수 구함
	int a = b;
	for(int i = 1; i <= n; ++i)
		a = std::max(a, ceil(currs[i] * b, cnts[i]));
	for(int i = 1; i <= n; ++i)
		res[i] = cnts[i] * a / b - currs[i];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	
	while(t--)
	{
		std::fill(cnts, cnts+201, 0);
		std::fill(currs, currs+201, 0);
		std::fill(res, res+201, 0);
		int n; cin >> n;
		for(int i = 1; i <= n; ++i) cin >> cnts[i];
		for(int i = 1; i <= n; ++i) cin >> currs[i];
		solve(n);
		for(int i = 1; i <= n; ++i) cout << res[i] << ' ';
		cout << '\n';
	}
}

/*
#include <cstdio>

#include <cmath>



using namespace std;



//GCD계산 (유클리드)

int calcGcd(int n1, int n2)

{

	int temp;

	if (n1 < n2) {

		temp = n1;

		n1 = n2;

		n2 = temp;

	}

	while (n2 != 0) {

		temp = n1%n2;

		n1 = n2;

		n2 = temp;

	}



	return n1;

	

}





int main(void)

{



	int numTry;

	scanf("%d",&numTry);



	while (numTry--)

	{

		int numElem;

		scanf("%d",&numElem);



		int *ideal = new int[numElem];

		int *curr = new int[numElem];

		int gcd;

		double curMul = 0;

		double maxMul = 0;

		int mul;

		

		//비율값 입력받음

		for (int i = 0; i < numElem; i++) 

			scanf("%d", &ideal[i]);





		//비율값의 gcd계산

		gcd = ideal[0];

		for (int i = 1; i < numElem; i++) 

			gcd = calcGcd(gcd, ideal[i]);





		//ideal값 재계산

		for (int i = 0; i < numElem; i++)

			ideal[i] = ideal[i]/gcd;



		//현재넣은값 입력받음

		for (int i = 0; i < numElem; i++) {

			scanf("%d", &curr[i]);

			curMul = (double)curr[i] / ideal[i];

			if (curMul >maxMul ) maxMul = curMul;

		}

	

		mul = ceil(maxMul);

		for (int i = 0; i < numElem; i++) {

			ideal[i] *= mul;

			printf("%d ", ideal[i] - curr[i]); 

		}

		printf("\n");



	}

	return 0;

}



출처: https://tibyte.kr/229 [티바이트]
*/