#include <iostream>
#include <vector>

using namespace std;

const int ALPHA = 26;
const int START = 65;

char getMaxChar(string word) {
	int max_cnt = 0; //최대 알파벳 사용횟수
	vector<int> alphabet(ALPHA, 0);

	for (int i = 0; i < word.size(); i++) {
		if (islower(word[i])) {
			word[i] = toupper(word[i]);
		}
		
		int index = word[i] - START;
		alphabet[index]++;
		max_cnt = max(max_cnt, alphabet[index]);
	}

	char answer; //가장 많이 사용된 알파벳 (대문자)
	int cnt = 0; //알파벳 사용 횟수가 최대인 알파벳의 개수
	for (int i = 0; i < ALPHA; i++) {
		if (alphabet[i] == max_cnt) {
			cnt++;
			answer = (char)(i + START);
		}
	}

	//가장 많이 사용된 알파벳이 1개인 경우
	if (cnt == 1) {
		return answer;
	}
	//가장 많이 사용된 알파벳이 여러개인 경우
	return '?';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string word;
	cin >> word;

	//연산 & 출력
	cout << getMaxChar(word);

	return 0;
}