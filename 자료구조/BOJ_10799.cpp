#include <iostream>
#include <stack>

using namespace std;

//잘려진 조각의 총 개수 반환
int countBar(string bar) {
	int cnt = 0;
	stack<char> s;

	for (int i = 0; i < bar.size(); i++) {
		//여는 괄호인 경우 스택에 저장
		if (bar[i] == '(') {
			s.push('(');
			continue;
		}

		//닫는 괄호인 경우 레이저인지, 쇠막대기의 끝인지 확인
		//직전 괄호가 여는 괄호였던 경우 레이저이므로 막대기 자름
		if (bar[i - 1] == '(') {
			s.pop();
			cnt += s.size();
		}
		//쇠막대기의 끝인 경우 해당 쇠막대기의 남은 조각 1만큼 더해줌
		else {
			s.pop();
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string bar;
	cin >> bar;

	//연산 & 출력
	cout << countBar(bar);

	return 0;
}