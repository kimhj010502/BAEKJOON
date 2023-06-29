#include <iostream>
#include <stack>

using namespace std;

//비밀번호 구하는 함수
stack<char> getPassword(string s) {
	char c;
	stack<char> stack1;
	stack<char> stack2;

	for (int i = 0; i < s.size(); i++) {
		//왼쪽으로 커서 이동
		if (s[i] == '<') {
			if (stack1.empty()) {
				continue;
			}
			c = stack1.top();
			stack1.pop();
			stack2.push(c);
		}
		//오른쪽으로 커서 이동
		else if (s[i] == '>') {
			if (stack2.empty()) {
				continue;
			}
			c = stack2.top();
			stack2.pop();
			stack1.push(c);
		}
		//백스페이스
		else if (s[i] == '-') {
			if (stack1.empty()) {
				continue;
			}
			stack1.pop();
		}
		//문자인 경우
		else {
			stack1.push(s[i]);
		}
	}

	//스택1에 남아있는 문자 스택2로 옮기기
	while (!stack1.empty()) {
		c = stack1.top();
		stack1.pop();
		stack2.push(c);
	}
	return stack2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	string s;
	cin >> t;

	while (t--) {
		//입력
		cin >> s;

		//연산
		stack<char> password = getPassword(s);

		//출력
		while (!password.empty()) {
			cout << password.top();
			password.pop();
		}
		cout << "\n";
	}

	return 0;
}