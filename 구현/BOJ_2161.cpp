#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> cardOne(int n) {
	vector<int> result; //버린 카드 순서대로 저장

	deque<int> dq; //카드를 저장할 덱
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int card = 0;
	while (true) {
		//제일 위에 있는 카드를 바닥에 버림
		card = dq.front();
		result.push_back(card);
		dq.pop_front();

		//카드가 없으면 종료
		if (dq.empty()) {
			break;
		}

		//제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮김
		card = dq.front();
		dq.pop_front();
		dq.push_back(card);

		//카드가 한 장 남았는지 확인
		if (dq.empty()) {
			break;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산
	vector<int> result = cardOne(n);

	//출력
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}