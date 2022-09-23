full = (1 << MAXBIT)-1;   //? 모든비트 켜기
bits |= (1 << x); 		  //? x번째 비트 켜기
if(bits & (1<<x)); 		  //? x번째 비트 존재 확인
bits &= ~(1<<x);		  //? x번째 비트 제거
bits &= (bits-1);		  //? 최소비트 제거
bits ^= (1<<x);			  //? x번째 비트 토글
minbit = (bits & -bits);  //? 최소비트 추출
for(int subset bits; subset; subset = ((subset-1 & bits)));
//? 부분집합 순회
int bitCount(bits)
{
	int cnt = 0;
	while(bits)
	{
		if((bits & 1) == 1) cnt++;
		bits >>= 1;
	}
	return cnt;
}
//! 1<<0 == 1임 비트도 idx는 0부터