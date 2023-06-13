#include <iostream>
#include <vector>

using namespace std;

//남학생: 자기가 받은 수의 배수 스위치 바꾸기
void changeM(int n, int num, vector<int>& state) {
	for (int i = num; i <= n; i += num) {
		state[i] = 1 - state[i];
	}
}

//여학생: 자기가 받은 번호 스위치를 중심으로 대칭인 스위치 최대로 바꾸기
void changeF(int n, int num, vector<int>& state) {
	state[num] = 1 - state[num];

	for (int i = 1; i <= n; i++) {
		//탐색 범위가 스위치 번호 범위를 벗어나면 안됨
		if ((num - i < 1) || (num + i > n)) {
			break;
		}

		if (state[num - i] == state[num + i]) {
			state[num - i] = 1 - state[num - i];
			state[num + i] = 1 - state[num + i];
		}
		else {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, sex, num;
	cin >> n;

	vector<int> state(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> state[i];
	}

	cin >> m;
	while (m--) {
		cin >> sex >> num;

		//연산
		//남학생인 경우
		if (sex == 1) {
			changeM(n, num, state);
		}
		//여학생인 경우
		else {
			changeF(n, num, state);
		}
	}

	//출력
	for (int i = 1; i <= n; i++) {
		cout << state[i] << " ";

		//한 줄에 20개씩 출력
		if (i % 20 == 0) {
			cout << "\n";
		}
	}

	return 0;
}