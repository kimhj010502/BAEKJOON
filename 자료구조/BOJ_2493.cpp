#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> ii;

const int MAX = 1e9;

//레이저 신호를 수신한 탑들의 번호 반환
vector<int> receptSignal(int n, vector<int>& tower) {
	vector<int> signal(n + 1, 0); //signal[i]: i번째 탑이 발사한 레이저를 수신하는 탑의 번호

	stack<ii> s; //{탑의 번호, 높이}
	s.push({ n,tower[n] }); //마지막 탑 넣기

	for (int i = n - 1; i > 0; i--) {
		//이전 탑의 높이가 더 큰 경우 해당 탑이 신호 받음
		while (!s.empty() && tower[i] > s.top().second) {
			signal[s.top().first] = i;
			s.pop();
		}

		//신호 보낼 탑 넣기
		s.push({ i, tower[i] });
	}
	return signal;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> tower(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> tower[i];
	}

	//연산
	vector<int> signal = receptSignal(n, tower);

	//출력
	for (int i = 1; i <= n; i++) {
		cout << signal[i] << " ";
	}

	return 0;
}