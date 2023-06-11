#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> map; //지도
vector<int> dir; //명령
vector<vector<int>> dice(4, vector<int>(3, 0)); //주사위 전개도 (dice[1][1]: 윗면, dice[3][1]: 바닥면)

//index 1부터 동, 서, 북, 남
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

//주사위 굴리기 (전개도 상에서 숫자 이동)
void rollDice(int d) {
	int tmp;
	switch (d) {
	case 1: //동
		//dice의 1행 값들을 오른쪽으로 한 칸씩 이동시킴
		tmp = dice[1][2];
		for (int i = 2; i > 0; i--) {
			dice[1][i] = dice[1][i - 1];
		}
		dice[1][0] = dice[3][1];
		dice[3][1] = tmp;
		break;

	case 2: //서
		//dice의 1행 값들을 왼쪽으로 한 칸씩 이동시킴
		tmp = dice[1][0];
		for (int i = 0; i < 2; i++) {
			dice[1][i] = dice[1][i + 1];
		}
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
		break;

	case 3: //북
		//dice의 1열 값들을 위쪽으로 한 칸씩 이동시킴
		tmp = dice[0][1];
		for (int i = 0; i < 3; i++) {
			dice[i][1] = dice[i + 1][1];
		}
		dice[3][1] = tmp;
		break;

	case 4: //남
		//dice의 1열 값들을 아래쪽으로 한 칸씩 이동시킴
		tmp = dice[3][1];
		for (int i = 3; i > 0; i--) {
			dice[i][1] = dice[i - 1][1];
		}
		dice[0][1] = tmp;
		break;
	}
}

//주사위 이동하고 윗 면에 쓰여 있는 수 출력하는 함수
void moveAndPrint() {
	//k번의 명령 실행
	for (int i = 0; i < k; i++) {
		int d = dir[i]; //다음 이동 방향
		int nx = x + dx[d];
		int ny = y + dy[d];

		//바깥으로 이동시키려고 하는 경우 해당 명령 무시
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		//다음 칸으로 이동
		x = nx; y = ny;

		rollDice(d); //주사위 굴려서 (x, y)에 위치시키기

		//이동한 칸에 쓰여있는 수가 0인 경우: 주사위의 바닥면에 쓰여 있는 수 복사
		if (!map[x][y]) {
			map[x][y] = dice[3][1];
		}
		//이동한 칸에 쓰여있는 수가 0이 아닌 경우: 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되고 칸에 쓰여 있는 수는 0이 됨
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}

		//주사위 윗면에 쓰여 있는 값 출력
		cout << dice[1][1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m >> x >> y >> k;

	map.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dir.assign(k, 0);
	for (int i = 0; i < k; i++) {
		cin >> dir[i];
	}

	//연산 & 출력
	moveAndPrint();

	return 0;
}