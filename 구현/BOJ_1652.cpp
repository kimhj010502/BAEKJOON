#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

//누울 수 있는 자리의 개수 반환
ii cntSeat(int n, vector<vector<int>>& room) {
	//방이 1 X 1 크기인 경우 누울 수 없음
	if (n == 1) {
		return { 0,0 };
	}

	ii cnt = { 0,0 }; //{ 가로로 누울 수 있는 자리의 개수, 세로로 누울 수 있는 자리의 개수 }
	vector<vector<int>> cnt_room;
	
	//가로 방향으로 탐색
	cnt_room.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		if (room[i][0] == '.' && room[i][1] == '.') {
			cnt_room[i][0] = ++cnt.first;
		}

		for (int j = 1; j < n - 1; j++) {
			//짐이 있는 칸은 넘어감
			if (room[i][j] == 'X') {
				continue;
			}

			//이전 칸에 짐이 있고 다음 칸에 없는 경우
			if (room[i][j - 1] == 'X' && room[i][j + 1] == '.') {
				cnt_room[i][j] = ++cnt.first;
			}
			//이전 칸에 짐이 없는 경우
			else {
				cnt_room[i][j] = cnt_room[i][j - 1];
			}
		}
	}

	cnt_room.assign(n, vector<int>(n, 0));
	//세로 방향으로 탐색
	for (int i = 0; i < n; i++) {
		if (room[0][i] == '.' && room[1][i] == '.') {
			cnt_room[0][i] = ++cnt.second;
		}

		for (int j = 1; j < n - 1; j++) {
			//짐이 있는 칸은 넘어감
			if (room[j][i] == 'X') {
				continue;
			}

			//이전 칸에 짐이 있고 다음 칸에 없는 경우
			if (room[j - 1][i] == 'X' && room[j + 1][i] == '.') {
				cnt_room[j][i] = ++cnt.second;
			}
			//이전 칸에 짐이 없는 경우
			else {
				cnt_room[j][i] = cnt_room[j - 1][i];
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	string s;
	cin >> n;

	vector<vector<int>> room(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			room[i][j] = s[j];
		}
	}

	//연산
	ii cnt = cntSeat(n, room);

	//출력
	cout << cnt.first << " " << cnt.second;

	return 0; 
}