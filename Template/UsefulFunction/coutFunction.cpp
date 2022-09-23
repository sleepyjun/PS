#include <iostream>

using namespace std;

int main()
{
	// stdio.h있는 출력 함수들과 손절하고 cout만 써서 성능 올리기
	// ∴ endl, printf, scanf 등등 이런거 쓰면 안돼
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//eof가 들어오면 true
	cin.eof();
	

	//소수점 6자리까지 출력
	cout << fixed;
	cout.precision(6);
}