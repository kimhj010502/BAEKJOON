#include <iostream>
#include <stack>
#include <string>

using namespace std;

//괄호열의 값 반환
int getNum(string bracket) {
	stack<string> s;
	int num, tmp;

	for (int i = 0; i < bracket.size(); i++) {
		char c = bracket[i];
		bool check = true; //숫자를 넣었는지 확인

		//여는 괄호인 경우 스택에 삽입
		if (c == '(') {
			s.push("(");

			check = false;
		}
		else if (c == '[') {
			s.push("[");
			check = false;
		}

		//닫는 소괄호인 경우
		else if (c == ')') {
			//s.top()이 여는 대괄호인 경우 입력이 올바르지 못하므로 0 반환
			if (s.empty() || s.top() == "[") {
				return 0;
			}

			//()인 경우 2 삽입
			if (s.top() == "(") {
				s.pop();
				s.push("2");
			}

			//(x)인 경우 2*x 삽입
			else if (isdigit(s.top()[0])) {
				num = stoi(s.top());
				s.pop();

				//그 전 top이 여는 소괄호가 아닌 경우 입력이 올바르지 못하므로 0 반환
				if (s.empty() || s.top() != "(") {
					return 0;
				}

				s.pop(); //( 제거
				s.push(to_string(2 * num));
			}
		}

		//닫는 대괄호인 경우
		else if (c == ']') {
			//s.top()이 여는 소괄호인 경우 입력이 올바르지 못하므로 0 반환
			if (s.empty() || s.top() == "(") {
				return 0;
			}

			//[]인 경우 3 삽입
			if (s.top() == "[") {
				s.pop();
				s.push("3");
			}

			//[x]인 경우 3*x 삽입
			else if (isdigit(s.top()[0])) {
				num = stoi(s.top());
				s.pop();

				//그 전 top이 여는 대괄호가 아닌 경우 입력이 올바르지 못하므로 0 반환
				if (s.empty() || s.top() != "[") {
					return 0;
				}

				s.pop(); //[ 제거
				s.push(to_string(3 * num));
			}
		}

		//숫자를 넣은 경우 이전 값도 숫자인지 확인
		if (check) {
			num = stoi(s.top());
			s.pop();

			//이전 값도 숫자인 경우 더하기 연산
			if (!s.empty() && isdigit(s.top()[0])) {
				tmp = stoi(s.top());
				s.pop();
				s.push(to_string(num + tmp));
			}
			//이전 값이 숫자가 아닌 경우 다시 숫자 넣어두기
			else {
				s.push(to_string(num));
			}
		}
	}

	//모든 연산을 끝내고 스택에 남은 값이 숫자이고 한 개인 경우 해당 숫자 반환
	if (!s.empty() && s.size() == 1 && isdigit(s.top()[0])) {
		return stoi(s.top());
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string bracket;
	cin >> bracket;

	//연산 & 출력
	cout << getNum(bracket);

	return 0;
}