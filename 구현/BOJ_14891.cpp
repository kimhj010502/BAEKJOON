#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int SIZE = 8;
typedef pair<int, int> ii;

vector<vector<int>> gear(5, vector<int>(SIZE)); //gear[i]: i번 톱니바퀴의 상태
vector<int> dir(5, 0); //dir[i]: i번 톱니바퀴에서 12시 방향의 톱니바퀴 인덱스

//n1번 톱니바퀴의 3시방향 톱니와 n2번 톱니바퀴의 9시 방향 톱니가 다른지 여부 반환
bool isDifferent(int n1, int n2) {
	if (gear[n1][(dir[n1] + 2) % SIZE] == gear[n2][(dir[n2] + 6) % SIZE]) {
		return false;
	}
	return true;
}

//검사해야 할 바퀴들을 q에 추가함
void pushQueue(int origin, int n, queue<ii>& q) {
	if (n == origin) {
		return;
	}

	if (n == 1) {
		q.push({ 1, 2 });
		return;
	}

	if (n == 4) {
		q.push({ 3, 4 });
		return;
	}

	q.push({ n - 1, n });
	q.push({ n, n + 1 });
	return;
}

//n번 톱니바퀴를 d 방향으로 회전
void moveGear(int n, int d) {
	vector<int> is_move(5, 0); //is_move[i]: i번 톱니바퀴가 회전했는지의 여부
	is_move[n] = d;

	queue<ii> q;
	pushQueue(0, n, q);

	while (!q.empty()) {
		int n1 = q.front().first;
		int n2 = q.front().second;
		q.pop();

		//이미 돌린 톱니인 경우 넘어감
		if (is_move[n1] && is_move[n2]) {
			continue;
		}

		//톱니가 다르다면 회전
		if (isDifferent(n1, n2)) {
			is_move[n1] = true;
			is_move[n2] = true;

			pushQueue(n, n1, q);
			pushQueue(n, n2, q);
		}
	}

	//모든 톱니바퀴에 대해 회전했는지 검사
	for (int i = 1; i <= 4; i++) {
		//회전한 경우 인덱스 변경
		if (is_move[i]) {
			dir[i] += (-d) * pow(-1, abs(n - i));
			dir[i] = (dir[i] + SIZE) % SIZE;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, n, d;
	string s;

	//바퀴 상태 입력
	for (int i = 1; i <= 4; i++) {
		cin >> s;

		for (int j = 0; j < SIZE; j++) {
			gear[i][j] = s[j] - '0';
		}
	}

	cin >> k;
	while (k--) {
		//입력
		cin >> n >> d;

		//연산
		moveGear(n, d);
	}

	//점수 계산
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][dir[i]] == 1) {
			ans += pow(2, i - 1);
		}
	}

	//출력
	cout << ans;

	return 0;
}