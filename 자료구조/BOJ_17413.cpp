#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string word;
	getline(cin, word);

	stack<char> s;
	queue<char> q;
	bool check = false; //괄호 여부

	//연산 & 출력
	for (int i = 0; i < word.size(); i++) {
		//괄호가 시작하는 경우
		if (word[i] == '<') {
			//스택에 있는 문자 뒤집어서 출력
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}

			q.push(word[i]);
			check = true;
		}
		//괄호인 경우
		else if (check && word[i] != '>') {
			q.push(word[i]);
		}
		//괄호가 끝나는 경우
		else if (check && word[i] == '>'){
			q.push('>');

			//큐에 있는 문자 순서대로 출력
			while (!q.empty()) {
				cout << q.front();
				q.pop();
			}

			check = false;
		}

		//괄호가 아니고 공백이 아닌 경우
		else if (!check && word[i] != ' ') {
			s.push(word[i]);
		}
		//괄호가 아닌데 공백을 만난 경우
		else if (!check && word[i] == ' ') {
			//스택에 있는 문자 뒤집어서 출력
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
	}

	if (check) {
		//큐에 남아있는 문자 순서대로 출력
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
	}
	else {
		//스택에 남아있는 문자 뒤집어서 출력
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	}

	return 0;
}