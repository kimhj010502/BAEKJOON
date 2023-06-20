#include <iostream>
#include <stack>

using namespace std;

//입력 괄호 문자열이 올바른지 여부 반환
bool isCorrect(string ps) {
	stack<char> s;

	for (int i = 0; i < ps.size(); i++) {
		//열린 괄호인 경우 스택에 넣기
		if (ps[i] == '(') {
			s.push(ps[i]);
			continue;
		}

		//닫힌 괄호인 경우
		//스택의 top이 열린 괄호일 경우에는 짝이 맞으므로 한 쌍의 괄호 없애기
		if (!s.empty() && s.top() == '(') {
			s.pop();
		}

		//스택의 top이 열린 괄호가 아닌 경우에는 짝이 맞지 않으므로 false 반환
		else {
			return false;
		}
	}

	//모든 괄호에 대한 연산을 다 하고 남는 괄호가 없는 경우 1 반환
	if (s.empty()) {
		return true;
	}
	//남는 괄호가 있는 경우 0 반환
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	string ps;
	cin >> t;

	while (t--) {
		//입력
		cin >> ps;

		//연산 & 출력
		if (isCorrect(ps)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}