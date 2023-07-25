#include <iostream>

using namespace std;

const int CHAR = 64;

//문자열을 압축하여 반환
string solution(string input) {
	string result = "";

	//1로 시작하는 경우 앞에 1 붙이기
	if (input[0] == '1') {
		result += "1";
	}

	int cnt = 1;
	for (int i = 1; i < input.size(); i++) {
		//숫자가 바뀌었으면 다시 리셋
		if (input[i] != input[i - 1]) {
			result += (char)(cnt + CHAR);
			cnt = 1;
		}
		//숫자가 바뀌지 않았으면 cnt 증가
		else {
			cnt++;
		}
	}

	//마지막 문자가 남은 경우
	if (cnt > 0) {
		result += (char)(cnt + CHAR);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string input;
	cin >> input;

	//연산 & 출력
	cout << solution(input);

	return 0;
}