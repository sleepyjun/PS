#include <stdio.h>
int main() {
	int num; // 입력받은 숫자, 고정되는 숫자
	int newNum; // 새롭게 만들어질 숫자, 변동이 있는 숫자
	int secondNum; // 뒤에 붙을 숫자
	int cycle = 1; // 반복 횟수
	scanf_s("%d", &num); // num에 입력

	newNum = num; // newNum은 계속 바뀌는 숫자로 고정된 num 값을 받아 변형시키기 위함

	while (1) { // 반복
		secondNum = (newNum / 10 + newNum % 10) % 10; // 각 자리의 숫자를 더한 후 10으로 나눴을 때 나머지가 2번째 숫자
		newNum = (newNum % 10) * 10 + secondNum; // 새로운 숫자는 이전의 숫자의 두 번째 숫자와 방금 구한 두번째 숫자를 붙인 수

		if (num == newNum) { // 만약 새로운 수와 고정된 입력받은 수가 같다면?
			printf("%d\n", cycle); // 반복의 횟수를 출력하고
			break; // 반복을 멈춘다.
		}
		cycle++; // 그렇지 않을 경우 반복을 1 더한다.
	}
	return 0; // 반복에서 나왔을 경우 정상 종료
}