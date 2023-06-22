#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

//폭발 후에 남아있는 문자 반환
deque<char> afterExplosion(string word, string explosion) {
	deque<char> dq;
	stack<char> s;

	int n = explosion.size();
	int cnt = 0;

	for (int i = 0; i < word.size(); i++) {
		dq.push_back(word[i]);
		cnt++;

		//지금까지 덱에 넣은 문자의 수가 폭발문자열의 글자수보다 작은 경우 비교할 필요가 없음
		if (cnt < n) {
			continue;
		}

		//덱의 마지막 글자가 폭발 문자열의 마지막 글자가 아닌 경우 넘어감
		if (dq.back() != explosion[n - 1]) {
			continue;
		}
		
		//스택 초기화
		while (!s.empty()) {
			s.pop();
		}

		//덱의 마지막 글자가 폭발 문자열의 마지막 글자인 경우 확인
		for (int j = n - 1; j >= 0; j--) {
			char c = dq.back();

			//폭발 문자열이 맞는 경우 제거
			if (c == explosion[j]) {
				s.push(c);
				dq.pop_back();
				cnt--;
			}

			//폭발 문자열이 아닌 경우 다시 s에 넣기
			else {
				while (!s.empty()) {
					dq.push_back(s.top());
					cnt++;
					s.pop();
				}
				break;
			}
		}
	}
	return dq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string word, explosion;
	cin >> word >> explosion;

	//연산
	deque<char> dq = afterExplosion(word, explosion);

	//출력
	//폭발 후에 남아있는 문자가 없는 경우
	if (dq.empty()) {
		cout << "FRULA";
	}
	//폭발 후에 남아있는 문자가 있는 경우
	else {
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
	}

	return 0;
}